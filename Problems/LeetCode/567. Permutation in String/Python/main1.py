def checkInclusion(s1: str, s2: str) -> bool:
    chars = [0] * 26

    for char in s1:
        order = ord(char) - ord('a')
        chars[order] += 1

    left = 0
    right = 0

    while right < len(s2):
        right_order = ord(s2[right]) - ord('a')

        if chars[right_order] > 0:
            chars[right_order] -= 1
            right += 1
        else:
            while chars[right_order] == 0:
                left_order = ord(s2[left]) - ord('a')
                chars[left_order] += 1
                left += 1
        
        if right - left == len(s1):
            return True
    
    return False


if __name__ == "__main__":
    s1 = "adc"
    s2 = "dcda"
    print(checkInclusion(s1, s2))