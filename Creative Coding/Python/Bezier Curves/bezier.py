class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)
    
    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)
    
    def __mul__(self, other):
        return Point(self.x * other, self.y * other)
    
    def __rmul__(self, other):
        return Point(self.x * other, self.y * other)
    
    def __str__(self):
        return f'({self.x}, {self.y})'

class Bezier:
    def __init__(self, p1: Point, p2: Point, p3: Point, p4: Point):
        self.pts = [p1, p2, p3, p4]
        self.center = Point(0, 0)

    def lerp(self, t):
        w1 =   -t^3 + 3*t^2 - 3*t + 1
        w2 =  3*t^3 - 6*t^2 + 3*t
        w3 = -3*t^3 + 3*t^2
        w4 =    t^3



