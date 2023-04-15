//
// Created by Alexander Allis on 3/8/23.
//

#include "Vigenere_Lib.h"
#include "CipherLib.h"
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

void decode(std::vector<char> * ciphertext, std::vector<int> key) {

    auto plaintext = std::vector<char>(ciphertext->size());

    for (int i = 0; i < ciphertext->size(); ++i) {
        plaintext.at(i) = intToChar( getModulo((charToIndex(ciphertext->at(i)) - key.at(i % key.size())), 26) );
    }

    // Convert plaintext vector to a string
    auto plaintextString = std::string(plaintext.begin(), plaintext.end());

    int score = 0;

    auto the = std::string("the");
    if(plaintextString.find(std::string("the")) != std::string::npos) {
        score++;
    }

    // Look for common english words

//    std::string theStr("THE");
//    size_t substring_length = plaintextString.find(theStr);
//    if ((substring_length = plaintextString.find(theStr)) != std::string::npos)
//        score++;
//
//    std::string thatStr("THAT");
//    if ((substring_length = plaintextString.find(thatStr)) != std::string::npos)
//        score++;
//
//    std::string haveStr("HAVE");
//    if ((substring_length = plaintextString.find(haveStr)) != std::string::npos)
//        score++;
//
//    std::string withStr("WITH");
//    if ((substring_length = plaintextString.find(withStr)) != std::string::npos)
//        score++;
//
//    std::string thisStr("THIS");
//    if ((substring_length = plaintextString.find(thisStr)) != std::string::npos)
//        score++;
//
//    std::string fromStr("FROM");
//    if ((substring_length = plaintextString.find(fromStr)) != std::string::npos)
//        score++;

    if(score >= 0) {
        // Print
        for(char i : plaintext) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "skip" << std::endl;
    }

}

std::vector<int> increment(std::vector<int> indices, int depth) {
    int size = (int) indices.size();
    bool carry = true;
    for(int i = indices.size() - 1; i >= 0; i--) {
        if(carry){
            indices.at(i) += 1;
            indices.at(i) %= depth;
            if(indices.at(i) == 0) {
                carry = true;
            }
            else{
                carry = false;
            }
        }
    }

    return indices;
}

std::vector<std::vector<int>> getKeys(std::vector<std::vector<std::pair<int, float>>> & optimalShiftsForYi, int depth) {

    auto indices = std::vector<int>(optimalShiftsForYi.size(), 0);
    std::vector<std::vector<int>> keys;
    std::vector<int> key;
    int combinations = pow(depth,optimalShiftsForYi.size());

    for(int i = 0; i < combinations; i++) {
//        if(i % 10000 == 0)
//            std::cout << "Combination: " << i << "/" << combinations << std::endl;

        for(int j = 0; j < optimalShiftsForYi.size(); j++) {
            key.push_back(optimalShiftsForYi.at(j).at(indices.at(j)).first);
        }
        keys.push_back(key);
        key.clear();
        indices = increment(indices, depth);
    }

    return keys;
}

/*
 * Input: Index of Coincidence for a given value of m.
 * Output: A vector of pairs that represent the shift value and (Mg - 0.065)^2 in sorted order.
 */
std::vector<std::vector<std::pair<int, float>>> calculateOptimalShifts(std::vector<std::vector<char>> * ioc) {

    std::vector<std::vector<std::vector<float>>> matricesOfMgPerIOC;
    std::vector<std::vector<std::pair<int, float>>> MgAbsDiffMatrix;
    std::vector<float> MgVectorForIoc;
    std::vector<std::vector<float>> YiPDFs;
    std::vector<std::vector<float>> englishLangPDF = {  // must be a column vector
            {0.082},{0.015},{0.028},{0.043},{0.127},{0.022},{0.020},{0.061},{0.070},{0.002},{0.008},{0.040},{0.024},
            {0.067},{0.075},{0.019},{0.001},{0.060},{0.063},{0.091},{0.028},{0.010},{0.023},{0.001},{0.020},{0.001}
    };

    float MgE = 0;
    for (int i = 0; i < englishLangPDF.size(); ++i) {
        MgE += (englishLangPDF.at(i).at(0) * englishLangPDF.at(i).at(0));
    }

    // 1. For each yi, find the probability distribution of the letters
    YiPDFs = findIocProbabilities(*ioc);

    for(int j = 0; j < 26; j++) {  // For each shift of the english character probabilities...
        // 3. Matrix Multiply the probabilities by the corresponding english letter
        // probabilities to get a vector of Mg values.
        MgVectorForIoc = multiplyMatrices(YiPDFs, englishLangPDF);
        // Find absolute value of the difference between Mg values and 0.065
//        for(int k = 0; k < MgVectorForIoc.size(); k++) {
//            MgVectorForIoc.at(k) -= 0.065;
//            MgVectorForIoc.at(k) = abs(MgVectorForIoc.at(k));  // find absolute value
////            MgVectorForIoc.at(k) *= MgVectorForIoc.at(k);
//        }

        // Create vector of pairs <shift amount, Mg absolute value of difference>
        std::vector<std::pair<int, float>> vectorOfShiftAndSqDiffPairs;
        vectorOfShiftAndSqDiffPairs.resize(MgVectorForIoc.size());
        for(int k = 0; k < MgVectorForIoc.size(); k++) {
            vectorOfShiftAndSqDiffPairs.at(k) = std::pair<int, float>(j, MgVectorForIoc.at(k));
        }
        // Add to matrix of shift amounts
        MgAbsDiffMatrix.resize(ioc->size());
        for(int k = 0; k < ioc->size(); k++) {
            MgAbsDiffMatrix.at(k).push_back(vectorOfShiftAndSqDiffPairs.at(k));
        }
        // shift english letter probabilities
        englishLangPDF = shiftVector(englishLangPDF, 1);
    }
    // Sort matrix of shift amounts
    for(int j = 0; j < MgAbsDiffMatrix.size(); j++) {
        sort(MgAbsDiffMatrix.at(j).begin(), MgAbsDiffMatrix.at(j).end(), sortPairsHighToLow);
    }

    return MgAbsDiffMatrix;
}

std::vector<std::vector<float>> shiftVector(std::vector<std::vector<float>> list, int shiftAmount) {

//    for(int i = 0; i < shiftAmount; i++) {
//        list.push_back(list.at(0));
//        list.erase(list.begin());
//    }

    rotate(list.begin(), list.begin() + list.size() - 1, list.end());

    return list;
}

std::vector<float> sumRows(std::vector<std::vector<float>> & matrix) {
    float sum = 0;
    std::vector<float> sumVector;
    for(auto & i : matrix) {
        for(int j = 0; j < i.size(); j++) {
            sum += i.at(j);
        }
        sumVector.push_back(sum);
        sum = 0;  // reset sum
    }

    return sumVector;
}

std::vector<std::vector<float>> findIocProbabilities(std::vector<std::vector<char>> & ioc) {
    std::vector<int> characterFrequency;
    std::vector<std::vector<float>> matrixOfCharacterProbabilities;
    std::vector<float> characterProbabilities;
    characterFrequency.resize(26, 0);
    characterProbabilities.resize(26, 0);

    for(auto & j : ioc) {  // for each yi in the ioc
        // 1. Determine frequency in yi
        for (char k : j) {
            characterFrequency.at(charToIndex(k))++;
        }

        // 2. Determine probabilities in yi
        for (int k = 0; k < characterFrequency.size(); k++) {
            characterProbabilities.at(k) = ((float) characterFrequency.at(k)) / ((float) j.size());
        }

        // Add yi probabilities to matrix
        matrixOfCharacterProbabilities.push_back(characterProbabilities);

        // Reset values to zero(0)
        std::fill(characterFrequency.begin(), characterFrequency.end(), 0);
        std::fill(characterProbabilities.begin(), characterProbabilities.end(), 0);
    }

    return matrixOfCharacterProbabilities;
}