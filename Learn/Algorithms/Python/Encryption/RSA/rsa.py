from hashlib import sha256
from bigint import *

# Modulus - n

# 1st Prime Factor - p
# 2nd Prime Factor - q

# Public Exponent - e
# Private Exponent - d

# Public Key - (e, n)
# Private Key - (d, n)

class RSA:
    def __init__(self, p, q):
        self.p = p
        self.q = q

        self.n = p * q
        self.phi = (p - 1) * (q - 1)

        self.e = 65537

        self.d = big_modinv(self.e, self.phi)
        self.dp = self.d % (p - 1)
        self.dq = self.d % (q - 1)
        
        self.q_inv = big_modinv(q, p)
        self.p_inv = big_modinv(p, q)


    @property
    def public_key(self):
        return (self.e, self.n)


    @property
    def private_key(self):
        return (self.d, self.n)


    def encrypt(self, message):
        return big_modexp(message, self.e, self.n)


    def decrypt(self, cipher):
        m1 = big_modexp(cipher, self.dp, self.p)
        m2 = big_modexp(cipher, self.dq, self.q)

        return (m1 * self.q * self.q_inv + m2 * self.p * self.p_inv) % self.n
        

    def sign(self, message):
        h = sha256(message.encode()).digest()
        h = int.from_bytes(h, 'big')

        s1 = big_modexp(h, self.dp, self.p)
        s2 = big_modexp(h, self.dq, self.q)

        return (s1 * self.q * self.q_inv + s2 * self.p * self.p_inv) % self.n
    
    
    def verify(self, message, signature):
        h = sha256(message.encode()).digest()
        h = int.from_bytes(h, 'big')

        return big_modexp(signature, self.e, self.n) == h


def encrypt(message, key):
    e = key[0]
    n = key[1]

    return big_modexp(message, e, n)


def verify(message, signature, key):
    e = key[0]
    n = key[1]

    h = sha256(message.encode()).digest()
    h = int.from_bytes(h, 'big')

    return big_modexp(signature, e, n) == h