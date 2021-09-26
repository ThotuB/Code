from timer import timeit

@timeit()
def length_variable(iter=10_000_000):
    lst = list(range(iter))
    length = len(lst)
    for _ in range(length):
        pass

@timeit()
def len_function(iter=10_000_000):
    lst = list(range(iter))
    for _ in range(len(lst)):
        pass

if __name__ == '__main__':
    length_variable()
    len_function()
    