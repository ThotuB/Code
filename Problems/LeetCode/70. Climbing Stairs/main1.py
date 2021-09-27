def climbStairs(n: int) -> int:
    steps = [0, 1]

    for i in range(2, n + 2):
        steps.append(steps[i - 1] + steps[i - 2])

    return steps[n + 1]

if __name__ == "__main__":
    print(climbStairs(7))