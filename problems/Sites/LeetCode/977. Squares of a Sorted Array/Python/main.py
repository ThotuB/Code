def sortedSquares(nums: list[int]) -> list[int]:
    negative_squares = []
    positive_squares = []

    for num in nums:
        square = num * num
        if num < 0:
            negative_squares.append(square)
        else:
            positive_squares.append(square)
    negative_squares.reverse()

    squares = []
    i = 0
    j = 0

    while i < len(negative_squares) and j < len(positive_squares):
        if negative_squares[i] < positive_squares[j]:
            squares.append(negative_squares[i])
            i += 1
        else:
            squares.append(positive_squares[j])
            j += 1

    while i < len(negative_squares):
        squares.append(negative_squares[i])
        i += 1

    while j < len(positive_squares):
        squares.append(positive_squares[j])
        j += 1

    return squares