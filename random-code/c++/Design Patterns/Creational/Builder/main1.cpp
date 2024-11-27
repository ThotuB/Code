#include <iostream>
#include <cstdlib>

class Product {
private:
    int id;
    std::string name;
    std::string description;
    double price;

public:
    Product(int id) {
        this->id = id;
    }

    Product& withName(std::string name) {
        this->name = name;
        return *this;
    }

    Product& withDescription(std::string description) {
        this->description = description;
        return *this;
    }

    Product& withPrice(double price) {
        this->price = price;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Product& product) {
        os << "Product: " << product.id << " " << product.name << " " << product.description << " $" << product.price;
        return os;
    }
};

int main() {
    Product p = Product(53452).withName("Product 1").withDescription("Description 1").withPrice(3.0); 
    std::cout << p << std::endl;
}