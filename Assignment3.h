#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <cstddef>   // size_t
#include <vector>    // for Q2

// =======================
// Q1: Template Queue ADT
// =======================

template <typename Item_Type>
class Queue {
private:
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& d, Node* n = nullptr)
            : data(d), next(n) {}
    };

    Node* front_ptr;
    Node* rear_ptr;
    size_t num_items;

public:
    Queue() : front_ptr(nullptr), rear_ptr(nullptr), num_items(0) {}

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    // push: insert at rear (O(1))
    void push(const Item_Type& item) {
        Node* new_node = new Node(item);

        if (empty()) {
            front_ptr = rear_ptr = new_node;
        } else {
            rear_ptr->next = new_node;
            rear_ptr = new_node;
        }

        num_items++;
    }

    // pop: remove from front (O(1))
    void pop() {
        if (empty()) {
            throw std::runtime_error("pop() called on empty queue");
        }

        Node* old_front = front_ptr;
        front_ptr = front_ptr->next;
        delete old_front;
        num_items--;

        if (num_items == 0) {
            rear_ptr = nullptr;
        }
    }

    // front: access front element
    Item_Type front() const {
        if (empty()) {
            throw std::runtime_error("front() called on empty queue");
        }
        return front_ptr->data;
    }

    // size: number of items
    size_t size() const {
        return num_items;
    }

    // empty: true if queue is empty
    bool empty() const {
        return num_items == 0;
    }

    // move_to_rear: move front element to back, using only push, pop, front
    void move_to_rear() {
        if (size() <= 1) {
            return; // nothing to do
        }
        Item_Type temp = front(); // read front value
        pop();                    // remove it
        push(temp);               // push it at the rear
    }
};

// =======================
// Q2: Recursive Linear Search
// (last occurrence in a vector)
// =======================

// Returns the index of the *last* occurrence of target in vec[0..index].
// If target is not found, returns -1.
int recursive_last_index(const std::vector<int>& vec, int target, int index);

// =======================
// Q3: Insertion Sort on Linked List
// =======================

struct Node {
    int data;
    Node* next;
    Node(int d, Node* n = nullptr) : data(d), next(n) {}
};

// Sorts a singly linked list using insertion sort and returns new head.
Node* insertion_sort_list(Node* head);

#endif // ASSIGNMENT3_H
