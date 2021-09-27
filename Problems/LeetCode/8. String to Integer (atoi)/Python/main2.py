def myAtoi(s: str) -> int:
    index = 0
    sign = 1
    number = 0

    while index < len(s) and s[index] == ' ':
        index += 1

    if index == len(s):
        return 0

    if s[index] == '-':
        sign = -1
        index += 1
    elif s[index] == '+':
        index += 1

    while index < len(s) and '0' <= s[index] <= '9':
        number = number * 10 + (ord(s[index]) - ord('0'))
        index += 1


    result = sign * number

    if result > 2147483647:
        return 2147483647
    elif result < -2147483648:
        return -2147483648
    else:
        return result
        


if __name__ == '__main__':
    print(myAtoi("-91283472332"))