#ifndef DOUBLY_LL_PROCEDURE_H
#define DOUBLY_LL_PROCEDURE_H
#include <iostream>

// DoubleList Node
template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* next;
        DoubleList<T>* prev;
    };

// Creating a Node Function
template <typename T>
DoubleList<T>* createNode(T newData){
        // Dynamic Memory Allocation for a new node
        DoubleList<T>* newNode = new DoubleList<T>;

        newNode -> data = newData;
        // Point to the next node
        newNode -> prev = nullptr;
        newNode -> next = nullptr;

        return newNode;
    }

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){
    // Check it the list is empty
    if (currentNode == nullptr){
        std::cout << "The list is empty.";
        return;
    }

    DoubleList<T>* tail;
    std::cout << "Forward Traverse: ";

    // Forward Traverse
    while(currentNode != nullptr){
        std::cout << currentNode -> data << " -> ";
        tail = currentNode;
        currentNode = currentNode -> next;
    }

    std::cout << std::endl;

    // Reverse Traverse
    std::cout << "Reverse Traverse: ";
    while(tail != nullptr){
        std::cout << tail -> data << " -> ";
        tail = tail -> prev;
    }

    std::cout << std::endl;

}   

// Inserting a node at the head of the list
template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentNode ){
    // Create or allocate a new node
    DoubleList<T>* newNode = createNode(newData);

    // Point the new node to the current head
    newNode -> next = *currentNode;

    // Point the current node to the new node
    (*currentNode)->prev = newNode;
    (*currentNode) = newNode;
}

// Inserting at the end
template <typename T>
void dllInsertEnd(T newData, DoubleList<T> *currentHead){

    // Create a new Node
    DoubleList<T>* newNode = createNode(newData);

    // Traverse until we reach the last node
    while(currentHead -> next != nullptr){
        currentHead = currentHead -> next;
    }

    // Comnnect the new node back to the last node
    newNode -> prev = currentHead;

    // Connect the current node to the new node
    currentHead -> next = newNode;

}

// Inserting General Node
template <typename T>
void dllGeneralinsert(T newData, DoubleList<T>* prevNode){
    // Allocating
    DoubleList<T>* newNode = new DoubleList<T>;

    // Putting the data in the new node
    newNode -> data = newData;

    // Point the new node to the next node
    newNode -> next = prevNode -> next;

    // Point the new node to the previous node
    newNode -> prev = prevNode;

};

// Deleting a Node
template <typename T>
void dllDeleteNode(T data, DoubleList<T>** head){

    if(*head == nullptr) return;

    DoubleList<T>* currentNode = *head;
    DoubleList<T>* prevNode = nullptr;

    while (currentNode != nullptr && currentNode -> data != data){
        prevNode = currentNode;
        currentNode = currentNode -> next;
    }

    if(currentNode == nullptr) return;

    if(prevNode == nullptr){
        *head = currentNode -> next;
        if (*head != nullptr) {
    }else{
        prevNode -> next = currentNode -> next;
    }}
    delete currentNode;
   
}

#endif