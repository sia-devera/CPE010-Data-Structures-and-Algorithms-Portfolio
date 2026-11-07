#ifndef SMQ_h
#define SMQ_h

template <typename T>
class SortingAlgorithms{
    private:
        // Merge two sorted portions of the array
        void merge(T array[], int left, int middle, int right);
        // Pivot the array for Quick Sort
        int pivot(T array[], int low, int high);
    public:
        // Shell Sort
        void shellSort(T array[], int size);
        // Merge Sort
        void mergeSort(T array[], int left, int right);
        // Quick Sort
        void quickSort(T array[], int low, int high);
};


// Shell Sort
template <typename T>
void SortingAlgorithms<T>::shellSort(T array[], int size){
    for (int interval = size / 2; interval > 0; interval /= 2){
        for (int i = interval; i < size; i++){
            T temp = array[i];
            int j = i;

            while (j >= interval && array[j - interval] > temp){
                array[j] = array[j - interval];
                j = j - interval;
            }
            array[j] = temp;
        }
    }
}


// Merge Sort - Merge Function
template <typename T>
void SortingAlgorithms<T>::merge(T array[], int left, int middle, int right){
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    T* leftArray = new T[leftSize];
    T* rightArray = new T[rightSize];

    for (int i = 0; i < leftSize; i++){
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < rightSize; j++){
        rightArray[j] = array[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize){
        if (leftArray[i] <= rightArray[j]){
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize){
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize){
        array[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}


// Merge Sort
template <typename T>
void SortingAlgorithms<T>::mergeSort(T array[], int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}


// Quick Sort - Pivot Function
template <typename T>
int SortingAlgorithms<T>::pivot(T array[], int low, int high){
    T pivot = array[high];

    int i = low - 1;

    for (int j = low; j < high; j++){
        if (array[j] < pivot){
            i++;

            T temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    T temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}


// Quick Sort
template <typename T>
void SortingAlgorithms<T>::quickSort(T array[], int low, int high){
    if (low < high){
        int pivotIndex = pivot(array, low, high);

        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

#endif