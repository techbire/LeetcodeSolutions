#include <bits/stdc++.h>
using namespace std;

// Node class for linked list
class Node {
public:
    int val;        // Node ka value
    Node* next;     // Pointer to the next node

    // Constructor to initialize node with value and set next to NULL
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// MyLinkedList class implementation
class MyLinkedList {
private:
    Node* head;     // Pointer to the head of the linked list
    int size;       // Size of the linked list

public:
    // Constructor: Initialize empty linked list
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    // Get value at specific index
    // Approach: Traverse the list to the given index and return the value
    int get(int index) {
        // Check if index is valid
        if (index < 0 || index >= size) {
            return -1; // Index out of bounds
        }
        Node* temp = head;
        // Traverse to the index
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->val;
    }

    // Add a node at the head
    // Approach: Create a new node and set it as the new head
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Add a node at the tail
    // Approach: Traverse to the end and add the new node
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = newNode;
        } else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Add a node at a specific index
    // Approach: Traverse to the index-1 position and insert the new node
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return; // Invalid index
        }
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            Node* newNode = new Node(val);
            Node* temp = head;
            // Traverse to the index-1 position
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            // Insert new node at the index position
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }

    // Delete a node at a specific index
    // Approach: Traverse to the index-1 position and adjust pointers to delete the node
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return; // Invalid index
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;
            // Traverse to the index-1 position
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            // Delete the node at the index position
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index, val);
 * obj->deleteAtIndex(index);
 */
