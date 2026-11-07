#include <iostream>
#include <vector>
#include "Memoization.h"

int main() {

// Memoization Main File
    int n;

    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> memo(n + 1, -1);

    int result = getMinSteps(n, memo);

    std::cout << "Minimum steps to 1: " << result << std::endl;

    return 0;
}
