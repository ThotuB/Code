from timer import timeit

@timeit(iter=100_000)
def sum_function():
    elems = list(range(1000))
    sum_elems = sum(elems)

    return sum_elems    


@timeit(iter=100_000)
def sum_in_for():
    elems = list(range(1000))
    sum_elems = 0
    for elem in elems:
        sum_elems += elem

    return sum_elems

if __name__ == '__main__':
    sum_function()
    sum_in_for()
    