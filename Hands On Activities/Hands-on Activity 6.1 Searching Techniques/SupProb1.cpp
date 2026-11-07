#include <iostream>
#include <cstdlib>
#include <time.h>
#include "supSearchingAlgo.h" 

int main(){ 

    /*
    // Problem #1
    Node<int>* num1 = new_node(15);
    Node<int>* num2 = new_node(18);
    Node<int>* num3 = new_node(2);
    Node<int>* num4 = new_node(19);
    Node<int>* num5 = new_node(0);
    Node<int>* num6 = new_node(8);
    Node<int>* num7 = new_node(14);
    Node<int>* num8 = new_node(19);
    Node<int>* num9 = new_node(14);

    num1 -> next = num2;
    num2 -> next = num3;
    num3 -> next = num4;
    num4 -> next = num5;
    num5 -> next = num6;
    num6 -> next = num7;
    num7 -> next = num8;
    num8 -> next = num9;

    linearSearchLL(num1, 18);

    
    // Problem #2
    int data[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int count = LLSearchCount(18, 18, data);

    std::cout << "The element '18' appeared " << count << " times in the list." << std::endl;


    // Problem #3
    int data[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int maxSize = 10;

    std::cout << "Sorted List: ";

    for (int i = 0; i < maxSize; i++) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;

    ArrBinSearch(8, data, maxSize);

    return 0;

    */

    // problem #4
    int data[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int maxSize = 10;

    std::cout << "Sorted List: ";

    for (int i = 0; i < maxSize; i++) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;

    ArrBinSearch(8, data, 0, maxSize - 1);

}

