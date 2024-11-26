#include "lib.hpp"

TEST(ShellSortTest, BasicTest) {
    std::vector<int> array = {12, 34, 54, 2, 3};
    shell_sort(array);
    std::vector<int> expected = {2, 3, 12, 34, 54};
    EXPECT_EQ(array, expected);
}

TEST(ShellSortTest, AlreadySorted) {
    std::vector<int> array = {1, 2, 3, 4, 5};
    shell_sort(array);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(array, expected);
}

TEST(ShellSortTest, ReverseSorted) {
    std::vector<int> array = {5, 4, 3, 2, 1};
    shell_sort(array);
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(array, expected);
}



TEST(FeedAnimalsTest, BasicTest) {
    std::vector<int> animals = {1, 2, 3, 4, 8};
    std::vector<int> food = {8, 3, 9, 1, 7};
    int result = 0;
    feed_animals(animals, food, result);
    EXPECT_EQ(result, 5);
}

TEST(FeedAnimalsTest, NotEnoughFood) {
    std::vector<int> animals = {5, 5, 5};
    std::vector<int> food = {1, 2, 3, 5};
    int result = 0;
    feed_animals(animals, food, result);
    EXPECT_EQ(result, 1);
}

TEST(FeedAnimalsTest, ExcessFood) {
    std::vector<int> animals = {1, 2};
    std::vector<int> food = {1, 2, 2, 1};
    int result = 0;
    feed_animals(animals, food, result);
    EXPECT_EQ(result, 2);
}

TEST(FeedAnimalsTest, NoMatchingFood) {
    std::vector<int> animals = {4, 4, 4};
    std::vector<int> food = {1, 2, 3};
    int result = 0;
    feed_animals(animals, food, result);
    EXPECT_EQ(result, 0);
}

TEST(FeedAnimalsTest, MultipleAnimalsSameFood) {
    std::vector<int> animals = {2, 2, 2};
    std::vector<int> food = {2, 2};
    int result = 0;
    feed_animals(animals, food, result);
    EXPECT_EQ(result, 2);
}



TEST(ExtraLetterTest, BasicTest) {
    std::string a = "abcd";
    std::string b = "abcde";
    char extra = extraLetter(a, b);
    EXPECT_EQ(extra, 'e');
}

TEST(ExtraLetterTest, ShuffledTest) {
    std::string a = "abcd";
    std::string b = "aecdb";
    char extra = extraLetter(a, b);
    EXPECT_EQ(extra, 'e');
}

TEST(ExtraLetterTest, DuplicateLetters) {
    std::string a = "aabbcc";
    std::string b = "abcbcad";
    char extra = extraLetter(a, b);
    EXPECT_EQ(extra, 'd');
}


TEST(TwoSumTest, BasicTest) {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> indices = twoSum(nums, target);
    EXPECT_EQ(indices.size(), 2);
    EXPECT_EQ(nums[indices[0]] + nums[indices[1]], target);
}

TEST(TwoSumTest, NoSolutionTest) {
    std::vector<int> nums = {1, 2, 3};
    int target = 7;
    std::vector<int> indices = twoSum(nums, target);
    EXPECT_TRUE(indices.empty());
}

TEST(TwoSumTest, MultipleSolutionsTest) {
    std::vector<int> nums = {1, 3, 3, 4};
    int target = 6;
    std::vector<int> indices = twoSum(nums, target);
    EXPECT_EQ(indices.size(), 2);
    EXPECT_EQ(nums[indices[0]] + nums[indices[1]], target);
}


// Функция для сортировки групп и слов внутри групп
void sortResult(std::vector<std::vector<std::string>>& result) {
    for (auto& group : result) {
        std::sort(group.begin(), group.end());
    }
    std::sort(result.begin(), result.end());
}

TEST(GroupAnagramsTest, BasicTest) {
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto result = groupAnagrams(strs);

    std::vector<std::vector<std::string>> expected = {
        {"bat"},
        {"nat","tan"},
        {"ate","eat","tea"}
    };

    // Сортируем результаты и ожидаемые данные
    sortResult(result);
    sortResult(expected);

    // Проверяем, что результаты совпадают
    EXPECT_EQ(result, expected);
}

TEST(GroupAnagramsTest, DuplicateStrings) {
    std::vector<std::string> strs = {"ooo","ooo","won","now","aaa"};
    auto result = groupAnagrams(strs);

    std::vector<std::vector<std::string>> expected = {
        {"aaa"},
        {"now","won"},
        {"ooo","ooo"}
    };

    // Сортируем результаты и ожидаемые данные
    sortResult(result);
    sortResult(expected);

    // Проверяем, что результаты совпадают
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}