def timeit(iter):
    def decorator(func):
        def wrapper(*args, **kwargs):
            import time

            start = time.time()
            for _ in range(iter):
                func(*args, **kwargs)

            end = time.time()

            print(f'"{func.__name__}" time: {end - start}s')

        return wrapper
    return decorator