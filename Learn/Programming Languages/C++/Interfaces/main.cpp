#include <iostream>
#include <string>
#include <vector>

class Callable {
public:
    virtual int call() = 0;

    Callable(std::vector<int> params) :
        params(params)
    {}

    virtual ~Callable() {
        std::cout << "~Callable()" << std::endl;
    }

protected:
    std::vector<int> params;
};

class Sum : public Callable {
public:
    int call() override {
        int sum = 0;
        for (int param : params) {
            sum += param;
        }
        return sum;
    }

    Sum(std::vector<int> params) :
        Callable(params)
    {}

    ~Sum() override {
        std::cout << "~Sum()" << std::endl;
    }
};

class Product : public Callable {
public:
    int call() override {
        int product = 1;
        for (int param : params) {
            product *= param;
        }
        return product;
    }

    Product(std::vector<int> params) :
        Callable(params)
    {}

    ~Product() override {
        std::cout << "~Product()" << std::endl;
    }
};

void print_result(Callable* callable) {
    std::cout << callable->call() << std::endl;
}

void call_function(std::string funcName, std::vector<int> params) {
    Callable *callable = nullptr;
    if (funcName == "sum") {
        callable = new Sum(params);
    } else if (funcName == "product") {
        callable = new Product(params);
    }
    
    if (callable == nullptr) {
        std::cout << "Invalid function name" << std::endl;
        return;
    }

    print_result(callable);
    delete callable;
}

int main() {
    std::vector<int> params = {1, 2, 3, 4, 5};

    call_function("sum", params);
    call_function("product", params);
    call_function("invalid", params);

    return 0;
}