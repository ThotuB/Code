def duplicateZeros(arr: list[int]) -> None:
    i = 0
    while i < len(arr):
        if arr[i] == 0:
            arr.insert(i, 0)
            arr.pop()
            i += 1
        i += 1
    return arr


if __name__ == "__main__":
    arr = [1, 0, 2, 3, 0, 4, 5, 0]
    duplicateZeros(arr)
    print(arr)