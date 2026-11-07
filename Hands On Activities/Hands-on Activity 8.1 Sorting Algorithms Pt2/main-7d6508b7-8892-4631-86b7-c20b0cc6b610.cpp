#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SMQ.h"


const int SIZE = 100;

void displayArray(int array[], int size){
    for (int i = 0; i < size; i++){
        std::cout << array[i] << " ";

        if ((i + 1) % 10 == 0){
            std::cout << std::endl;
        }
    }
}

int main()
{
    int originalArray[SIZE];
    int shellArray[SIZE];
    int mergeArray[SIZE];
    int quickArray[SIZE];

    std::srand(time(0));

    // Create 100 random elements
    for (int i = 0; i < SIZE; i++)
    {
        originalArray[i] = rand() % 1000 + 1;

        shellArray[i] = originalArray[i];
        mergeArray[i] = originalArray[i];
        quickArray[i] = originalArray[i];
    }

    SortingAlgorithms<int> sorting;

    std::cout << "THE 100 UNSORTED ELEMENTS: " << std::endl;
    std::cout << std::endl;
    displayArray(originalArray, SIZE);

    std::cout << std::endl;

    sorting.shellSort(shellArray, SIZE);

    std::cout << "SHELL SORTED ARRAY: " << std::endl;
    std::cout << std::endl;
    displayArray(shellArray, SIZE);

    std::cout << std::endl;

    sorting.mergeSort(mergeArray, 0, SIZE - 1);

    std::cout << "MERGE SORTED ARRAY: " << std::endl;
    std::cout << std::endl;
    displayArray(mergeArray, SIZE);

    std::cout << std::endl;

    sorting.quickSort(quickArray, 0, SIZE - 1);

    std::cout << "QUICK SORTED ARRAY: " << std::endl;
    std::cout << std::endl;
    displayArray(quickArray, SIZE);

    return 0;
}