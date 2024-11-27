numbers = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
numerals = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']

def intToRoman(num: int) -> str:
    roman_num = ''
    
    while num > 0:
        for numeral, number in zip(numerals, numbers):
            if num >= number:
                roman_num += numeral
                num -= number
                break
        
    return roman_num

if __name__ == '__main__':
    assert intToRoman(1) == 'I'
    assert intToRoman(5) == 'V'
    assert intToRoman(10) == 'X'
    assert intToRoman(50) == 'L'
    assert intToRoman(100) == 'C'
    assert intToRoman(500) == 'D'
    assert intToRoman(1000) == 'M'

    assert intToRoman(3) == 'III'
    assert intToRoman(4) == 'IV'
    assert intToRoman(9) == 'IX'
    assert intToRoman(58) == 'LVIII'
    assert intToRoman(1994) == 'MCMXCIV'
    assert intToRoman(3999) == 'MMMCMXCIX'