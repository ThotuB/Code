#include <iostream>

class Product {
private:
    int id;
    std::string name;
    std::string description;
    double price;

public:
    struct Options {
        std::string name = "";
        std::string description = "";
        double price = 0.0;
    };

    Product(int id, Options options) {
        this->id = id;
        this->name = options.name;
        this->description = options.description;
        this->price = options.price;
    }

    friend std::ostream& operator<<(std::ostream& os, const Product& product) {
        os << "Product: " << product.id << " " << product.name << " " << product.description << " $" << product.price;
        return os;
    }
};

int main() {
    Product p = Product(425, Product::Options{
        .name = "Product 2",
        .description = "Description 2",
        .price = 5.0
    }); 
    std::cout << p << std::endl;
}