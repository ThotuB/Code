from timer import timeit

@timeit(iter=10_000_000)
def power_operator(power):
    return 2 ** power

@timeit(iter=10_000_000)
def multiplication_2():
    return 2 * 2

@timeit(iter=10_000_000)
def multiplication_15_slow():
    return 2*2*2*2*2 * 2*2*2*2*2 * 2*2*2*2*2

@timeit(iter=10_000_000)
def multiplication_15_moderate():
    x2 = 2*2
    x4 = x2*x2
    x8 = x4*x4
    return x8*x4*x2*2

@timeit(iter=10_000_000)
def multiplication_15_fast():
    x2 = 2*2
    x3 = x2*2
    x6 = x3*x3
    x12 = x6*x6
    return x12*x3


if __name__ == '__main__':
    power_operator(2)
    multiplication_2()
    power_operator(15)
    multiplication_15_slow()
    multiplication_15_moderate()
    multiplication_15_fast()
    