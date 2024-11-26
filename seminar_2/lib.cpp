#include "lib.hpp"

// Конструктор узла
Node::Node(int value) : info(value), next(nullptr) {}

// Конструкторы и методы класса Single_list

Single_list::Single_list() : head(nullptr), is_cleared(false) {}

Single_list::Single_list(Node* node) : head(node), is_cleared(false) {}

Single_list::Single_list(const Single_list& other) : head(nullptr), is_cleared(false) {
    Node* current = other.head;
    while (current) {
        append(current->info);
        current = current->next;
    }
}

Single_list& Single_list::operator=(const Single_list& other) {
    if (this != &other) {
        clear();
        Node* current = other.head;
        while (current) {
            append(current->info);
            current = current->next;
        }
    }
    return *this;
}

Single_list::~Single_list() {
    clear();
}

void Single_list::clear() {
    if (is_cleared) {
        return;
    }
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    is_cleared = true;
}

void Single_list::append(int value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void Single_list::remove(int value) {
    if (!head) {
        return;
    }

    if (head->info == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next && current->next->info != value) {
        current = current->next;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void Single_list::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->info << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

Node* Single_list::get_node() {
    return head;
}

void Single_list::append_vector(const std::vector<int>& vector) {
    for (size_t i = 0; i < vector.size(); ++i) {
        append(vector[i]);
    }
}

Node* Single_list::find_node(int value) {
    Node* current = head;
    while (current) {
        if (current->info == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Функция проверки на наличие цикла в списке
bool has_cycle(Node* head) {
    if (head == nullptr) {
        std::cout << "нету цикла" << std::endl;
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            std::cout << "есть цикл" << std::endl;
            return true;
        }
    }

    std::cout << "нету цикла" << std::endl;
    return false;
}

// Функция разворота односвязного списка
Node* reverse_linked_list(Node* head) {
    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Функция нахождения середины списка
Node* middle_node(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Функция слияния двух отсортированных списков
Single_list merge_single_linked_list(Single_list& list1, Single_list& list2) {
    Node* left = list1.get_node();
    Node* right = list2.get_node();
    Node* head = nullptr;
    Node* tail = nullptr;

    while (left != nullptr && right != nullptr) {
        Node* new_node;
        if (left->info < right->info) {
            new_node = new Node(left->info);
            left = left->next;
        } else {
            new_node = new Node(right->info);
            right = right->next;
        }

        if (head == nullptr) {
            head = new_node;
        } else {
            tail->next = new_node;
        }
        tail = new_node;
    }

    while (left != nullptr) {
        Node* new_node = new Node(left->info);
        if (head == nullptr) {
            head = new_node;
            tail = head;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        left = left->next;
    }

    while (right != nullptr) {
        Node* new_node = new Node(right->info);
        if (head == nullptr) {
            head = new_node;
            tail = head;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        right = right->next;
    }

    return Single_list(head);
}