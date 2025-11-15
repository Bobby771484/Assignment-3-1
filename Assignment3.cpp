#include <iostream>
#include "assignment3.h"

// Q2: Recursive search implementation

int recursive_last_index(const std::vector<int>& vec, int target, int index) {
    if (index < 0) {
        return -1;
    }

    if (vec[index] == target) {
        return index;
    }

    return recursive_last_index(vec, target, index - 1);
}

// Q3: Insertion sort on linked list

Node* insertion_sort_list(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* sorted = nullptr;

    while (head != nullptr) {
        Node* current = head;
        head = head->next;

        if (!sorted || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    return sorted;
}

// Helper functions for Q3 demo (optional)

Node* push_front(Node* head, int value) {
    return new Node(value, head);
}

void print_list(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << "\n";
}

// main(): demo for Q1, Q2, Q3

int main() {
    std::cout << "Q1: Queue demo\n";

    Queue<int> q;

    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    std::cout << "Initial queue contents: ";
    size_t n = q.size();
    for (size_t i = 0; i < n; ++i) {
        int val = q.front();
        std::cout << val << " ";
        q.pop();
        q.push(val);
    }
    std::cout << "\n";

    q.move_to_rear();

    std::cout << "After move_to_rear(): ";
    n = q.size();
    for (size_t i = 0; i < n; ++i) {
        int val = q.front();
        std::cout << val << " ";
        q.pop();
        q.push(val);
    }
    std::cout << "\n\n";

    std::cout << "Q2: Recursive last-occurrence search\n";

    std::vector<int> v = {2, 5, 7, 5, 9, 5};
    int target = 5;
    int index = recursive_last_index(v, target, static_cast<int>(v.size()) - 1);

    std::cout << "Vector: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\nTarget: " << target << "\n";
    std::cout << "Last occurrence index: " << index << "\n\n";

    std::cout << "Q3: Insertion sort on linked list\n";

    Node* head = nullptr;
    head = push_front(head, 3);
    head = push_front(head, 1);
    head = push_front(head, 8);
    head = push_front(head, 2);
    head = push_front(head, 5);

    std::cout << "Original list: ";
    print_list(head);

    head = insertion_sort_list(head);

    std::cout << "Sorted list:   ";
    print_list(head);

    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}
