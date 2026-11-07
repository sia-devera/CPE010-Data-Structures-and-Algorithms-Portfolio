#ifndef QUEUELL_H
#define QUEUELL_H
#include <iostream>
#include <string>

class Printing {
public:
    int PrintOrder; // Order of rpinting
    std::string PrOr; // owner of the docu
    int pages; // Number of pages of the docu

    Printing() {
        PrintOrder = 0;
        PrOr = "";
        pages = 0;
    }

    Printing(int order, std::string name, int pageCount) {
        PrintOrder = order;
        PrOr = name;
        pages = pageCount;
    }

    void display() {
        std::cout << "Print Order: " << PrintOrder << std::endl;
        std::cout << "From: " << PrOr << std::endl;
        std::cout << "No. of Pages: " << pages << std::endl;
    }
};


// Node
class qNode {
public:
    Printing data;
    qNode* next;
};


// Creating a new node
qNode* newNode(Printing newData) {
    qNode* node = new qNode;
    node->data = newData;
    node->next = nullptr;
    return node;
}


// Enqueue
void enqueue(Printing newData, qNode** frontPtr, qNode** backPtr) {

    // Create a new node
    qNode* standardNode = newNode(newData);

    // If queue is empty
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        (*frontPtr) = standardNode;
        (*backPtr) = standardNode;
        return;
    }

    // Add new node to the back
    (*backPtr)->next = standardNode;

    // New node becomes the back
    (*backPtr) = standardNode;
}


// Dequeue
void dequeue(qNode** frontPtr, qNode** backPtr) {

    // Check if queue is empty
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        std::cout << "The printer queue is empty!" << std::endl;
        std::cout << std::endl;
        return;
    }

    // Temporary pointer
    qNode* tempPtr = (*frontPtr);

    // If only one node remains
    if ((*frontPtr) == (*backPtr)) {
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete tempPtr;
        return;
    }

    // Move front to the next node
    (*frontPtr) = (*frontPtr)->next;

    // Disconnect the old front
    tempPtr->next = nullptr;
    delete tempPtr;
}


// Display queue
void display(qNode* frontPtr) {
    if (frontPtr == nullptr) {
        std::cout << "No pending printing jobs." << std::endl;
        std::cout << std::endl;
        return;
    }

    qNode* current = frontPtr;
    while (current != nullptr) {
        current->data.display();
        std::cout << "               " << std::endl;
        std::cout << std::endl;
        current = current->next;
    }
}

#endif