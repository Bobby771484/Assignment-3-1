#include <iostream>
#include "assignment3.h"

// =======================
// Q2: Recursive search implementation
// =======================

int recursive_last_index(const std::vector<int>& vec, int target, int index) {
    // Base case: index out of range
    if (index < 0) {
        return -1;
    }

    // First search earlier portion to find a later occurrence
    int result = recursive_last_index(vec, target, index - 1);

    if (result != -1) {
        // We already found a later occurrence, keep it
        return result;
    }

    // No later occurrence found, check current index
    if (vec[index] == target) {
        return index;
    }

    return -1;
}

// =======================
// Q3: Insertion sort on linked list
// =======================

Node* insertion_sort_list(Node* head) {
    if (!head || !head->next) {
        return head; // already sorted (0 or 1 node)
    }

    Node* sorted = nullptr; // new sorted list head

    while (head != nullptr) {
        Node* current = head;     // take one node from original list
        head = head->next;        // move head forward

        // Insert 'current' into proper position in 'sorted'
        if (!sorted || current->data < sorted->data) {
            // Insert at front of sorted list
            current->next = sorted;
            sorted = current;
        } else {
            // Find insertion position in sorted list
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            // Insert after temp
            current->next = temp->next;
            temp->next = current;
        }
    }

    return sorted;
}

// =======================
// Helper functions for Q3 demo (not required by assignment, just for testing)
// =======================

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

// =======================
// main(): demo for Q1, Q2, Q3
// =======================

int main() {
    // ------------- Q1: Queue demo -------------
    std::cout << "Q1: Queue demo\n";

    Queue<int> q;

    // Push 10 integer values
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    // Display all elements using only queue functions (push, pop, front, size, empty)
    std::cout << "Initial queue contents: ";
    size_t n = q.size();
    for (size_t i = 0; i < n; ++i) {
        int val = q.front();
        std::cout << val << " ";
        q.pop();      // remove from front
        q.push(val);  // push back to maintain order
    }
    std::cout << "\n";

    // Test move_to_rear()
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

    // ------------- Q2: Recursive last occurrence demo -------------
    std::cout << "Q2: Recursive last-occurrence search\n";

    std::vector<int> v = {2, 5, 7, 5, 9, 5};
    int target = 5;
    int index = recursive_last_index(v, target, static_cast<int>(v.size()) - 1);

    std::cout << "Vector: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\nTarget: " << target << "\n";
    std::cout << "Last occurrence index: " << index << "\n\n";

    // ------------- Q3: Insertion sort on list demo -------------
    std::cout << "Q3: Insertion sort on linked list\n";

    Node* head = nullptr;
    // Build unsorted list: 5 -> 2 -> 8 -> 1 -> 3
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

    // Cleanup linked list
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}
