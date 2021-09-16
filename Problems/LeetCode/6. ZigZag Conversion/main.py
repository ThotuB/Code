def convert(s: str, numRows: int) -> str:
    if numRows == 1:
        return s
    
    zigzag = ''
    factor = 2 * numRows - 2

    jump = factor
    
    for row in range(numRows):
        for i in range(row, len(s), factor):
            zigzag += s[i]
            if jump != 0 and jump != factor and i + jump < len(s):
                zigzag += s[i + jump]
        jump -= 2

    return zigzag


if __name__ == "__main__":
    print(convert("PAYPALISHIRING", 4))