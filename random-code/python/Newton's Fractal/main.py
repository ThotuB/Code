from polynomial import Poly
import plotly.express as px
import numpy as np


def newton_approx(poly: Poly, x: complex, n: int) -> float:
    if n == 0:
        return x
        
    x_next = x - (poly(x))/((poly>>1)(x))

    return newton_approx(poly, x_next, n-1)


def distance(x: complex, y: complex) -> float:
    return abs(x-y)


def newton_fractal_colors(poly: Poly, roots: list[complex], resolution: int, scale: int):
    coord_min = -scale
    coord_max = scale
    step = (coord_max - coord_min)/resolution

    plot_range = list(np.arange(coord_min, coord_max, step))


    clrs = [0] * resolution * resolution
    for i, y in enumerate(plot_range):
        for j, x in enumerate(plot_range):
            z = x + y*1j
            z_approx = newton_approx(poly, z, 10)

            index = i * resolution + j
            min = float('inf')
            for (i, root) in enumerate(roots):
                if distance(z_approx, root) < min:
                    min = distance(z_approx, root)
                    clrs[index] = i

    xs = [i for i in plot_range for _ in plot_range]
    ys = [i for _ in plot_range for i in plot_range]

    return xs, ys, clrs

if __name__ == '__main__':
    resolution = 100
    roots = [
        1+0j, 
        -0.5 + 0.86602540378j,
        -0.5 - 0.86602540378j
    ]
    poly = Poly(roots, mode='root')

    xs, ys, clrs = newton_fractal_colors(poly, roots, resolution, 2)

    fig = px.scatter(x=xs, y=ys, color=clrs)
    fig.show()
