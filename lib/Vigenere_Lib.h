//
// Created by Alexander Allis on 3/8/23.
//

#include <vector>

#ifndef VIGENERE_CIPHER_VIGENERE_LIB_H
#define VIGENERE_CIPHER_VIGENERE_LIB_H

#endif //VIGENERE_CIPHER_VIGENERE_LIB_H

std::vector<std::vector<float>> findIocProbabilities(std::vector<std::vector<char>> &);

std::vector<float> sumRows(std::vector<std::vector<float>> & matrix);

std::vector<std::vector<float>> shiftVector(std::vector<std::vector<float>>, int);

std::vector<std::vector<std::pair<int, float>>> calculateOptimalShifts(std::vector<std::vector<char>> *);

std::vector<std::vector<int>> getKeys(std::vector<std::vector<std::pair<int, float>>> &, int);

std::vector<int> increment(std::vector<int>, int depth);

void decode(std::vector<char> *, std::vector<int>);
