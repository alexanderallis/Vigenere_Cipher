//
// Created by Alexander Allis on 2/23/23.
//

/*
 * ATTN: MANY OF THE FOLLOWING FUNCTIONS ARE UNTESTED!
 */

#include <vector>
#include <iostream>
#include "CipherLib.h"

std::vector<char> * encrypt(std::vector<char> plaintext, std::vector<int> key) {
    auto * encryption = new std::vector<char>(plaintext.size());
    for(int i = 0; i < plaintext.size(); ++i) {
       encryption->at(i) = (intToChar(getModulo((charToIndex(plaintext.at(i)) + key.at(i % key.size())), 26)));
    }
    return encryption;
}

/*
 * Compares the absolute values of the second element of two pairs.
 */
bool sortPairs(std::pair<int, float> & pair1, std::pair<int, float> & pair2) {
    return pair1.second < pair2.second;
}

bool sortPairsHighToLow(std::pair<int, float> & pair1, std::pair<int, float> & pair2) {
    return pair1.second > pair2.second;
}

char intToChar(int i) {
    return char(i + 65);  // returns captial letters
}

int charToIndex(char c) {
    unsigned charIndex = int(c);
    if(charIndex > 96) charIndex -= 97;  // Condition for lowercase letters
    else charIndex -= 65;  // Condition for uppercase letters
    if(charIndex < 0 || charIndex > 25) {
//        throw std::domain_error("Domain Error: Character out of range");
        std::cout << c << std::endl;
        std::cout << c << "charToIndex out of range" << std::endl;
        return -1;
    }
    else{
        return int(charIndex);
    }
}

int getModulo(int i, int mod) {
    int k = i % mod;
    if(k < 0) k += 26;
    return k;
}

/*
 * Returns the determinant of a matrix modulo 26.
 */
int getDeterminant(std::vector<std::vector<int>> * matrix, int modulus) {
    int determinant = matrix->at(0).at(0) * matrix->at(1).at(1) - matrix->at(0).at(1) * matrix->at(1).at(0);
    return getModulo(determinant, modulus);
}

/*
 * Returns dot product
 * Answers as residuals of the modulus
*/
float dotProduct(std::vector<float> a, std::vector<float> b) {
    // Note: a and b must have the same length
    float c = 0;
    for(int i = 0; i < a.size(); i++) {
        c += a.at(i) * b.at(i);
    }
    return c;
}

/*
 * Returns the product of two matrices A*B
 * Answers as residuals of the modulus
*/
std::vector<float> multiplyMatrices(std::vector<std::vector<float>> & A, std::vector<std::vector<float>> & B) {
    // Rows of matrix a dot product with columns of matrix B
    auto answer = std::vector<float>(A.size());
    std::vector<float> colB;

    for(int i = 0; i < A.size(); i++) {  // for each row of a...
        for(int j = 0; j < B.at(0).size(); j++) {  // ...dot product with each column of B.
            for(int k = 0; k < B.size(); k++) {  // get each column of B
                colB.push_back(B.at(k).at(j));
            }
            answer.at(i) = dotProduct(A.at(i), colB);
            colB.clear();
        }
    }
    return answer;
}

/*
 * Finds the greatest common divisor.
 * Tested for all (x,26); x is in Z-26.
 * Should find mod(x) before using.
 */
int getGcd(int num1, int num2) {
    if(num1 == 0) return num2;
    if(num2 == 0) return num1;
    if(num1 > num2) {
        int temp;
        temp = num1;
        num1 = num2;
        num2 = temp;
    }  // num2 should always be bigger
    int q = 0;
    int r = 1;
    // num2 = q * num1 + r
    while(r >= 1) {
        q = num2 / num1;
        r = num2 % num1;
        if(r == 0) return num1;
//        if(num1 % r == 0) return r;
        num2 = num1;
        num1 = r;
    }
    int answer = num1;
    return answer;
}

/*
 * Returns inverse of a number in Z-26, -1 if inverse does not exist.
 */
int findInverseNumber(int num, int modulus){
    if(getGcd(num, modulus) != 1) return -1;
    int inverse = 0;
    int product;
    for(int i = 0; i < modulus; i++) {
        product = num * i;
        product = getModulo(product, modulus);
        if(product == 1) {
            inverse = i;
            break;
        }
    }
    return inverse;
}

/*
 * Returns a pointer to an inverse matrix.
 * Returns nullptr if the inverse matrix does not exist.
 */
std::vector<std::vector<int>> * findInverseMatrix(std::vector<std::vector<int>> * matrix, int modulus) {

    // Find the determinant
    int matrixDeterminant = getDeterminant(matrix, modulus);
    // Note: If the gcd(determinant, modulus) != 1, then the inverse of the determinant itself does not exist.
    // In this case, findInverseNumber will return -1 if the number does not have in inverse, per a gcd(num, modulus) test.
    int determinant_inv = findInverseNumber(matrixDeterminant, 26);
    if(determinant_inv == -1) {
        return nullptr;
    }

    auto * matrix_Inv = new std::vector<std::vector<int>> {{matrix->at(1).at(1), -matrix->at(0).at(1)},{-matrix->at(1).at(0), matrix->at(0).at(0)}};
    for(auto & i : *matrix_Inv) {
        for(int & j : i) {
            j *= determinant_inv;
            j = getModulo(j, 26);  // find residues mod 26
        }
    }

    return matrix_Inv;
}
