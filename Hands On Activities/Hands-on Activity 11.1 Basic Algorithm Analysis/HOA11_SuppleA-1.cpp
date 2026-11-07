#include <iostream>
#include <vector>
#include <chrono>

bool Unique(std::vector<int>& A) {
    int n = A.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j])
                return false;
        }
    }

    return true;
}

void test(int size) {
    std::vector<int> A(size);

    // Create an array with unique elements
    for (int i = 0; i < size; i++)
        A[i] = i;

    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();

    bool result = Unique(A);

    std::chrono::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    std::cout << "Input Size (N): " << size << std::endl;
    std::cout << "Time taken: "<< std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << " milliseconds" << std::endl;

    if (result)
        std::cout << "All elements are unique." << std::endl;
    else
        std::cout << "Duplicate elements found." << std::endl;

    std::cout << std::endl;
}

int main() {

    test(1000);
    test(10000);
    test(100000);

    return 0;
}
