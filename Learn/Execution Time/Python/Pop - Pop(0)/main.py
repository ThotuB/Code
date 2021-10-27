import sys, os
sys.path.insert(0, os.path.abspath(sys.path[0] + '\\..\\~ Decorator'))
from timer import timeit

@timeit(iter=1)
def stack_back_operations(elems):
    stack = []
    for _ in range(elems):
        stack += [0]
    for _ in range(elems):
        stack.pop()


@timeit(iter=1)
def stack_front_operations(elems):
    stack = []
    for _ in range(elems):
        stack += [0]
    for _ in range(elems):
        stack.pop(0)


if __name__ == '__main__':
    stack_back_operations(20000)
    stack_front_operations(20000)