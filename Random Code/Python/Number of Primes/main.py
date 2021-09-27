import matplotlib.pyplot as plt
import math

def Is_Prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    i = 3
    while i ** 2 <= n:
        if n % i == 0:
            return False
        i += 2
    return True

def Graph_Nr_Of_Primes(n):
    x = []
    y = []
    y_approx1 = []
    y_approx2 = []

    nr_primes = 0
    for i in range(2, n):
        if Is_Prime(i):
            nr_primes += 1

        x.append(i)

        y.append(nr_primes)
        # y_approx1.append(i/10)
        y_approx2.append(i/math.log(i))

    plt.plot(x, y, 'r-', label='Actual')
    # plt.plot(x, y_approx1, 'b-', label='x/10')
    plt.plot(x, y_approx2, 'g-', label='x/log(x)')
    plt.show()


if __name__ == "__main__":
    Graph_Nr_Of_Primes(10000)

