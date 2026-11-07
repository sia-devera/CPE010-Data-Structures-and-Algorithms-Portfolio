#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>

template <typename T>
class queueArr {
private:
    // Pointer to dynamically allocated array
    T* q_array;
    size_t q_capacity;
    size_t q_size;

    int q_front;
    int q_back;

public:
    // Constructor:
    queueArr(size_t capacity);

    bool Empty();
    size_t Size();
    void Clear();

    T Front();
    T Back();

    void Enqueue (T value);
    void Dequeue ();

    // Copy Constructor:
    queueArr(const queueArr& other);

    // Copy Assignment Constructor:
    queueArr& operator = (const queueArr& other);

    // Destructor:
    ~queueArr();
};

//Constructor:
template <typename T>
queueArr<T>::queueArr(size_t capacity){
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T [q_capacity];
}

template <typename T>
bool queueArr<T>::Empty(){
    return q_size == 0;
}

template <typename T>
size_t queueArr<T>::Size(){
    return q_size;
}

template <typename T>
void queueArr<T>::Clear(){
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

template <typename T>
T queueArr<T>::Front(){
    if(Empty()){
        std::cout << "The queue is empty." << std::endl;
        return T{};
    }
    return q_array[q_front];
}

template <typename T>
T queueArr<T>::Back(){
    if(Empty()){
        std::cout << "The queue is empty." << std::endl;
        return T{};
    }

    return q_array[q_back];
}

template <typename T>
void queueArr<T>::Enqueue(T value){
    // Check if the value is full
    if (q_size == q_capacity) {
        std::cout << "Queue is full! Cannot enqueue " << value << std::endl;
        return;
    }

    // Compute for the q_back for circular (use the modulo operator)
    q_back = (q_back + 1) % q_capacity;

    // Assign the q_array with the updated q_back to the value
    q_array[q_back] = value;

    // Increment the q_size
    q_size++;
}

template <typename T>
void queueArr<T>::Dequeue(){
    // Check if it is empty
    if(Empty()){
        std::cout << "The queue is empty!" << std::endl;
        return;
    }

    // Move q_front circularly
    q_front = (q_front + 1) % q_capacity;

    // Decrement
    q_size--;
    
    // Reset index when queue becomes empty
    if(Empty()){
        Clear();
        return;
    }
}

// Deconstructor
template <typename T>
queueArr<T>::~queueArr(){
    delete[] q_array;
}

#endif