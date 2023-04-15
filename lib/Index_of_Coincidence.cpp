//
// Created by Alexander Allis on 3/6/23.
//

#include <vector>
#include <iostream>
#include "Index_of_Coincidence.h"
#include "CipherLib.h"

/*
 * Index of Coincidence: A matrix where the rows are each m character from the ciphertext. There are m rows because
 * each row is offset by one character. Each row is called yi.
 */
std::vector<std::vector<char>> * constructIndexOfCoincidence(int m, std::vector<char> * ciphertext) {

    int m_dividend = (int) (ciphertext->size() / m) + 1;
    if(ciphertext->size() % m == 0) {
        m_dividend--;
    }

    auto * indexOfCoincidence = new std::vector<std::vector<char>>();
    for (int i = 0; i < m; i++) {  // loop through offsets from m
        indexOfCoincidence->emplace_back();
        for (int j = 0; (j * m + i) < ciphertext->size(); j++) {  // loop through multiples of m
            indexOfCoincidence->at(i).push_back(ciphertext->at(j * m + i));
        }
    }

    return indexOfCoincidence;
}

/*
 * Indices of confidence is a list of the sum of squares of probabilities of each letter in yi.
 * The sum of all the squared probabilities in english text should be very close to 0.065
 */
std::vector<float> calculateIndexOfConfidence(std::vector<std::vector<char>> * ioc) {

    auto characterFrequency = std::vector<int>(26, 0);
    auto characterProbabilities = std::vector<float>(26, 0);
    auto indicesOfConfidence = std::vector<float>(ioc->size(), 0);

    for(int i = 0; i < ioc->size(); i++) {
        // calculate index of confidence for each Yi of the index
        // 1. Determine frequency
        for(int j = 0; j < ioc->at(i).size(); j++) {
            characterFrequency.at(charToIndex(ioc->at(i).at(j)))++;
        }

        for(int j = 0; j < characterFrequency.size(); j++) {
            // 2. Determine probabilities
            characterProbabilities.at(j) = ((float) characterFrequency.at(j)) / ((float) ioc->at(i).size());
            // 3. Sum squares of probabilities
            // 4. Add to indicesOfConfidence
            indicesOfConfidence.at(i) += characterProbabilities.at(j) * characterProbabilities.at(j);
        }

        // Reset values to zero(0)
        std::fill(characterFrequency.begin(), characterFrequency.end(), 0);
        std::fill(characterProbabilities.begin(), characterProbabilities.end(), 0);
    }

    return indicesOfConfidence;

}