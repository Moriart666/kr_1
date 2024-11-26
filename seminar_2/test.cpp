#include "lib.hpp"

// Тестовый класс для Single_list
class SingleListTest : public ::testing::Test {
protected:
    Single_list list;

    void SetUp() override {
        list.append(1);
        list.append(2);
        list.append(3);
    }
};

TEST_F(SingleListTest, AppendTest) {
    list.append(4);
    std::vector<int> expected = {1, 2, 3, 4};
    Node* current = list.get_node();
    for (int val : expected) {
        ASSERT_NE(current, nullptr);
        EXPECT_EQ(current->info, val);
        current = current->next;
    }
    EXPECT_EQ(current, nullptr);
}

TEST_F(SingleListTest, RemoveTest) {
    list.remove(2);
    std::vector<int> expected = {1, 3};
    Node* current = list.get_node();
    for (int val : expected) {
        ASSERT_NE(current, nullptr);
        EXPECT_EQ(current->info, val);
        current = current->next;
    }
    EXPECT_EQ(current, nullptr);
}

TEST_F(SingleListTest, FindNodeTest) {
    Node* node = list.find_node(2);
    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->info, 2);

    node = list.find_node(4);
    EXPECT_EQ(node, nullptr);
}

TEST(SingleListStaticTest, HasCycleTest) {
    Single_list list;
    list.append_vector({1, 2, 3, 4, 5});
    EXPECT_FALSE(has_cycle(list.get_node()));

    // Создаем цикл для теста
    Node* head = list.get_node();
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = head->next; // Создаем цикл
    EXPECT_TRUE(has_cycle(list.get_node()));

    // Разрываем цикл, чтобы избежать проблем с памятью
    tail->next = nullptr;
}

TEST(SingleListStaticTest, ReverseLinkedListTest) {
    Single_list list;
    list.append_vector({1, 2, 3, 4, 5});
    Node* reversed_head = reverse_linked_list(list.get_node());

    std::vector<int> expected = {5, 4, 3, 2, 1};
    Node* current = reversed_head;
    for (int val : expected) {
        ASSERT_NE(current, nullptr);
        EXPECT_EQ(current->info, val);
        current = current->next;
    }
    EXPECT_EQ(current, nullptr);
}

TEST(SingleListStaticTest, MiddleNodeTest) {
    Single_list list;
    list.append_vector({1, 2, 3, 4, 5});
    Node* middle = middle_node(list.get_node());
    ASSERT_NE(middle, nullptr);
    EXPECT_EQ(middle->info, 3);

    list.append(6);
    middle = middle_node(list.get_node());
    ASSERT_NE(middle, nullptr);
    EXPECT_EQ(middle->info, 4);
}

TEST(SingleListStaticTest, MergeSingleLinkedListTest) {
    Single_list list1;
    list1.append_vector({1, 3, 5});
    Single_list list2;
    list2.append_vector({2, 4, 6});

    Single_list merged_list = merge_single_linked_list(list1, list2);

    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    Node* current = merged_list.get_node();
    for (int val : expected) {
        ASSERT_NE(current, nullptr);
        EXPECT_EQ(current->info, val);
        current = current->next;
    }
    EXPECT_EQ(current, nullptr);
}

TEST(SingleListStaticTest, ClearTest) {
    Single_list list;
    list.append_vector({1, 2, 3});
    list.clear();
    EXPECT_EQ(list.get_node(), nullptr);
}

TEST(SingleListStaticTest, CopyConstructorTest) {
    Single_list list1;
    list1.append_vector({1, 2, 3});
    Single_list list2 = list1;

    Node* current1 = list1.get_node();
    Node* current2 = list2.get_node();
    while (current1 && current2) {
        EXPECT_EQ(current1->info, current2->info);
        EXPECT_NE(current1, current2); // Проверяем, что это разные узлы
        current1 = current1->next;
        current2 = current2->next;
    }
    EXPECT_EQ(current1, nullptr);
    EXPECT_EQ(current2, nullptr);
}

TEST(SingleListStaticTest, AssignmentOperatorTest) {
    Single_list list1;
    list1.append_vector({1, 2, 3});
    Single_list list2;
    list2 = list1;

    Node* current1 = list1.get_node();
    Node* current2 = list2.get_node();
    while (current1 && current2) {
        EXPECT_EQ(current1->info, current2->info);
        EXPECT_NE(current1, current2); // Проверяем, что это разные узлы
        current1 = current1->next;
        current2 = current2->next;
    }
    EXPECT_EQ(current1, nullptr);
    EXPECT_EQ(current2, nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}