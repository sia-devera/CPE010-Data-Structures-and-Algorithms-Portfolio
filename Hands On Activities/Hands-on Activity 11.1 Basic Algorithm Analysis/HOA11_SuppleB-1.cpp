#include <iostream>
#include <chrono>

long long rpower(int x, int n) {
    if (n == 0)
        return 1;
    else
        return x * rpower(x, n - 1);
}

long long brpower(int x, int n) {
    if (n == 0)
        return 1;

    if (n % 2 != 0) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }

    long long y = brpower(x, n / 2);
    return y * y;
}

void test_rpower(int x, int n) {

    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();

    long long result = rpower(x, n);

    std::chrono::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    std::cout << "rpower" << std::endl;
    std::cout << "Input Size (N): " << n << std::endl;
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>  (end - begin).count() << " microseconds" << std::endl;

    std::cout << std::endl;
}

void test_brpower(int x, int n) {

    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();

    long long result = brpower(x, n);

    std::chrono::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    std::cout << "brpower" << std::endl;
    std::cout << "Input Size (N): " << n << std::endl;
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << " microseconds" << std::endl;

    std::cout << std::endl;
}

int main() {

    test_rpower(2, 100000);

    test_brpower(2, 100000);

    return 0;
}
