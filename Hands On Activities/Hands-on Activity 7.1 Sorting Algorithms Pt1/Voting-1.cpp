#include <iostream>
#include <cstdlib>
#include "SortingAlgo.h"

const int MaxSize = 100;

int main() {

    int arr[MaxSize];
    int count[5] = {0};

    std::cout << "[CITIZEN'S VOTE]" << std::endl;

    for (int i = 0; i < MaxSize; i++) {
        arr[i] = rand() % 5 + 1;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Grouping the Votes accordingly:" << std::endl;
    std::cout << std::endl;
    std::cout << "                  p r o c e s s i n g . . ." << std::endl;
    std::cout << std::endl;

    // selsort
    SelSort (arr, MaxSize);
        for (int i = 0; i < MaxSize; i++) {
    std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    //countng
    std::string candidates [5] = {"Bo Dalton Capistrano", "Cornelius Raymon Agustin", 
        "Deja Jayla Bañaga", "Lalla Brielle Yabut", "Franklin Relano Castro"};

    for (int i = 0; i < MaxSize; i++) {
        count[arr[i] - 1]++;
    }

    std::cout << "[FINALIZING VOTE COUNT]" << std::endl;

    for (int i = 0; i < 5; i++) {
    std::cout << "CAND. #" << i + 1 << ": " << candidates[i] << " has " << count[i] << " votes." << std::endl;
}
    // anouncing
    int winCand = 0;

    for (int i = 1; i < 5; i++) {
        if (count[i] > count[winCand]) {
            winCand = i;
        }
    }

    std::cout << std::endl;
    std::cout << "Congratulations! " << candidates[winCand] << ", you're the winner!" << std::endl;
    std::cout << "Total Votes accumulated: " << count[winCand] << " votes." << std::endl;

    return 0;
}