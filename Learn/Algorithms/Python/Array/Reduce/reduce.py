def reduce(function, array, initial=None):
    if initial is None:
        value = array[0]
        array = array[1:]
    else:
        value = initial

    for elem in array:
        value = function(value, elem)

    return value

def add(x, y):
    return x + y


if __name__ == '__main__':
    arr = [1, 10, 100, 1000, 10000]
    value = reduce(add, arr)
    print(value)
