factorial = {
    0: 1,
    1: 1,
    2: 2,
    3: 6,
    4: 24,
    5: 120,
    6: 720,
    7: 5040,
    8: 40320,
    9: 362880
}

def sum_of(num, fn):
    sum = 0
    while num > 0:
        sum += fn(num % 10)
        num //= 10
    return sum


# sum of factorials of digits
def f(n):
    return sum_of(n, lambda x: factorial[x])


# sum of digits of f(n)
def sf(n):
    n = f(n)
    return sum_of(n, lambda x: x)


# smallest n such that sf(n) = i
def g(i):
    n = 1
    while True:
        if sf(n) == i:
            return n
        n += 1


# sum of digits of g(i)
def sg(i):
    i = g(i)
    return sum_of(i, lambda x: x)


def eps_sg(n):
    sum = 0
    for i in range(1, n + 1):
        sum += sg(i)
    return sum

if __name__ == '__main__':
    n = 500
    m = 1000000

    i = 54
    
    # print(f'{i}: {g(i)}')
    print(f'{i}: {f(12378889)}')

    