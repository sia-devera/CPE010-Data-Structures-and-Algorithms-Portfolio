#ifndef SORTINGALGO_H
#define SORTINGALGO_H

template <typename T>
void SelSort(T arr[], int MaxSize) {

    int POS;
    for (int i = 0; i < MaxSize; i++) {
        POS = routineSmallest(arr, i, MaxSize);
        std::swap(arr[i], arr[POS]);
    }
}

#endif