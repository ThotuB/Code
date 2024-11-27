# Iterative Implementation

def floodFill(image: list[list[int]], row: int, col: int, new_color: int) -> list[list[int]]:
    old_color = image[row][col]

    if old_color == new_color:
        return image

    def check(row: int, col: int) -> bool:
        if row < 0 or row >= len(image) or col < 0 or col >= len(image[0]):
            return False
        if image[row][col] != old_color:
            return False
        return True

    fill_queue = []
    fill_queue.append((row, col))
    image[row][col] = new_color

    while fill_queue:
        row, col = fill_queue.pop(0)

        if check(row - 1, col):
            fill_queue.append((row - 1, col))
            image[row-1][col] = new_color
        if check(row + 1, col):
            fill_queue.append((row + 1, col))
            image[row+1][col] = new_color
        if check(row, col - 1):
            fill_queue.append((row, col - 1))
            image[row][col-1] = new_color
        if check(row, col + 1):
            fill_queue.append((row, col + 1))
            image[row][col+1] = new_color

    return image


if __name__ == "__main__":
    image = [[0, 0, 0], [0, 1, 1]]
    row = 1
    col = 1
    new_color = 1
    print(floodFill(image, row, col, new_color))