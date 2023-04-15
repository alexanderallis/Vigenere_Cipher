#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include "lib/read_file.h"
#include "lib/Index_of_Coincidence.h"
#include "lib/CipherLib.h"
#include "lib/Vigenere_Lib.h"

int main() {

    // TESTING ENCRYPTION / DECRYPTION - TALE OF TWO CITIES
//    std::string filePath_ = "./Ciphertext/Large_Ciphertext";
//    std::string * cipherMessage = fileToString(filePath_);
//    std::vector<char> * plaintext_ = convert_message_to_vector_char(cipherMessage);
//    std::vector<int> key_ = {3, 7, 21, 16};
//    std::vector<char> * ciphertext = encrypt(*plaintext_, key_);

    // TEST ENCRYPTION DECRYPTION WITH 'QUICK BROWN FOX'
//    std::string plaintext = "THEQUICKBROWNFOXJUMPEDOVERTHELAZYDOG";
//    std::vector<int> key_ = {3, 7, 21, 16};
//    std::vector<char> * plaintext_ = convert_message_to_vector_char(&plaintext);
//    std::vector<char> * ciphertext = encrypt(*plaintext_, key_);
//    decode(&ciphertext_, key_);
    // END TEST

    // 0. Read real ciphertext
    std::string filePath = "./Ciphertext/grad-vigenere-cipher";
    std::string * cipherMessage = fileToString(filePath);
    std::vector<char> * ciphertext = convert_message_to_vector_char(cipherMessage);

    // Find keyword length, m
    // 1. Construct indices of coincidence for different values of m
    int m = 20;
    auto *ioCoincidenceVector = new std::vector<std::vector<std::vector<char>>*>();
    for(int i = 1; i <= m; i++) {
        ioCoincidenceVector->push_back(constructIndexOfCoincidence(i, ciphertext));
    }

    // 2. Calculate the probability of choosing two identical characters for each value of m
    // This is called the index of confidence.
    auto *ioConfidenceVector = new std::vector<std::vector<float>>(0, std::vector<float>(0.0));
    for(auto & i : *ioCoincidenceVector) {
        ioConfidenceVector->push_back(calculateIndexOfConfidence(i));
    }

    // 3. Tabulate results by finding the average index of confidence for each value of m.
    float ioConfSum = 0.0;
    float ioConfAvg = 0.0;
    auto ioConfidenceList = std::vector<std::pair<int, float>>();

    for(int i = 0; i < ioConfidenceVector->size(); i++) {
        // a. Calculate the average index of confidence value for each value of m.
        // b. Add the distance from 0.065 to a list.
        for(float j : ioConfidenceVector->at(i)) {
            ioConfSum += j;
        }
        ioConfAvg = ioConfSum / (float) ioConfidenceVector->at(i).size();
//        ioConfidenceList.emplace_back(i, abs((float) 0.065 - ioConfAvg));
        ioConfidenceList.emplace_back(i, ioConfAvg);  // Find the largest index of confidence, not closest to 0.065
        ioConfSum = 0.0;  // reset value
    }
    // c. Sort list by the second element, the float value.
    // The third argument is overloads a method for the sort criteria.
    std::sort(ioConfidenceList.begin(), ioConfidenceList.end(), sortPairsHighToLow);

    // Print results
    for(auto & i : ioConfidenceList) {
        std::cout << "M:" << i.first + 1 << " | " << ioConfAvg << " | Delta: " << i.second << std::endl;
    }

    // ----------------
    // Find the keyword
    // ----------------

    // Calculate Optimal Shifts for a value of m. The index of ioCoincidenceVector is the value of m.
    int mValue = 6;
    std::vector<std::vector<std::pair<int, float>>> optimalShiftsForYi = calculateOptimalShifts(ioCoincidenceVector->at(mValue - 1));

    // Get keys
    int depth = 2;
    std::vector<std::vector<int>> keys = getKeys(optimalShiftsForYi, depth);

    // Decode by keys
//    std::vector<int> key;
//    for (int i = 0; i < keys.size(); ++i) {
//        if(i % 10000 == 0)
//            std::cout << i << "/" << keys.size() << std::endl;
//        key = keys.at(i);
//        decode(ciphertext, key);
//    }

    // Decode using most likely key
    decode(ciphertext, keys.at(0));

    return 0;
}
