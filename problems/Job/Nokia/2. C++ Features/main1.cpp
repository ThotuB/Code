#include <chrono>
#include <iostream>

unsigned constexpr fibonacciConstExpr(unsigned n) {
    return n <= 1 ? n : fibonacciConstExpr(n - 1) + fibonacciConstExpr(n - 2);
}

unsigned fibonacci(unsigned n) {
    return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    auto tic = std::chrono::high_resolution_clock::now();
    std::cout << fibonacci(45) << std::endl;
    auto toc = std::chrono::high_resolution_clock::now();

    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(toc - tic).count() << " ms" << std::endl;
}