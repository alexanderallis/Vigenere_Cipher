//
// Created by Alexander Allis on 2/23/23.
//

#ifndef HILL_AND_AFFINE_CIPHER_CIPHERLIB_H
#define HILL_AND_AFFINE_CIPHER_CIPHERLIB_H

#endif //HILL_AND_AFFINE_CIPHER_CIPHERLIB_H

std::vector<char> * encrypt(std::vector<char> plaintext, std::vector<int> key);

bool sortPairs(std::pair<int, float> &, std::pair<int, float> &);

bool sortPairsHighToLow(std::pair<int, float> & pair1, std::pair<int, float> & pair2);

char intToChar(int);

int charToIndex(char);

int getModulo(int, int);

int getDeterminant(std::vector<std::vector<int>>, int);

float dotProduct(std::vector<float>, std::vector<float>);

std::vector<float> multiplyMatrices(std::vector<std::vector<float>> &, std::vector<std::vector<float>> &);

int getGcd(int, int);

int findInverseNumber(int, int);

std::vector<std::vector<int>> * findInverseMatrix(std::vector<std::vector<int>> *, int);
