#include <iostream>
#include <vector>
#include "PathCount.h"

int main() {
    std::vector<std::vector<int>> matrix = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int targetCost = 25;

    int m = matrix.size();
    int n = matrix[0].size();

    std::cout << "Number of paths with cost " << targetCost << ": " << countPaths(matrix, m - 1, n - 1, targetCost) << std::endl;
    std::cout << std::endl;

    return 0;
}
