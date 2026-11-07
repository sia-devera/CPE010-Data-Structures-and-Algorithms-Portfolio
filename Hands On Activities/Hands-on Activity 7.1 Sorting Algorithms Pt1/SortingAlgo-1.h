#ifndef SORTINGALGO_H
#define SORTINGALGO_H
#include <iostream>

template <typename T>
void BubSorting(T arr[], int MaxSize) {

    for (int i = 0; i < MaxSize - 1; i++) {
        for (int j = 0; j < MaxSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int routineSmallest(T arr[], int K, int MaxSize) {

    int position;
    T smallElem = arr[K];

    position = K;

    for (int j = K + 1; j < MaxSize; j++) {
        if (arr[j] < smallElem) {
            smallElem = arr[j];
            position = j;
        }
    }
    return position;
}


template <typename T>
void SelSort(T arr[], int MaxSize) {

    int POS;
    for (int i = 0; i < MaxSize; i++) {
        POS = routineSmallest(arr, i, MaxSize);
        std::swap(arr[i], arr[POS]);
    }
}

template<typename T>
void InsSort(T arr[], int MaxSize){
    int K, j, temp;

    while(K < MaxSize){
        temp = arr[K];
        j = K-1;

        while(temp <= arr[j]){
            arr[j+1] = temp;
            j--;
        }
    arr[j+1] = temp;
    K++;
    }
}

#endif