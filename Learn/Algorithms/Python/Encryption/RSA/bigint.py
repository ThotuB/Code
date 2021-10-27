def big_sqrt(n):
    """
    Return the integer square root of n.
    """
    x = n
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x


def is_prime(n):
    """
    Return True if n is prime.
    """
    if n == 2:
        return True
    if n < 2 or n % 2 == 0:
        return False
    for i in range(3, 1 + big_sqrt(n), 2):
        if n % i == 0:
            return False
    return True


def big_modinv(x, m):
    """
    Return the inverse of x mod n. 
    x - prime
    """
    t, newt = 0, 1
    r, newr = m, x

    while newr != 0:
        quotient = r // newr
        t, newt = newt, t - quotient * newt
        r, newr = newr, r - quotient * newr

    if r > 1:
        return 0

    if t < 0:
       return t + m

    return t

def big_modexp(x, y, m):
    """
    Return x^y mod m.
    """
    result = 1
    while y > 0:
        if y & 1:
            result = (result * x) % m
        y >>= 1
        x = (x * x) % m
    return result