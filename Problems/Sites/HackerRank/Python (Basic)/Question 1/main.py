from math import pi

class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height


class Circle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return pi * self.radius ** 2


if __name__ == '__main__':
    rect = Rectangle(3, 5)
    print(f'{rect.area():.6f}')

    circ = Circle(6)
    print(f'{circ.area():.6f}')