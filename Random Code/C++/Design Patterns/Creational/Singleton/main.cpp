#include <iostream>

class Singleton {
private:
    static Singleton *instance;
    int data;
    
    Singleton() {
        data = 0;
    }
    
    Singleton(const Singleton &) = delete;
    
    Singleton &operator=(const Singleton &) = delete;

public:
    static Singleton *getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void doSomething() {
        std::cout << "Singleton::doSomething()" << std::endl;
    }
};