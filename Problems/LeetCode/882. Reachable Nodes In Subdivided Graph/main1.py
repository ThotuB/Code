# Matrix Version
# Graph and Moves
# Depth-First Search

#! Time Limit Exceeded

def Print_Matrix(matrix, ingore=None):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if matrix[i][j] == ingore:
                print('-', end='\t')
            else:
                print(matrix[i][j], end = '\t')
        print()
    print()

def reachableNodes(edges: list[list[int]], max_moves: int, n: int) -> int:
    graph = [[-1 for _ in range(n)] for _ in range(n)]
    moves_made = [[0 for _ in range(n)] for _ in range(n)]
    visited = set()

    for u, v, subnodes in edges:
        graph[u][v] = subnodes
        graph[v][u] = subnodes

    def dfs(node, moves):
        if moves >= 0:
            nonlocal visited
            visited |= {node}
        if moves <= 0:
            return

        for neighbor, subnodes in enumerate(graph[node]):
            if subnodes == -1 or neighbor == node:
                continue
            
            if moves > moves_made[node][neighbor]:
                moves_made[node][neighbor] = moves
                dfs(neighbor, moves - subnodes - 1)

    dfs(0, max_moves)

    Print_Matrix(graph, -1)
    Print_Matrix(moves_made, 0)
    print(visited)

    reached = len(visited)
    for u in range(n):
        for v in range(u + 1, n):
            if graph[u][v] == -1:
                continue
            reached += min(graph[u][v], moves_made[u][v] + moves_made[v][u])

    return reached
    

if __name__ == "__main__":
    edges = [[1,2,5],[0,3,3],[1,3,2],[2,3,4],[0,4,1]]
    max_moves = 7
    n = 5
    
    print(reachableNodes(edges, max_moves, n))