from math import comb

# Time: O(n^2)
# Space: O(n)
def Fibonacci_Recursive(n):
    if n <= 1:
        return n
        
    return Fibonacci_Recursive(n-1) + Fibonacci_Recursive(n-2)

# Time: O(n)
# Space: O(n)
def Fibonacci_Recursive_Dynamic(n):
    fib_list = [0, 1]

    def Fib(n):
        nonlocal fib_list

        # Number already calculated
        if n < len(fib_list):
            return fib_list[n]
        
        # Calculate number and store in list
        fib_list += [Fib(n-1) + Fib(n-2)]
        return fib_list[n]

    return Fib(n)


# Time: O(n)
# Space: O(n)
def Fibonacci_Iterative(n):
    fib_list = [0, 1]

    for i in range(2, n+1):
        fib_list.append(fib_list[i-1] + fib_list[i-2])

    return fib_list[n]

# Time: O(n)
# Space: O(1)
def Fibonacci_Iterative_Space_Efficient(n):
    fib_list = [0, 1]

    for _ in range(2, n+1):
        fib_list[0], fib_list[1] = fib_list[1], fib_list[0] + fib_list[1]

    if n == 0:
        return fib_list[0]

    return fib_list[1]

# Time: O(n?)
# Space: O(1)
def Fibonacci_Iterative_Combinations(n):
    n -= 1
    fib = 0

    for k in range(0, n // 2 + 1):
        fib += comb(n - k, k)

    return fib

if __name__ == "__main__":
    num = 21
    print(Fibonacci_Recursive(num))
    print(Fibonacci_Recursive_Dynamic(num))
    print(Fibonacci_Iterative(num))
    print(Fibonacci_Iterative_Space_Efficient(num))
    print(Fibonacci_Iterative_Combinations(num))