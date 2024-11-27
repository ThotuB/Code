def if_else(n: int):
    if n % 2 == 1:
        print("Weird")
    elif n < 5:
        print("Not Weird")
    elif n <= 20:
        print("Weird")
    else:
        print("Not Weird")


if __name__ == '__main__':
    if_else(3)
    if_else(24)