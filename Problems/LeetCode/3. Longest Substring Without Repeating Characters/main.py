def lengthOfLongestSubstring(s: str) -> int:
    left = 0
    right = 0

    max_length = 0

    char_set = set()

    while right < len(s):
        if s[right] not in char_set:
            char_set.add(s[right])
            right += 1
            max_length = max(max_length, char_set.__len__())
        else:
            char_set.remove(s[left])
            left += 1

    return max_length


if __name__ == '__main__':
    text = "abcabcbb"
    print(lengthOfLongestSubstring(text))