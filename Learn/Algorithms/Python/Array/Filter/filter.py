def filter(function, array):
    result = []
    for element in array:
        if function(element):
            result.append(element)
    
    return result

def at_lest_three_digits(x):
    return 99 < x


if __name__ == '__main__':
    arr = [1, 10, 100, 1000, 10000]
    value = filter(at_lest_three_digits, arr)
    print(value)