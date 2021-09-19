# Object Version
# Nodes and Edges
# Breadth-First Search

#* Accepted: 
#* BEST  - 519 ms (35.5%) | 20.7 MB (92.0%)
#* WORST - 780 ms (35.5%) | 20.8 MB (85.0%)

from collections import defaultdict
from heapq import heappush, heappop

def Reachable_Nodes(edges: list[list[int]], max_moves: int, n: int) -> int:
    graph = defaultdict(set)
    dists = [0] * n

    for u, v, weight in edges:
        graph[u] |= {(v, weight + 1)}
        graph[v] |= {(u, weight + 1)}

    def dijkstra(source_node: int):
        dists[source_node] = 0
        heap =[(0, source_node)]

        while heap:
            min_dist, node = heappop(heap)
            for neighbor, weight in graph[node]:
                new_dist = min_dist + weight
                if new_dist < dists[neighbor]:
                    dists[neighbor] = new_dist
                    heappush(heap, (new_dist, neighbor))

    dijkstra(0)

    reached = sum(dists[i] <= max_moves for i in range(n))
    for u, v, w in edges:
        w1 = max(0, max_moves - dists[u])
        w2 = max(0, max_moves - dists[v])
        reached += min(w, w1 + w2)

    return reached


if __name__ == "__main__":
    edges = [[1,2,5],[0,3,3],[1,3,2],[2,3,4],[0,4,1]]
    max_moves = 7
    n = 5

    print(Reachable_Nodes(edges, max_moves, n))