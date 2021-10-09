import sys, os
sys.path += [os.path.abspath(sys.path[0] + '/../~ Decorator')]
from timer import timeit

def compare(num: list[int], taget_num: list[int]):
    for i in range(len(taget_num)):
        if num[i] != taget_num[i]:
            return False
    return True

@timeit(iter=1)
def backtracking_recursive1(target: list[int]) -> list[int]:
    result = None
    found = False

    def backtrack(stack: list[int], iter: int, iter_max: int):
        nonlocal result, found
        # target already found
        if found:
            return
        # stopping condition
        if iter == iter_max:
            # target found
            if compare(stack, target):
                result = stack[:]
                found = True
            # target not found
            return
        
        for digit in range(10):
            stack.append(digit)
            backtrack(stack, iter + 1, iter_max)
            stack.pop()
    
    backtrack([], 0, len(target))

    return result


@timeit(iter=1)
def backtracking_recursive2(taget_num: list[int]) -> list[int]:
    result = None
    found = False

    def backtrack(stack: list[int], iter: int, iter_max: int):
        nonlocal result, found
        for digit in range(10):
            stack.append(digit)

            # target already found
            if found:
                break
            # stopping condition
            if iter == iter_max:
                # target found
                if compare(stack, taget_num):
                    result = stack[:]
                    found = True
            else:
                backtrack(stack, iter + 1, iter_max)

            stack.pop()

    backtrack([], 1, len(taget_num))

    return result


@timeit(iter=1)
def backtracking_iterative1(taget_num: list[int]) -> list[int]:
    stack = [[]]
    length_max = len(taget_num)

    while ( len(stack) > 0 ):
        curr_num = stack.pop()
        length = len(curr_num)

        if length == length_max:
            if compare(curr_num, taget_num):
                return curr_num
        else:
            for digit in range(10):
                new_num = curr_num + [digit]
                stack.append(new_num)

    return None


@timeit(iter=1)
def backtracking_iterative2(taget_num: list[int]) -> list[int]:
    stack = [[]]
    length_max = len(taget_num)

    while ( len(stack) > 0 ):
        curr_num = stack.pop()
        length = len(curr_num)

        for digit in range(10):
            new_num = curr_num + [digit]

            if length + 1 == length_max:
                if compare(new_num, taget_num):
                    return new_num
            else:
                stack.append(new_num)

    return None

if __name__ == '__main__':
    tel_num = [4, 5, 2, 1, 0, 2, 7]
    backtracking_recursive1(tel_num)
    backtracking_recursive2(tel_num)
    backtracking_iterative1(tel_num)
    backtracking_iterative2(tel_num)