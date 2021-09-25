def validMountainArray(arr: list[int]) -> bool:
    if len(arr) < 3:
        return False

    i = 1
    # Ascending
    while i < len(arr) and arr[i] > arr[i - 1]:
        i += 1
    
    if not 1 < i < len(arr):
        return False
    
    # Descending
    while i < len(arr) and arr[i] < arr[i - 1]:
        i += 1
    
    if i < len(arr):
        return False

    # Mountain
    return True


if __name__ == "__main__":
    print(validMountainArray([2,1]))
    print(validMountainArray([3,5,5]))
    print(validMountainArray([0,3,2,1]))
    print(validMountainArray([0,1,2,3,4,5,6,7,8,9]))