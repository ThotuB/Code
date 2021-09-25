from math import comb

def climbStairs(n: int) -> int:
    max_twos = n // 2

    ways = 0
    for twos in range(0, max_twos + 1):
        ways += comb(n - twos, twos)
    
    return ways


if __name__ == "__main__":
    print(climbStairs(24))