#pragma once
#include <vector>
#include <iostream>
#include <gtest/gtest.h>

// Реализация односвязного списка со всеми необходимыми методами для задачи

struct Node {
    int info;
    Node* next;

    Node(int value);
};

class Single_list {
private:
    Node* head;
    bool is_cleared;

public:
    Single_list();
    Single_list(Node* node);
    Single_list(const Single_list& other);
    Single_list& operator=(const Single_list& other);
    ~Single_list();

    void clear();
    void append(int value);
    void remove(int value);
    void print() const;
    Node* get_node();
    void append_vector(const std::vector<int>& vector);
    Node* find_node(int value);
};

// Проверить, является ли список циклическим
bool has_cycle(Node* head);

// Развернуть односвязный список
Node* reverse_linked_list(Node* head);

// Найти середину списка
Node* middle_node(Node* head);

// Слияние двух отсортированных списков
Single_list merge_single_linked_list(Single_list& list1, Single_list& list2);