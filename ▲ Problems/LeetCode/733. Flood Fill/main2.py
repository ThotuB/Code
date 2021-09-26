# Iterative Implementation

def floodFill(image: list[list[int]], row: int, col: int, new_color: int) -> list[list[int]]:
    old_color = image[row][col]

    if old_color == new_color:
        return image

    # Check if valid pixel
    def check(row: int, col: int) -> bool:
        # boundry check
        if row < 0 or row >= len(image) or col < 0 or col >= len(image[0]):
            return False
        # check if old color
        if image[row][col] != old_color:
            return False
        return True

    fill_queue = []
    fill_queue.append((row, col))

    while fill_queue:
        row, col = fill_queue.pop(0)
        image[row][col] = new_color

        if check(row - 1, col):
            fill_queue.append((row - 1, col)) # up
        if check(row + 1, col):
            fill_queue.append((row + 1, col)) # down
        if check(row, col - 1):
            fill_queue.append((row, col - 1)) # left
        if check(row, col + 1):
            fill_queue.append((row, col + 1)) # right

    return image


if __name__ == "__main__":
    image = [[0, 0, 0], [0, 1, 1]]
    row = 1
    col = 1
    new_color = 1
    print(floodFill(image, row, col, new_color))