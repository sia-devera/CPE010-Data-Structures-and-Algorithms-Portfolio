#include <iostream>
#ifndef STACK_LIST_H
#define STACK_LIST_H

// Class node that contains data and the next element
template <typename T>
class Node{
    public: 
    T data;
    Node* next;
};

// Global Pointer
template <typename T>
Node<T> *head = nullptr;

// Pushing function
template <typename T>
void push (T newData){
    // Creating new node and assigning newData
    Node<T>* newNode = new Node<T>;
    newNode -> data = newData;

    // New node points to the current top, then becomes the new top
    newNode -> next = head<T>;
    head<T> = newNode;
}

template <typename T>
T pop() {
    if (isEmpty<T>()) {
        std::cout << "Stack Underflow." << std::endl;
        return T();
    }

    Node<T>* temp = head<T>;
    T value = temp->data;

    head<T> = head<T> -> next;
    delete temp;

    return value;
}

//isEmpty function
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// Top function
template <typename T>
void Top(){
    // Error catching
    if(isEmpty<T>()){
        std::cout << "Stack Underflow." << std::endl;
        return;
    }

    // Displaying the top node
    std::cout << "The top of the stack is: " << head<T> -> data << std::endl;
}

// Displaying all the nodes from the stack
template <typename T>
void displayAll(){
    if(head<T> == nullptr){
        std::cout << "Stack is Underflow." << std::endl;
        return;
    }

    std::cout << "Displaying the Stack: " << std::endl;
    Node<T>* temp = head<T>;
    while(temp != nullptr){
        std::cout << temp -> data << std::endl;
        temp = temp -> next;
    }

    std::cout << std::endl;
}

#endif