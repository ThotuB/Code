def checkIfExist(arr: list[int]) -> bool:
    num_set = set()
    for num in arr:
        if (num * 2) in num_set:
            return True
        if num / 2 in num_set:
            return True

        num_set |= {num}
    
    return False


if __name__ == "__main__":
    print(checkIfExist([10, 2, 5, 3]))
    print(checkIfExist([7, 1, 14, 11]))
    print(checkIfExist([3, 1, 7, 11]))