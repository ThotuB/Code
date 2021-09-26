def updateMatrix(mat: list[list[int]]) -> list[list[int]]:
    m = len(mat)
    n = len(mat[0])
    
    

def printMatrix(mat: list[list[int]]) -> None:
    for row in mat:
        print(row)

if __name__ == '__main__':
    mat = [[1, 0, 1, 1, 0, 0, 1, 0, 0, 1],
           [0, 1, 1, 0, 1, 0, 1, 0, 1, 1],
           [0, 0, 1, 0, 1, 0, 0, 1, 0, 0],
           [1, 0, 1, 0, 1, 1, 1, 1, 1, 1],
           [0, 1, 0, 1, 1, 0, 0, 0, 0, 1],
           [0, 0, 1, 0, 1, 1, 1, 0, 1, 0],
           [0, 1, 0, 1, 0, 1, 0, 0, 1, 1],
           [1, 0, 0, 0, 1, 1, 1, 1, 0, 1],
           [1, 1, 1, 1, 1, 1, 1, 0, 1, 0],
           [1, 1, 1, 1, 0, 1, 0, 0, 1, 1]]
    printMatrix(updateMatrix(mat))
