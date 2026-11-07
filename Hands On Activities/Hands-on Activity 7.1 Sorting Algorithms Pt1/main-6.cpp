#include <iostream>
#include <cstdlib>
#include "SortingAlgo.h"

const int MaxSize = 100;

int main() {

    int arr[MaxSize];
    std::cout << "                  Random Numbers:" << std::endl;

    for (int i = 0; i < MaxSize; i++) {
        arr[i] = rand() % 999;
        std::cout << arr[i] << " ";
    }

    // BubSort
    std::cout << std::endl;
    std::cout << "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    BubSorting(arr, MaxSize);

    std::cout << std::endl;
    std::cout << "                  Bubble Sorted Numbers:" << std::endl;

    for (int i = 0; i < MaxSize; i++) {
        std::cout << arr[i] << " ";
    }

    // SelSort
    std::cout << std::endl;
    std::cout << "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl; 
    std::cout << "                  Selection Sorting: " << std::endl;
    SelSort(arr, MaxSize);
        for (int i = 0; i < MaxSize; i++) {
    std::cout << arr[i] << " ";
}

    std::cout << std::endl;

    //InsSort
    std::cout << std::endl;
    std::cout << "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl; 
    std::cout << "                  Insertion Sorting: " << std::endl;
    InsSort(arr, MaxSize);
        for (int i = 0; i < MaxSize; i++) {
    std::cout << arr[i] << " ";
}


    return 0;
}