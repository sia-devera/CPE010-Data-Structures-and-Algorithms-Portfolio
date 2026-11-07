#include <iostream>
#include "DOUBLY_LL_PROCEDURE.h"

int main(){

    // C P E
    DoubleList<char>* head = createNode ('C');
    DoubleList<char>* second = createNode ('P');
    DoubleList<char>* third = createNode ('E');

    // Connect the head node to the next node
    head -> next = second;
    second -> prev = head;
    second -> next = third;
    third -> prev = second;

    // Traverse the list
    std::cout << "Listing the items in the Double List: " << std::endl;
    dllTraverse(head);

    // Insert the new node as the head
    std::cout << "Inserting a new item as the head." << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    // Insert a new node at the end
    std::cout << "Is the General Insert working?" << std::endl;
    std::cout << "General Insert working ..." << std::endl;
    std::cout << "Insert a new node at the end." << std::endl;
    dllInsertEnd('2', head);
    dllTraverse(head);

    // General Insert
    dllGeneralinsert('2', head -> next -> next);
    dllTraverse(head);

    std::cout << "Deleting a node from the list ..." << std::endl;
    dllDeleteNode('2', &head);
    dllTraverse(head);
    dllDeleteNode('C', &head);
    dllTraverse(head);

    return 0;
}