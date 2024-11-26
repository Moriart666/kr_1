#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <gtest/gtest.h>

void shell_sort(std::vector<int>& array);

void feed_animals(const std::vector<int>& animals, const std::vector<int>& food, int& result);

char extraLetter(const std::string& a, const std::string& b);

std::vector<int> twoSum(const std::vector<int>& nums, int target);

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);