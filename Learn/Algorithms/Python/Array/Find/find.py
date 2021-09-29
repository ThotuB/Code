def find(function, array):
    for element in array:
        if function(element):
            return element
    
    return None

def three_digits(x):
    return 99 < x < 1000


if __name__ == '__main__':
    arr = [1, 10, 100, 1000, 10000]
    value = find(three_digits, arr)
    print(value)
