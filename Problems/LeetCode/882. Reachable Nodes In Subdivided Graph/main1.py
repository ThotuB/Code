def printMatrix(matrix):
    for row in matrix:
        print(*row)

def reachableNodes(edges: list[list[int]], max_moves: int, n: int) -> int:
    graph = [[0 for _ in range(n)] for _ in range(n)]
    reached = [[0 for _ in range(n)] for _ in range(n)]

    for u, v, subnodes in edges:
        graph[u][v] = subnodes
        graph[v][u] = subnodes

    def dfs(node, moves):
        if moves < 0:
            return 0
        
        reached[node][node] = 1

        for i, subnodes in enumerate(graph[node]):
            if subnodes == 0:
                continue

            subnodes_reached = min(moves, subnodes)
            reached[node][i] = subnodes_reached

    dfs(0, max_moves)
    

if __name__ == "__main__":
    edges = [[3,4,8],[0,1,3],[1,4,0],[1,2,3],[0,3,2],[0,4,10],[1,3,3],[2,4,3],[2,3,3],[0,2,10]]
    max_moves = 7
    n = 5

    print(reachableNodes(edges, max_moves, n))