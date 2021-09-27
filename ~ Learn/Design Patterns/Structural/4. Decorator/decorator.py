def decorator(*args, **kwargs):
    def inner_decorator(func):
        def wrapper(*args, **kwargs):
            print('\t\twrapper start')

            print(f'\t\twrapper args: {args}')
            print(f'\t\twrapper kwargs: {kwargs}')

            result = func(*args, **kwargs)
            
            print('\t\twrapper end')

            return result

        print('\tinner decorator start')
        print(f'\tinner decorator func: {func.__name__}')

        return wrapper

    print('decorator start')

    print(f'decorator args: {args}')
    print(f'decorator kwargs: {kwargs}')

    return inner_decorator

@decorator(1, 2, a=1, b=2)
def function(a, b, *args, **kwargs):
    print('\t\t\tfunction start')
    
    print(f'\t\t\tfunction params: {a}, {b}')
    print(f'\t\t\tfunction args: {args}')
    print(f'\t\t\tfunction kwargs: {kwargs}')

    #
    # some
    # code
    #
    
    print('\t\t\tfunction end')

if __name__ == '__main__':
    function(1, 2, 3, 4, e='5', f='6')
