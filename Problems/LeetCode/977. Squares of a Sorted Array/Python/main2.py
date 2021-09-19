def merge(arr, mid):
    squares = []

    neg_index = mid
    pos_index = mid + 1

    while 0 <= neg_index and pos_index < len(arr):
        if arr[neg_index] < arr[pos_index]:
            squares.append(arr[neg_index])
            neg_index -= 1
        else:
            squares.append(arr[pos_index])
            pos_index += 1

    while 0 <= neg_index:
        squares.append(arr[neg_index])
        neg_index -= 1

    while pos_index < len(arr):
        squares.append(arr[pos_index])
        pos_index += 1

    return squares

def sortedSquares(nums: list[int]) -> list[int]:
    mid = 0
    for i in range(len(nums)):
        if nums[i] < 0:
            mid = i
        nums[i] = nums[i] ** 2

    return merge(nums, mid)


if __name__ == '__main__':
    print(sortedSquares([-4,-1,0,3,10]))