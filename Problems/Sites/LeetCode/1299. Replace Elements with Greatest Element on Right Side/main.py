def replaceElements(arr: list[int]) -> list[int]:
    max_val = -1
    for i in range(len(arr) - 1, -1, -1):
        temp = arr[i]
        arr[i] = max_val
        max_val = max(max_val, temp)
    
    return arr

if __name__ == "__main__":
    arr = [17,18,5,4,6,1]
    print(replaceElements(arr))