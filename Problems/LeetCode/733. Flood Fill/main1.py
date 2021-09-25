# Recursive Implementation

def floodFill(image: list[list[int]], row: int, col: int, new_color: int) -> list[list[int]]:
    old_color = image[row][col]

    if old_color == new_color:
        return image

    def fill(image: list[list[int]], row: int, col: int) -> None:
        # boundry check
        if row < 0 or row >= len(image) or col < 0 or col >= len(image[0]):
            return
        # check if pixel is old color
        if image[row][col] != old_color:
            return

        nonlocal new_color
        image[row][col] = new_color

        fill(image, row + 1, col) # down
        fill(image, row - 1, col) # up
        fill(image, row, col + 1) # right
        fill(image, row, col - 1) # left
    
    fill(image, row, col)

    return image


if __name__ == "__main__":
    image = [[0, 0, 0], [0, 1, 1]]
    row = 1
    col = 1
    new_color = 1
    print(floodFill(image, row, col, new_color))