//
// Created by Alexander Allis on 3/6/23.
//

#include "gtest/gtest.h"
#include "../lib/Index_of_Coincidence.h"

class IndexOfCoincidenceTestClass : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

};

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m1_test_1){

    auto * ciphertext = new std::vector<char> {'a'};
    int m = 1;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m1_test_2){

    auto * ciphertext = new std::vector<char> {'a', 'b'};
    int m = 1;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m1_test_3){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c'};
    int m = 1;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m1_test_4){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd'};
    int m = 1;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m1_test_5){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e'};
    int m = 1;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m1_test_6){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e', 'f'};
    int m = 1;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m1_test_7){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int m = 1;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m1_test_8){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int m = 1;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m2_test_1){

    auto * ciphertext = new std::vector<char> {'a'};
    int m = 2;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

    delete ciphertext;
    delete indexOfCoincidence;

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m2_test_2){

    auto * ciphertext = new std::vector<char> {'a', 'b'};
    int m = 2;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m2_test_3){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c'};
    int m = 2;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m2_test_4){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd'};
    int m = 2;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m2_test_5){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e'};
    int m = 2;
    std::vector<std::vector<char>> *indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m2_test_6){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e', 'f'};
    int m = 2;
    std::vector<std::vector<char>> *indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m2_test_7){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int m = 2;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m2_test_8){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int m = 2;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m3_test_1){

    auto * ciphertext = new std::vector<char> {'a'};
    int m = 3;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

    delete ciphertext;
    delete indexOfCoincidence;

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m3_test_2){

    auto * ciphertext = new std::vector<char> {'a', 'b'};
    int m = 3;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m3_test_3){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c'};
    int m = 3;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m3_test_4){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd'};
    int m = 3;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m3_test_5){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e'};
    int m = 3;
    std::vector<std::vector<char>> *indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m3_test_6){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e', 'f'};
    int m = 3;
    std::vector<std::vector<char>> *indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m3_test_7){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int m = 3;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}

TEST_F(IndexOfCoincidenceTestClass, buildMatrix_m3_test_8){

    auto * ciphertext = new std::vector<char> {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int m = 3;
    std::vector<std::vector<char>> * indexOfCoincidence = constructIndexOfCoincidence(m, ciphertext);

    int size = 0;
    for(auto & i : *indexOfCoincidence) {
        size += (int) i.size();
    }
    ASSERT_TRUE(size == ciphertext->size());

}