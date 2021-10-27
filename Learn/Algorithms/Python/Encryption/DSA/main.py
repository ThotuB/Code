from hashlib import sha256
from bigint import *


def key_generation(p, q):
    """
    Generate DSA keys for given p and q.
    """
    g = 