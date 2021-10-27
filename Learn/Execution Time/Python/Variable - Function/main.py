import sys, os
sys.path += [os.path.abspath(sys.path[0] + '/../~ Decorator')]
from timer import timeit

class Object1:
    def __init__(self):
        self.flag = True
        self.value = 10

@timeit(iter=1_000_000)
def variable_variant():
    object = Object1()

    if object.flag:
        object.flag = False
    else:
        pass

    object.value = 0

class Object2:
    def __init__(self):
        self.value = 10

    def flag(self):
        return self.value == 10

@timeit(iter=1_000_000)
def function_variant():
    object = Object2()

    if object.flag():
        pass
    else:
        pass

    object.value = 0


if __name__ == '__main__':
    variable_variant()
    function_variant()