from timer import timeit

@timeit()
def append_function(iter=100_000):
    lst = []
    for i in range(iter):
        lst.append(i)

@timeit()
def insert_function(iter=100_000):
    lst = []
    for i in range(iter):
        lst.insert(0, i)

@timeit()
def append_operator(iter=100_000):
    lst = []
    for i in range(iter):
        lst += [i]

@timeit()
def insert_operator(iter=100_000):
    lst = []
    for i in range(iter):
        lst = [i] + lst

if __name__ == '__main__':
    append_function()
    insert_function()
    append_operator()
    insert_operator()
    