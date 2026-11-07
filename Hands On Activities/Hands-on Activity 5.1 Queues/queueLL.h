#ifndef QUEUELL_H
#define QUEUELL_H
#include <iostream>

template <typename T>
class qNode {
public:
    T data;
    qNode<T>* next;
};

// Creating the new node
template <typename T>
qNode<T>* newNode(T newData) {
    qNode<T>* node = new qNode<T>;
    node->data = newData;
    node->next = nullptr;
    return node;
}

template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr) {

    // Create a new node:
    qNode<T>* standardNode = newNode(newData);

    // Inserting into an empty queue
    // Error catching:
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr){
        // Assign the frontPtr to the newNode
        (*frontPtr) = standardNode;
        (*backPtr) = standardNode;
        return;
    }

    //Point the back next to the newNode:
    (*backPtr) -> next = standardNode;
    //The newNode will be the new backPtr:
    (*backPtr) = standardNode;
    return;
}

template <typename T>
void dequeue(qNode<T> **frontPtr, qNode<T> **backPtr){

    // How to determine if the queue is empty?:
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout << "The queue is empty! nothing to dequeue." << std::endl;
        return;
    }

    // Creating a temporary pointer
    qNode <T>* tempPtr = nullptr;
    // Store the frontptr to the tempPtr:
    tempPtr = (*frontPtr);

    // Check if the queue is only 1 node left:
    if ((*frontPtr) == (*backPtr)){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete tempPtr;
        return;
    }

    // Update the fronPtr:
    (*frontPtr) = (*frontPtr) -> next;

    // Point the tempPtr -> next to null
    tempPtr -> next = nullptr;

    delete tempPtr;
}

// Display all items in the queue:
template <typename T>
void display(qNode<T>* frontPtr){

    // Catch if the queue is empty:

    // Temp Point to store the front Ptr:
     qNode<T>* current = frontPtr;

    // Create a loop that will print the tempPtr -> data:
    while (current != nullptr){
        std::cout << current->data << " " << std::endl;
        current = current -> next;
    }
    std::cout << std::endl;
}

#endif