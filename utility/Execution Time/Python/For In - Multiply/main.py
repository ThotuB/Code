import sys, os
sys.path += [os.path.abspath(sys.path[0] + '/../~ Decorator')]
from timer import timeit

@timeit()
def for_in(iter=100_000_000):
    [None for _ in range(iter)]

@timeit()
def multiply(iter=100_000_000):
    [None] * iter

if __name__ == '__main__':
    for_in()
    multiply()
    