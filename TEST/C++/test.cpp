#include <iostream>
#include <vector>

using namespace std;

class A {
public:
    virtual void method() {
        std::cout << "Hello\n";
    }

    virtual ~A() = default;
};

class B : public A {
public:
    void method() override {
        std::cout << "Hi\n";
    }

    virtual ~B() = default;
};

bool is_palindrome(std::string input) {
    int size = input.length();
    for (int i = 0; i < size / 2 ; i++) {
        if (input[i] != input[size-i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void print_vector(std::vector<T>& vec) {
    for (auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main(char argc, char** argv) {
    std::vector<const A*> vec;

    A* a = new A();
    vec.push_back(a);
}