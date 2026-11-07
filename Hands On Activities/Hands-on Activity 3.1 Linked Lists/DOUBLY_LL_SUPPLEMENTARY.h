#ifndef DOUBLY_LL_SUPPLEMENTARY_h
#define DOUBLY_LL_SUPPLEMENTARY_h

#include <string>

template <typename T>
class DoublyList{
public:
    T data;
    DoublyList<T>* prev;
    DoublyList<T>* next;
};

// Play all songs (Traverse Forward)
template <typename T>
void ListTraversal(DoublyList<T>* head){
    DoublyList<T>* currentNode = head;

    while(currentNode != nullptr){
        std::cout << currentNode->data;

        if(currentNode->next != nullptr){
            std::cout << " -> ";
        }

        currentNode = currentNode->next;
    }

    std::cout << std::endl;
}

// Play Previous Songs (Traverse Backward)
template <typename T>
void ReverseTraversal(DoublyList<T>* tail){
    DoublyList<T>* currentNode = tail;

    while(currentNode != nullptr){
        std::cout << currentNode->data;

        if(currentNode->prev != nullptr){
            std::cout << " -> ";
        }

        currentNode = currentNode->prev;
    }

    std::cout << std::endl;
}

// Add Song (Insert at End)
template <typename T>
void dllInsertEnd(T newData, DoublyList<T>** head){

    DoublyList<T>* newNode = new DoublyList<T>;

    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if(*head == nullptr){
        *head = newNode;
        return;
    }

    DoublyList<T>* currentNode = *head;

    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    newNode->prev = currentNode;
}

// Insert Song at Head
template <typename T>
void dllInsertHead(T newData, DoublyList<T>** head){

    DoublyList<T>* newNode = new DoublyList<T>;

    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = *head;

    if(*head != nullptr){
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// Insert Song After a Given Song
template <typename T>
void dllGeneralinsert(T newData, DoublyList<T>* prevNode){

    if(prevNode == nullptr)
        return;

    DoublyList<T>* newNode = new DoublyList<T>;

    newNode->data = newData;

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if(prevNode->next != nullptr){
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
}

// Remove Song
template <typename T>
void dllDeleteNode(T findData, DoublyList<T>** head){

    if(*head == nullptr)
        return;

    DoublyList<T>* currentNode = *head;

    while(currentNode != nullptr && currentNode->data != findData){
        currentNode = currentNode->next;
    }

    if(currentNode == nullptr)
        return;

    if(currentNode->prev == nullptr){
        *head = currentNode->next;

        if(*head != nullptr){
            (*head)->prev = nullptr;
        }
    }
    else{
        currentNode->prev->next = currentNode->next;

        if(currentNode->next != nullptr){
            currentNode->next->prev = currentNode->prev;
        }
    }

    delete currentNode;
}

#endif