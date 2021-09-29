def map(function, array):
    result = []
    for element in array:
        result.append(function(element))
    
    return result

def double(x):
    return x * 2


if __name__ == '__main__':
    arr = [1, 10, 100, 1000, 10000]
    value = map(double, arr)
    print(value)
