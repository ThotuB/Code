numbers = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
numerals = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']

def romanToInt(roman_num: str) -> int:
    num = 0
    
    while roman_num:
        for numeral, number in zip(numerals, numbers):
            if roman_num.startswith(numeral):
                num += number
                roman_num = roman_num[len(numeral):]
                break
        
    return num

if __name__ == '__main__':
    assert romanToInt('I') == 1
    assert romanToInt('V') == 5
    assert romanToInt('X') == 10
    assert romanToInt('L') == 50
    assert romanToInt('C') == 100
    assert romanToInt('D') == 500
    assert romanToInt('M') == 1000

    assert romanToInt('III') == 3
    assert romanToInt('IV') == 4
    assert romanToInt('IX') == 9
    assert romanToInt('LVIII') == 58
    assert romanToInt('MCMXCIV') == 1994
    assert romanToInt('MMMCMXCIX') == 3999