#include "lib.hpp"

// Тесты для функции is_Subsequence
TEST(StringTests, IsSubsequence) {
    EXPECT_TRUE(is_Subsequence("abc", "ahbgdc"));
    EXPECT_TRUE(is_Subsequence("ace", "abcde"));
    EXPECT_FALSE(is_Subsequence("aec", "abcde"));
}

// Тесты для функции is_Palindrome_1
TEST(StringTests, IsPalindrome1) {
    EXPECT_TRUE(is_Palindrome_1("racecar"));
    EXPECT_TRUE(is_Palindrome_1("a"));
    EXPECT_FALSE(is_Palindrome_1("hello"));
    EXPECT_TRUE(is_Palindrome_1("madam"));
}

// Тесты для функции is_Palindrome_2
TEST(StringTests, IsPalindrome2) {
    EXPECT_TRUE(is_Palindrome_2("level"));
    EXPECT_FALSE(is_Palindrome_2("world"));
}

// Тесты для функции is_Palindrome_3
TEST(StringTests, IsPalindrome3) {
    EXPECT_TRUE(is_Palindrome_3("noon"));
    EXPECT_FALSE(is_Palindrome_3("python"));
}

// Тесты для функции binary_search_sqrt
TEST(MathTests, BinarySearchSqrt) {
    EXPECT_EQ(binary_search_sqrt(16), 4);
    EXPECT_EQ(binary_search_sqrt(20), 4);
    EXPECT_EQ(binary_search_sqrt(0), 0);
    EXPECT_EQ(binary_search_sqrt(1), 1);
}

// Тесты для функции delete_dublicat
TEST(StringTests, DeleteDublicat) {
    std::string str1 = "xyyx";
    delete_dublicat(str1);
    EXPECT_EQ(str1, "");

    std::string str2 = "fqffqzzsd";
    delete_dublicat(str2);
    EXPECT_EQ(str2, "fsd");

    std::string str3 = "aaabccddd";
    delete_dublicat(str3);
    EXPECT_EQ(str3, "b");
}

// Тесты для функции copy_time
TEST(CopyTimeTest, ZeroCopiesTest) {
    EXPECT_EQ(copy_time(0, 1, 1), 0);
}

TEST(CopyTimeTest, OneCopyTest) {
    EXPECT_EQ(copy_time(1, 2, 3), 2);
    EXPECT_EQ(copy_time(1, 5, 5), 5);
}

TEST(CopyTimeTest, DifferentSpeedsTest) {
    EXPECT_EQ(copy_time(5, 1, 2), 4);
    EXPECT_EQ(copy_time(5, 2, 3), 8);
    EXPECT_EQ(copy_time(3, 1, 10), 3);
}

TEST(CopyTimeTest, MinCopyTimeTest) {
    EXPECT_EQ(copy_time(3, 1, 10), 3);
    EXPECT_EQ(copy_time(3, 10, 1), 3);
}

TEST(CopyTimeTest, SingleFastCopierTest) {
    EXPECT_EQ(copy_time(10, 1, 1000), 10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}