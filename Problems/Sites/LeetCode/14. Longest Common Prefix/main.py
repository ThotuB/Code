def longestCommonPrefix(strs: list[str]) -> str:
    if not strs:
        return ""
    
    for i, letter_group in enumerate(zip(*strs)):
        if len(set(letter_group)) > 1:
            return strs[0][:i]
    else:
        return min(strs)
    
    
if __name__ == '__main__':
    assert longestCommonPrefix(["flower","flow","flight"]) == "fl"
    assert longestCommonPrefix(['dog','racecar','car']) == ""