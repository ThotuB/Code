import re

def decode_matrix(matrix: list[list[str]]):
    n = len(matrix)
    m = len(matrix[0])

    res = ''

    for col in zip(*matrix):
        res += ''.join(col)
            
    return re.sub(r'(?<=\w)([^\w]+)(?=\w)', ' ', res)

if __name__ == '__main__':
    matrix = [
        ['T', 's', 'i'],
        ['h', '%', 'x'],
        ['i', ' ', '#'],
        ['s', 'M', ' '],
        ['$', 'a', ' '],
        ['#', 't', '%'],
        ['i', 'r', '!'],
    ]

    print(decode_matrix(matrix))