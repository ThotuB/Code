#include <iostream>

// max of parameters
template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

template <typename T, typename... Args>
T max(T a, T b, Args... args) {
    return a > b ? max(a, args...) : max(b, args...);
}

// sum of squares of parameters
template <typename T, typename... Args>
T sum_of_squares(T a) {
    return a * a;
}

template <typename T, typename... Args>
T sum_of_squares(T a, Args... args) {
    return a * a + sum_of_squares(args...);
}

// test values
template <typename T>
bool test(T a, T b) {
    return a < b;
}


template <typename T, typename... Args>
bool test(T a, T b, Args... args) {
    if (test(a, b)) {
        return test(args...);
    }
    return false;
}

int main() {
    std::cout << max(1, 2, 3, 4, 5) << std::endl;
    std::cout << sum_of_squares(1, 2, 3, 4, 5) << std::endl;
    std::cout << test(4, 5, 7, 9, 2, 4) << std::endl;
    std::cout << test(6, 9, 8, 2) << std::endl;
    std::cout << test(4.6, 5.8, 7, 8, 'a', 'e') << std::endl;
}