from hashlib import sha256
from bigint import *

# Modulus - n

# 1st Prime Factor - p
# 2nd Prime Factor - q

# Public Exponent - e
# Private Exponent - d

# Public Key - (e, n)
# Private Key - (d, n)

def generate_keys(p, q):
    """
    Generates RSA keys for given p and q.
    """
    n = p * q
    phi = (p - 1) * (q - 1)

    e = 3
    d = big_modinv(e, phi) # d = e^-1 mod phi

    return (e, d, n)


def encrypt(m, e, n):
    """
    Encrypts a message m using the public key (e, n)\n
    c = m ^ e mod n
    """
    return big_modexp(m, e, n)


def decrypt(c, d, n, p=None, q=None):
    """
    Decrypts a ciphertext c using the private key (d, n)\n
    m = c ^ d mod n
    """
    if p is None or q is None:
        return big_modexp(c, d, n)

    dp = d % (p - 1)
    dq = d % (q - 1)
        
    m1 = big_modexp(c, dp, p)
    m2 = big_modexp(c, dq, q)

    return (m1 * q * big_modinv(q, p) + m2 * p * big_modinv(p, q)) % n
    

def sign(m, d, n, p=None, q=None):
    """
    Signs a message m using the private key (d, n)\n
    s = Hash(m) ^ d mod n
    """
    h = sha256(m.encode()).digest()
    h = int.from_bytes(h, 'big')

    if p is None or q is None:
        return big_modexp(h, d, n)

    dp = d % (p - 1)
    dq = d % (q - 1)

    s1 = big_modexp(h, dp, p)
    s2 = big_modexp(h, dq, q)

    return (s1 * q * big_modinv(q, p) + s2 * p * big_modinv(p, q)) % n


def verify(m, s, e, n):
    """
    Verifies a message m using the public key (e, n) and a signature s\n
    Hash(m) = s ^ e mod n
    """
    h = sha256(m.encode()).digest()
    h = int.from_bytes(h, 'big')
    return big_modexp(s, e, n) == h