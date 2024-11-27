#include <iostream>
#include <cmath>

class EquilateralTriangle {
public:
    EquilateralTriangle(int side1) : side1(side1) {}
    
    virtual double getArea() {
        return sqrt(3) / 4 * side1 * side1;
    }

    virtual int getPerimeter() {
        return 3 * side1;
    }

protected:
    int side1;
};

class IsoscelesTriangle : public EquilateralTriangle {
public:
    IsoscelesTriangle(int side1, int side2) : EquilateralTriangle(side1), side2(side2) {}
    
    virtual double getArea() override {
        
    }

    virtual int getPerimeter() override {
        return 2 * side1 + side2;
    }

protected:
    int side2;
};

class Triangle : public IsoscelesTriangle {
public:
    Triangle(int side1, int side2, int side3) : IsoscelesTriangle(side1, side2), side3(side3) {}
    
    double getArea() final {
        const double p = (side1 + side2 + side3) / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }

    int getPerimeter() final {
        return side1 + side2 + side3;
    }

protected:
    int side3;
};

void display(EquilateralTriangle* t) {
    std::cout << "Area: " << t->getArea() << std::endl;
    std::cout << "Perimeter: " << t->getPerimeter() << std::endl;
}

int main() {
    EquilateralTriangle eq(5);
    IsoscelesTriangle is(5, 6);
    Triangle tr(5, 6, 7);

    display(&eq);
    display(&is);
    display(&tr);
}