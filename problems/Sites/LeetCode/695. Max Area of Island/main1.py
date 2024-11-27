def maxAreaOfIsland(grid: list[list[int]]) -> int:
    # Get Area of Island
    def getArea(row: int, col: int) -> int:
        # Check if Island Cell
        def check(r: int, c: int) -> bool:
            # boundary check
            if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]):
                return False
            # unvisited island check
            if grid[r][c] != 1:
                return False
            return True

        area = 0

        fill_queue = []
        fill_queue.append((row, col))

        while fill_queue:
            row, col = fill_queue.pop(0)

            if not check(row, col):
                continue
            area += 1
            grid[row][col] = 2

            if check(row - 1, col):
                fill_queue.append((row - 1, col))
            if check(row + 1, col):
                fill_queue.append((row + 1, col))
            if check(row, col - 1):
                fill_queue.append((row, col - 1))
            if check(row, col + 1):
                fill_queue.append((row, col + 1))

        return area

    max_area = 0

    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1:
                area = getArea(row, col)
                print(area)
                max_area = max(max_area, area)

    return max_area


if __name__ == "__main__":
    image = [[1, 1, 0, 0, 0],
             [1, 1, 0, 0, 0],
             [0, 0, 0, 1, 1],
             [0, 0, 0, 1, 1]]
    print(maxAreaOfIsland(image))
