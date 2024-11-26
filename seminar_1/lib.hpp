#pragma once
#include <iostream>
#include <vector>
#include "gtest/gtest.h"

void array_revers1(std::vector<int>& array);

void temp_revers2(std::vector<int>& array, int left, int right);

void array_revers2(std::vector<int>& array, int k);

std::vector<int> merge_sorted(std::vector<int>& left, std::vector<int>& right);

std::vector<int> merge_sorted2(std::vector<int>& left,
                               std::vector<int>& right);

void first_even(std::vector<int>& array);

void end_null(std::vector<int>& array);

class ArrayTest : public ::testing::Test {
protected:
    std::vector<int> array1;
    std::vector<int> array2;
    std::vector<int> array3;

    void SetUp() override {
    }

    void TearDown() override {
    }
};
