# Tribonacci - dynamic programming

def tribonacci(n: int) -> int:
    tribs = [0, 1, 1]

    i = 3
    while i <= n:
        temp = tribs[0] + tribs[1] + tribs[2]
        tribs[0] = tribs[1]
        tribs[1] = tribs[2]
        tribs[2] = temp

        i += 1
        
    return tribs[n if n < 3 else 2]


if __name__ == "__main__":
    print(tribonacci(25))