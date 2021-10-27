from random import uniform, random
from math import cos, sin, sqrt, pi
import plotly.express as px

def rejection_sampling():
    while True:
        x = uniform(-1, 1)
        y = uniform(-1, 1)
        if x**2 + y**2 <= 1:
            return x, y


def polar_sqrt_dist():
    theta = uniform(0, 2 * pi)
    r = sqrt(random())
    return r * cos(theta), r * sin(theta)


def polar_sum_dist():
    theta = uniform(0, 2 * pi)
    r = random() + random()
    if r > 1:
        r = 2 - r
    return r * cos(theta), r * sin(theta)


def polar_max_dist():
    theta = uniform(0, 2 * pi)
    r = max(random(), random())
    return r * cos(theta), r * sin(theta)


def get_points(n, func):
    xs = []
    ys = []
    for _ in range(n):
        x, y = func()
        xs.append(x)
        ys.append(y)
    return xs, ys

if __name__ == "__main__":
    xs, ys = get_points(10000, polar_sqrt_dist)
    fig = px.scatter(x=xs, y=ys, labels={"x": "x", "y": "y"})
    fig.show()