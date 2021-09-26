def myAtoi(s: str) -> int:
    def ignoreLeadingSpaces(s: str):
        nonlocal index
        while index < len(s) and s[index] == ' ':
            index += 1
    
    def getSign(s: str):
        nonlocal index, sign
        if index >= len(s):
            return

        if s[index] == '-':
            sign = -1
            index += 1
        elif s[index] == '+':
            index += 1

    def getNumber(s: str):
        nonlocal index, sign, number
        while index < len(s) and '0' <= s[index] <= '9':
            number = number * 10 + (ord(s[index]) - ord('0'))
            index += 1

    index = 0
    sign = 1
    number = 0
    
    ignoreLeadingSpaces(s)
    getSign(s)
    getNumber(s)

    result = sign * number

    if result > 2147483647:
        return 2147483647
    elif result < -2147483648:
        return -2147483648
    else:
        return result
        


if __name__ == '__main__':
    print(myAtoi("-91283472332"))