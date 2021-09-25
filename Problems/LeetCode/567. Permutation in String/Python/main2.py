def checkInclusion(s1: str, s2: str) -> bool:
    chars = dict()

    for char in s1:
        if char in chars:
            chars[char] += 1
        else:
            chars[char] = 1

    print(chars)

    left = 0
    right = 0

    while right < len(s2):
        right_char = s2[right]
        if right_char in chars and chars[right_char] > 0:
            chars[right_char] -= 1
            right += 1
        else:
            while left < right:
        
        if right - left == len(s1):
            return True
    
    return False


if __name__ == "__main__":
    s1 = "adc"
    s2 = "dcda"
    print(checkInclusion(s1, s2))
