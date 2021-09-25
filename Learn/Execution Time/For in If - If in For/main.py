from timer import timeit

@timeit(iter=100_000)
def for_in_if():
    for x in range(10):
        if x % 2 == 0:
            for _ in range(100):
                pass
        else:
            for _ in range(100):
                pass

@timeit(iter=100_000)
def if_in_for():
    for x in range(10):
        for _ in range(100):
            if x % 2 == 0:
                pass
            else:
                pass

if __name__ == '__main__':
    for_in_if()
    if_in_for()
    