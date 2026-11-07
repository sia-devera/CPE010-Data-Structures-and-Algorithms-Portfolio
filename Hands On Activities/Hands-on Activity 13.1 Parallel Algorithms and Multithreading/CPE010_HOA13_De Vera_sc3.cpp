#include <iostream>
#include <thread>
#include <mutex>

int total = 0;
std::mutex mtx;

void add(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    total = total + value;
}

void display() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << total << std::endl;
}

int main() {
    std::cout << "Original Value: ";
    display();

    std::thread T1(add, 25);
    T1.join();

    std::cout << "After adding first value [T1.join()]: ";
    display();

    std::thread T2(add, 70);
    T2.join();

    std::cout << "After adding second value [T2.join()]: ";
    display();

    std::thread T3(add, 1000);
    T3.join();

    std::cout << "After adding the last value [T3.join()]: ";
    display();

    return 0;
}
