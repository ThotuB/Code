#include <iostream>
#include <string>
#include <unordered_map>

template <typename K, typename V>
void print_map(const std::unordered_map<K, V>& m) {
    for (const auto& p : m) {
        std::cout << p.first << ": " << p.second << '\n';
    }
}

int main() {
    std::unordered_map<std::string, int> m({
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
    });

    print_map(m);

    for (int i = 0 ; i < 32 ; ++i) {
        m[std::to_string(i)] = i;
        std::cout << "Load factor: " << m.load_factor() << "\nSize: " << m.size() << '\n';
    }
}