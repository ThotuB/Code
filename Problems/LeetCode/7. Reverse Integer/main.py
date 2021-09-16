def reverse(x: int) -> int:
    if x < 0:
        return -reverse(-x)

    result = 0
    while x > 0:
        result = result * 10 + x % 10
        x //= 10

    return result


if __name__ == "__main__":
    print(reverse(123))
    print(reverse(-123))
    print(reverse(120))