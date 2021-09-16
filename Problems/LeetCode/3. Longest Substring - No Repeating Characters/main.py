def lengthOfLongestSubstring(s: str) -> int:
    start = 0
    end = 0

    max_length = 0

    char_set = set()

    while end < len(s):
        if s[end] not in char_set:
            char_set.add(s[end])
            end += 1
            max_length = max(max_length, char_set.__len__())
        else:
            char_set.remove(s[start])
            start += 1

    return max_length


if __name__ == '__main__':
    text = "abcabcbb"
    print(lengthOfLongestSubstring(text))