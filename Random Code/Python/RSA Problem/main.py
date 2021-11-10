def mod_inv(x, n):
    t, newt = 0, 1
    r, newr = n, x

    while newr != 0:
        quotient = r // newr
        t, newt = newt, t - quotient * newt
        r, newr = newr, r - quotient * newr

    if r > 1:
        return 0

    if t < 0:
       return t + n

    return t

def test_factors(p, q):
    n = p * q

    print(f'n: {n}  p + q: {p+q}')

    for x in range(1, n):
        x_inv = mod_inv(x, n)
        y = x ** (p + q)

        print(f'{x}, {x_inv} -> {y%n}')
        if x == n // 2:
            print("--------------")

if __name__ == '__main__':
    test_factors(7, 5)
