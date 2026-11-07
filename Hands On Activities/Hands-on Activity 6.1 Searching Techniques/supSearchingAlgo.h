#include "node.h"
#ifndef SUPSEARCHINGALGO_H
#define SUPSEARCHINGALGO_H

/*
//Problem #1
// will use sequential search ll 
template <typename T>
void linearSearchLL(Node<T>* node, T dataFind){

    int comparisons = 0;
    while (node != nullptr) {
        comparisons++;
        if (node->data == dataFind) {
            std::cout << "The data is found in the list!" << std::endl;
            std::cout << "Number of comparisons: " << std::endl;
            std::cout << comparisons << std::endl;
            return;
        }
        node = node->next;
    }

    std::cout << "The data is not found in the list." << std::endl;
    std::cout << "Number of comparisons: " << std::endl;
    std::cout << comparisons << std::endl;
}
    
//Problem #2
template <typename T>
int LLSearchCount(int max_Size, T dataFind, T data[]) {
    int count = 0;
    for (int i = 0; i < max_Size; i++) {
        if (data[i] == dataFind) {
            count++;
        }
    }
    return count;
}


//Problem #3
template <typename T>
void ArrBinSearch(T dataFind, T data[], int max_Size) {

    int bottom = 0, upper = max_Size - 1, midpoint;

    while(bottom <= upper){
        midpoint = (int)((bottom + upper) / 2);

        if(dataFind == data[midpoint]){
            std::cout << "The data is in the list!" << std::endl;
            return;
        }
        else if(dataFind > data[midpoint]){
            bottom = midpoint + 1;
        }
        else{
            upper = midpoint - 1;
        }
    }

    std::cout << "No such element in the list." << std::endl;
}
    */

    // problem #4
    template <typename T>
void ArrBinSearch(T dataFind, T data[], int bottom, int upper){

    if(bottom > upper){
        std::cout << "No such element in the list." << std::endl;
        return;
    }

    int midpoint = (int)((bottom + upper) / 2);

    if(dataFind == data[midpoint]){
        std::cout << "The data is in the list!" << std::endl;
        return;
    }
    else if(dataFind > data[midpoint]){
        ArrBinSearch(dataFind, data, midpoint + 1, upper);
    }
    else{
        ArrBinSearch(dataFind, data, bottom, midpoint - 1);
    }
}

#endif