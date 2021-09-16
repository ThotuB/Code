# Floyd-Warshall Method
def Print_Matrix(matrix):
    for row in matrix:
        for elem in row:
            if elem == 100:
                print('-', end=' ')
            else:
                print(elem, end=' ')
        print()

def Floyd_Warshall(graph):
    n = len(graph)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if graph[i][k] + graph[k][j] < graph[i][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]
    return graph

def Reachable_Nodes(edges: list[list[int]], max_moves: int, n: int) -> int:
    graph = [[100 for _ in range(n)] for _ in range(n)]

    for u, v, subnodes in edges:
        graph[u][v] = subnodes
        graph[v][u] = subnodes

    Print_Matrix(graph)

    Floyd_Warshall(graph)
    
    Print_Matrix(graph)


if __name__ == "__main__":
    edges = [[0, 4, 1], [0, 3, 3], [3, 1, 2], [3, 2, 3], [1, 2, 5]]
    max_moves = 7
    n = 5

    print(Reachable_Nodes(edges, max_moves, n))