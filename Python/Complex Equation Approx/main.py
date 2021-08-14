def approx_eq_sol(func: function, val: float, decimals: int) -> float:
    sol = 1.0
    for decs in range(0, decimals):
        sub_val = 0
        for dec in range(0, 10):
            dec /= (10 ** (decs + 1))

            x = complex(0, (sol + dec))
            y = func(x)

            if abs(y) < val:
                sub_val = round(x.imag, decs + 1)
            else:
                break

        sol = sub_val

    return sol
        
def func(x):
    return x ** 2 + x

# print('{0} -> {1} + {2}i'.format(round(x.imag, decimals), round(y.real, 5), round(y.imag, 5)))

g = approx_eq_sol(func, 2.0, 5)
print(g)