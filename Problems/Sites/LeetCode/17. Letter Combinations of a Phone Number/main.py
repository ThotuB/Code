phone_digits = {
    '2': ['a', 'b', 'c'],
    '3': ['d', 'e', 'f'],
    '4': ['g', 'h', 'i'],
    '5': ['j', 'k', 'l'],
    '6': ['m', 'n', 'o'],
    '7': ['p', 'q', 'r', 's'],
    '8': ['t', 'u', 'v'],
    '9': ['w', 'x', 'y', 'z']
}

def letterCombinations(digits: str) -> list[str]:
    if not digits:
        return []

    res = ['']
    for digit in digits:
        res = [letter + next_letter for letter in res for next_letter in phone_digits[digit]]
    return res


if __name__ == '__main__':
    assert letterCombinations('23') == ['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']
    assert letterCombinations('2') == ['a', 'b', 'c']
    assert letterCombinations('') == []