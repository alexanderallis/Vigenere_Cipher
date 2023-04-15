//
// Created by Alexander Allis on 3/6/23.
//

#include "gtest/gtest.h"
#include "../lib/Index_of_Coincidence.h"

class IndexOfConfidenceTestClass : public ::testing::Test {

protected:
    virtual void SetUp() {}

    virtual void TearDown() {}

};

TEST_F(IndexOfConfidenceTestClass, m1_test_1){

    std::vector<char> ciphertext = {'a', 'b', 'a', 'b', 'a', 't', 'g', 'h'};
    std::vector<std::vector<char>> * ioCoincidence;

    ioCoincidence = constructIndexOfCoincidence(1, &ciphertext);

    std::vector<float> ioConfidence = calculateIndexOfConfidence(ioCoincidence);

    EXPECT_NEAR(ioConfidence.at(0), 0.25, 0.0001);

}

TEST_F(IndexOfConfidenceTestClass, m1_test_2){

    std::vector<char> ciphertext = {'a', 'b', 'c', 'd', 'a', 't', 'g', 'h'};
    std::vector<std::vector<char>> * ioCoincidence;

    ioCoincidence = constructIndexOfCoincidence(1, &ciphertext);

    std::vector<float> ioConfidence = calculateIndexOfConfidence(ioCoincidence);

    EXPECT_NEAR(ioConfidence.at(0), 0.15625, 0.0001);

}

TEST_F(IndexOfConfidenceTestClass, m1_test_3){

    std::vector<char> ciphertext = {'a', 'a', 'z', 'a', 'a', 'b', 'b', 'b'};
    std::vector<std::vector<char>> * ioCoincidence;

    ioCoincidence = constructIndexOfCoincidence(1, &ciphertext);

    std::vector<float> ioConfidence = calculateIndexOfConfidence(ioCoincidence);

    EXPECT_NEAR(ioConfidence.at(0), 0.40625, 0.0001);

}

TEST_F(IndexOfConfidenceTestClass, m2_test_1){

    std::vector<char> ciphertext = {'a', 'b', 'a', 'd', 'e', 'b', 'g', 'h'};
    std::vector<std::vector<char>> * ioCoincidence;

    ioCoincidence = constructIndexOfCoincidence(2, &ciphertext);

    std::vector<float> ioConfidence = calculateIndexOfConfidence(ioCoincidence);

    EXPECT_NEAR(ioConfidence.at(0), 0.375, 0.0001);
    EXPECT_NEAR(ioConfidence.at(1), 0.375, 0.0001);

}

TEST_F(IndexOfConfidenceTestClass, m2_test_2){

    std::vector<char> ciphertext = {'a', 'b', 'a', 'z', 'a', 't', 'g', 'h'};
    std::vector<std::vector<char>> * ioCoincidence;

    ioCoincidence = constructIndexOfCoincidence(2, &ciphertext);

    std::vector<float> ioConfidence = calculateIndexOfConfidence(ioCoincidence);

    EXPECT_NEAR(ioConfidence.at(0), 0.625, 0.0001);
    EXPECT_NEAR(ioConfidence.at(1), 0.25, 0.0001);

}

TEST_F(IndexOfConfidenceTestClass, m3_test_1){

    std::vector<char> ciphertext = {'a', 'b', 'a', 'd', 'b', 'b', 'g', 'h'};
    std::vector<std::vector<char>> * ioCoincidence;

    ioCoincidence = constructIndexOfCoincidence(3, &ciphertext);

    std::vector<float> ioConfidence = calculateIndexOfConfidence(ioCoincidence);

    EXPECT_NEAR(ioConfidence.at(0), 0.3333, 0.0001);
    EXPECT_NEAR(ioConfidence.at(1), 0.5555, 0.0001);
    EXPECT_NEAR(ioConfidence.at(2), 0.5, 0.0001);

}

TEST_F(IndexOfConfidenceTestClass, m4_test_2){

    std::vector<char> ciphertext = {'a', 'q', 'o', 'x', 'a', 'o', 'g', 's'};
    std::vector<std::vector<char>> * ioCoincidence;

    ioCoincidence = constructIndexOfCoincidence(4, &ciphertext);

    std::vector<float> ioConfidence = calculateIndexOfConfidence(ioCoincidence);

    EXPECT_NEAR(ioConfidence.at(0), 1.0, 0.0001);
    EXPECT_NEAR(ioConfidence.at(1), 0.5, 0.0001);
    EXPECT_NEAR(ioConfidence.at(2), 0.5, 0.0001);
    EXPECT_NEAR(ioConfidence.at(3), 0.5, 0.0001);

}

