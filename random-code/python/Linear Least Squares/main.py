import plotly.express as px
import numpy as np
from functions import *

def calculate_error(xs, ys, func):
    error = 0
    for x, y in zip(xs, ys):
        error += (y - func(x))**2
    return error


if __name__ == "__main__":
    xs = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    ys = [4, 2, 2, 6, 4, 9, 11, 8, 9]

    lin = Linear(1, 3)
    error = calculate_error(xs, ys, lin.func)
    
    print(error)