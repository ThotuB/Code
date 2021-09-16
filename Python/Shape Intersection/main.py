import matplotlib.pyplot as plt
import numpy as np
import csv


class Point:
    def __init__(self, x: float, y: float):
        self.x = x
        self.y = y

    def dist(self, p) -> float:
        return np.sqrt((self.x - p.x) ** 2 + (self.y - p.y) ** 2)

    def __str__(self) -> str:
        return f'({round(self.x, 4)}, {round(self.y, 4)})'


class Line:
    def __init__(self, p1: Point, p2: Point):
        self.p1 = p1
        self.p2 = p2

    def on_segment(self, p: Point) -> bool:
        a = self.p1
        b = self.p2

        return min(b.x, p.x) <= a.x <= max(b.x, p.x) and min(b.y, p.y) <= a.y <= max(b.y, p.y)

    def orientation(self, p: Point) -> int:
        a = self.p1
        b = self.p2

        val = (b.y - a.y) * (p.x - b.x) - (b.x - a.x) * (p.y - b.y)

        if val == 0:
            return 0

        return 1 if val > 0 else -1

    def intersect(self, line) -> Point:
        x1 = self.p1.x
        y1 = self.p1.y
        x2 = self.p2.x
        y2 = self.p2.y

        x3 = line.p1.x
        y3 = line.p1.y
        x4 = line.p2.x
        y4 = line.p2.y

        det_x12 = np.linalg.det(np.array([
            [x1, 1],
            [x2, 1]
        ]))

        det_y12 = np.linalg.det(np.array([
            [y1, 1],
            [y2, 1]
        ]))

        det_x34 = np.linalg.det(np.array([
            [x3, 1],
            [x4, 1]
        ]))

        det_y34 = np.linalg.det(np.array([
            [y3, 1],
            [y4, 1]
        ]))

        det_x12y12 = np.linalg.det(np.array([
            [x1, y1],
            [x2, y2]
        ]))

        det_x34y34 = np.linalg.det(np.array([
            [x3, y3],
            [x4, y4]
        ]))

        # Δ
        det = np.linalg.det(np.array([
            [det_x12, det_y12],
            [det_x34, det_y34]
        ]))

        # Δx
        det_x = np.linalg.det(np.array([
            [det_x12y12, det_x12],
            [det_x34y34, det_x34]
        ]))

        # Δy
        det_y = np.linalg.det(np.array([
            [det_x12y12, det_y12],
            [det_x34y34, det_y34]
        ]))

        return Point(det_x / det, det_y / det)

    def __str__(self) -> str:
        return f'{self.p1} - {self.p2}'


class Triangle:
    def __init__(self, c: Point, r: int):
        self.center = c
        self.radius = r

        self.points = []
        self.generate_points()

    def generate_points(self):
        for i in range(3):
            x = self.center.x + self.radius * np.cos(2 * np.pi * i / 3)
            y = self.center.y + self.radius * np.sin(2 * np.pi * i / 3)

            self.points += [Point(x, y)]

    def get_intersect_distances(self) -> list:
        radians = []
        distances = []

        lines = [Line(self.points[i], self.points[(i + 1) % 3]) for i in range(3)]
        for deg in range(0, 121, 1):
            line1 = lines[deg // 120]
            rad = np.radians(deg)

            x = self.center.x + self.radius * np.cos(rad)
            y = self.center.y + self.radius * np.sin(rad)
            line2 = Line(self.center, Point(x, y))

            p = line1.intersect(line2)
            dist = self.center.dist(p)

            radians += [rad]
            distances += [dist]

        return [radians, distances]

    def calc_intersect_distances(self) -> list:
        radians = []
        distances = []

        a = self.radius * (1 / np.tan(np.pi / 3))

        for deg in range(0, 121, 1):
            rad = np.radians(deg)
            dist = a * np.cosh(rad / a)

            radians += [rad]
            distances += [dist]

        return [radians, distances]

    def __str__(self) -> str:
        output = f'C: {self.center}, r: {self.radius}'
        char = 'A'
        for p in self.points:
            output += f'\n{char}: {p}'
            char = chr(ord(char) + 1)
        return output


if __name__ == '__main__':
    t = Triangle(Point(0, 0), 1)
    [rads1, dists1] = t.get_intersect_distances()
    [rads2, dists2] = t.calc_intersect_distances()

    p = Point(1, 1)
    p2 = Point(2, 2)

    print(dists1)
    print(dists2)

    with open('distances.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',')
        writer.writerow(['Radians', 'Distance'])
        for rad, dist in zip(rads1, dists1):
            writer.writerow([rad, dist])
