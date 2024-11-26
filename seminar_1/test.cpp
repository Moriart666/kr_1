#include "lib.hpp"

TEST_F(ArrayTest, ArrayRevers1_1) {
    array1.clear();
    array_revers1(array1);
    EXPECT_TRUE(array1.empty());
}

TEST_F(ArrayTest, ArrayRevers1_2) {
    array1.clear();
    array1 = {1};
    array_revers1(array1);
    EXPECT_EQ(array1, std::vector<int>({1}));
}

TEST_F(ArrayTest, ArrayRevers1_3) {
    array1.clear();
    array1 = {1, 2};
    array_revers1(array1);
    EXPECT_EQ(array1, std::vector<int>({2, 1}));
}

TEST_F(ArrayTest, ArrayRevers1_4) {
    array1.clear();
    array1 = {1, 2, 3, 4, 5};
    array_revers1(array1);
    EXPECT_EQ(array1, std::vector<int>({5, 4, 3, 2, 1}));
}

TEST_F(ArrayTest, ArrayRevers1_5) {
    array1.clear();
    array1 = {3, 8, 6, 9, 9, 8, 6};
    array_revers1(array1);
    EXPECT_EQ(array1, std::vector<int>({6, 8, 9, 9, 6, 8, 3}));
}

TEST_F(ArrayTest, ArrayRevers2_1){
    array1.clear();
    array1 = {1, 2, 3, 4, 5, 6, 7};
    array_revers2(array1, 3);
    EXPECT_EQ(array1, std::vector<int>({5, 6, 7, 1, 2, 3, 4}));
}

TEST_F(ArrayTest, ArrayRevers2_2){
    array1.clear();
    array1 = {1, 2, 3, 4, 5, 6, 7};
    array_revers2(array1, -3);
    EXPECT_EQ(array1, std::vector<int>({4, 5, 6, 7, 1, 2, 3}));
}

TEST_F(ArrayTest, ArrayRevers2_3){
    array1.clear();
    array1 = {1, 2, 3, 4, 5, 6, 7};
    array_revers2(array1, 10);
    EXPECT_EQ(array1, std::vector<int>({5, 6, 7, 1, 2, 3, 4}));
}

TEST_F(ArrayTest, ArrayRevers2_4) {
    array1.clear();
    array1 = {1};
    array_revers2(array1, 3);
    EXPECT_EQ(array1, std::vector<int>({1}));
}

TEST_F(ArrayTest, ArrayMergeSorted_1){
    array1.clear();
    array2.clear();
    array3.clear();
    array1 = {3, 8, 10, 11};
    array2 = {1, 7, 9};
    array3 = merge_sorted(array1, array2);
    EXPECT_EQ(array3, std::vector<int>({1, 3, 7, 8, 9, 10, 11}));
}

TEST_F(ArrayTest, ArrayMergeSorted_2){
    array1.clear();
    array2.clear();
    array3.clear();
    array1 = {1, 2, 3, 4, 5, 6, 7};
    array2 = {8, 9, 10, 11, 12};
    array3 = merge_sorted(array1, array2);
    EXPECT_EQ(array3, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}));
}

TEST_F(ArrayTest, ArrayMergeSorted_3){
    array1.clear();
    array2.clear();
    array3.clear();
    array1 = {1, 1, 1, 1, 1};
    array2 = {1, 1, 1, 1, 1, 1, 1, 1};
    array3 = merge_sorted(array1, array2);
    EXPECT_EQ(array3, std::vector<int>({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
}

TEST_F(ArrayTest, ArrayMergeSorted_4){
    array1.clear();
    array2.clear();
    array3.clear();
    array1 = {1, 2, 3, 4, 5, 6, 7};
    array2 = {-12, -11, -10 -9, -8, 0};
    array3 = merge_sorted(array1, array2);
    EXPECT_EQ(array3, std::vector<int>({-12, -11, -10 -9, -8, 0, 1, 2, 3, 4, 5, 6, 7}));
}

TEST_F(ArrayTest, ArrayMergeSorted2_1){
    array1.clear();
    array2.clear();
    array1 = {1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0};
    array2 = {8, 9, 10, 11};
    merge_sorted2(array1, array2);
    EXPECT_EQ(array1, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}));
}

TEST_F(ArrayTest, ArrayMergeSorted2_2){
    array1.clear();
    array2.clear();
    array1 = {8, 9, 10, 11, 0, 0, 0, 0, 0, 0, 0};
    array2 = {1, 2, 3, 4, 5, 6, 7};
    merge_sorted2(array1, array2);
    EXPECT_EQ(array1, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}));
}

TEST_F(ArrayTest, FirstEven_1){
    array1.clear();
    array1 = {3, 2, 4, 1, 11, 8, 9};
    first_even(array1);
    EXPECT_EQ(array1, std::vector<int>({2, 4, 8, 1, 11, 3, 9}));
}

TEST_F(ArrayTest, FirstEven_2){
    array1.clear();
    array1 = {3, 2, 4, 1, 11, 8, 9};
    first_even(array1);
    array2 = {2, 4, 8};
    for (size_t i = 0; i < 3; ++i){
        EXPECT_EQ(array1[i], array2[i]);
    }
}

TEST_F(ArrayTest, FirstEven_3){
    array1.clear();
    array1 = {-3, -2, -4, -1, -11, -8, -9, 0};
    first_even(array1);
    array2 = {-2, -4, -8, 0};
    for (size_t i = 0; i < 4; ++i){
        EXPECT_EQ(array1[i], array2[i]);
    }
}

TEST_F(ArrayTest, EndNull_1){
    array1.clear();
    array1 = {0, 0, 1, 0, 3, 12};
    end_null(array1);
    EXPECT_EQ(array1, std::vector<int>({1, 3, 12, 0, 0, 0}));
}

TEST_F(ArrayTest, EndNull_2){
    array1.clear();
    array1 = {0, 33, 57, 88, 60, 0, 0, 80, 99};
    end_null(array1);
    EXPECT_EQ(array1, std::vector<int>({33, 57, 88, 60, 80, 99, 0, 0, 0}));
}

TEST_F(ArrayTest, EndNull_3){
    array1.clear();
    array1 = {0, 0, 0, 18, 16, 0, 0, 77, 99};
    end_null(array1);
    EXPECT_EQ(array1, std::vector<int>({18, 16, 77, 99, 0, 0, 0, 0, 0}));
}




//...........................................................//
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}