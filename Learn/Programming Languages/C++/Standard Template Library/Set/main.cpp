#include <iostream>
#include <set>

template <typename T>
void print_set(const std::set<T>& s) {
    for (const auto& e : s) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::set<int> test_set({1, 2, 2, 4, 3, 5, 7});

    print_set(test_set);

    test_set.erase(2);
    test_set.insert(6);

    print_set(test_set);

    std::cout << "Count: " << test_set.count(2) << '\n';
    std::cout << "Count: " << test_set.count(6) << '\n';

    return 0;
}