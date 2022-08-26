#include <iostream>
#include <map>

int main() {
    std::map<char, int> test_map({{'a', 1}, {'b', 2}, {'c', 3}});
    
    std::cout << "Map: " << test_map['a'] << '\n';
    
    test_map['a'] = 5;
    
    std::cout << "Map: " << test_map['a'] << '\n';
    
    test_map['d'] = 4;

    std::cout << "Map: " << test_map['d'] << '\n';

    return 0;
}