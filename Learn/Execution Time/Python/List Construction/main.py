import sys, os
sys.path.insert(0, os.path.abspath(sys.path[0] + '\\..\\~ Decorator'))
from timer import timeit

@timeit(iter=1)
def list_comprehension(n):
    list = [0 for _ in range(n)]


@timeit(iter=1)
def list_multiplication(n):
    list = [0] * n


@timeit(iter=1)
def list_append(n):
    list = []
    for _ in range(n):
        list.append(0)


@timeit(iter=1)
def list_extend(n):
    list = []
    for _ in range(n):
        list.extend([0])


@timeit(iter=1)
def list_insert(n):
    list = []
    for i in range(n):
        list.insert(i, 0)


if __name__ == '__main__':
    n = 10000000
    list_comprehension(n)
    list_multiplication(n)
    list_append(n)
    list_extend(n)
    list_insert(n)