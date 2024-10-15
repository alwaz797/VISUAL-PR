#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert a new node at the head of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the third index
    void insertAtThirdIndex(int value) {
        if (!head) {
            insertAtHead(value);
            return;
        }

        if (!head->next) {
            insertAtEnd(value);
            return;
        }

        if (!head->next->next) {
            insertAtEnd(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < 2; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Delete the node at the third position
    void deleteThirdNode() {
        if (!head) {
            std::cout << "Error: List is empty." << std::endl;
            return;
        }

        if (!head->next) {
            std::cout << "Error: List has fewer than three nodes." << std::endl;
            return;
        }

        if (!head->next->next) {
            std::cout << "Error: List has fewer than three nodes." << std::endl;
            return;
        }

        Node* current = head;
        for (int i = 0; i < 2; i++) {
            current = current->next;
        }
        current->next = current->next->next;
    }

    // Delete the node at the end of the list
    void deleteLastNode() {
        if (!head) {
            std::cout << "Error: List is empty." << std::endl;
            return;
        }

        if (!head->next) {
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }
        current->next = nullptr;
    }

    // Print the values in the linked list
    void printList() {
        Node* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Sing
