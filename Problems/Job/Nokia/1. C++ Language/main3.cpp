#include <iostream>
#include <cmath>

class Shape {
public:
    virtual void display() = 0;
    virtual double getArea() = 0;
    virtual int getPerimeter() = 0;
};

class Triangle : public Shape {
public:
    Triangle(int side1, int side2, int side3) : side1(side1), side2(side2), side3(side3) {}
    
    void display() override {
        std::cout << "Area: " << getArea() << std::endl;
        std::cout << "Perimeter: " << getPerimeter() << std::endl;
    }
    
    double getArea() override {
        const double p = (side1 + side2 + side3) / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }
    
    int getPerimeter() override {
        return side1 + side2 + side3;
    }

private:
    int side1;
    int side2;
    int side3;
};

class Square : public Shape {
public:
    Square(int side) : side(side) {}
    
    void display() override {
        std::cout << "Area: " << getArea() << std::endl;
        std::cout << "Perimeter: " << getPerimeter() << std::endl;
    }
    
    double getArea() override {
        return side * side;
    }
    
    int getPerimeter() override {
        return 4 * side;
    }

private:
    int side;
};

class Hexagon : public Shape {
public:
    Hexagon(int side) : side(side) {}
    
    void display() override {
        std::cout << "Area: " << getArea() << std::endl;
        std::cout << "Perimeter: " << getPerimeter() << std::endl;
    }
    
    double getArea() override {
        return (3 * sqrt(3) / 2) * side * side;
    }
    
    int getPerimeter() override {
        return 6 * side;
    }

private:
    int side;
};

int main() {
    Triangle tr(5, 6, 7);
    Square sq(5);
    Hexagon hex(5);

    tr.display();
    sq.display();
    hex.display();
}