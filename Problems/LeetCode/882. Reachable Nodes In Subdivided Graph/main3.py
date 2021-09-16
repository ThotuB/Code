def printMatrix(matrix):
    for row in matrix:
        print(*row)

def reachableNodes(edges: list[list[int]], max_moves: int, n: int) -> int:
    graph = [[[0] for _ in range(n)] for _ in range(n)]
    links

    for u, v, subnodes in edges:
        graph[u][v] = subnodes
        graph[v][u] = subnodes

    def dfs(node: int, moves: int, visited: set=set()):
        if moves < 0:
            return 0

        visited |= {node}
        
        reached = 1
        for i, (linked, subnodes) in enumerate(graph[node]):
            if not linked:
                continue

            submoves = min(moves, subnodes)
            subnodes_left = subnodes - submoves
            graph[node][i] = subnodes_left
            graph[i][node] = subnodes_left

            moves_left = moves - submoves

            reached += submoves + dfs(i, moves_left, visited)

        return reached

    return dfs(0, max_moves)
    

if __name__ == "__main__":
    edges = [[3,4,8],[0,1,3],[1,4,0],[1,2,3],[0,3,2],[0,4,10],[1,3,3],[2,4,3],[2,3,3],[0,2,10]]
    max_moves = 7
    n = 5

    print(reachableNodes(edges, max_moves, n))