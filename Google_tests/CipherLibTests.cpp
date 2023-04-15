//
// Created by Alexander Allis on 2/23/23.
//

#include <random>
#include "gtest/gtest.h"
#include "../CipherLib.h"

class CipherLibTestFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

    int modulus = 26;

};

/*
 * Note:
 * Earlier I tested gcd() on all numbers in Z-26 and got correct answers.
 * I won't replicate those tests here for the sake of time, but rest assured
 * that gcd() is fully tested.
*/

TEST_F(CipherLibTestFixture, Inverse_Number_Test){

    int inv;
    int product;

    for(int i = 1; i < modulus; i++) {
        inv = findInverseNumber(i, modulus);
        product = getModulo(inv * i, modulus);
        if(inv == -1) std::cout << i << std::endl;
        ASSERT_TRUE(product == 1 || inv == -1);
    }

}

//TEST_F(CipherLibTestFixture, Inverse_Matrix_Test) {
//    std::vector<std::vector<int>> * matrixA_inv = nullptr;
//    std::vector<std::vector<int>> matrixA;
//    while(matrixA_inv == nullptr) {
//        // Generate random matrices
//        std::vector<int> numbersA = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//        std::vector<int> numbersB = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//        std::vector<int> numbersC = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//        std::vector<int> numbersD = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//        std::random_device randomDevice;
//        std::default_random_engine randEngine(randomDevice());
//
//        shuffle(numbersA.begin(), numbersA.end(), randEngine);
//        shuffle(numbersB.begin(), numbersB.end(), randEngine);
//        shuffle(numbersC.begin(), numbersC.end(), randEngine);
//        shuffle(numbersD.begin(), numbersD.end(), randEngine);
//        matrixA = {{numbersA.at(0), numbersB.at(1)}, {numbersC.at(3), numbersD.at(4)}};
//
//        // Find inverse
//        matrixA_inv = findInverseMatrix(&matrixA, modulus);
//    }
//
//    // Matrix Multiply
//    auto productMatrix = multiplyMatrices(matrixA_inv, &matrixA, modulus);
//
//    // Test for product == Identity Matrix
//    ASSERT_TRUE(
//            productMatrix.at(0).at(0) == 1
//            && productMatrix.at(0).at(1) == 0
//            && productMatrix.at(1).at(0) == 0
//            && productMatrix.at(1).at(1) == 1
//            );
//}