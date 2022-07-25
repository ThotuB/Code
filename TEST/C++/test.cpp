#include <iostream>
#include <vector>

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

int main() {
    std::vector<A*> vec;
    vec.push_back(new A());
    vec.push_back(new A());
    vec.push_back(new B());

    for (auto elem : vec) {
        elem->method();
    }

    vec.clear();
}