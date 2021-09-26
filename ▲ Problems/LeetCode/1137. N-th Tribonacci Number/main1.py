# Tribonacci - dynamic programming

def tribonacci(n: int) -> int:
    trib = [0, 1, 1]

    i = 3
    while i <= n:
        trib.append(trib[i - 1] + trib[i - 2] + trib[i - 3])
        i += 1
    
    return trib[n]


if __name__ == "__main__":
    print(tribonacci(25))