# Object Version
# Nodes and Subnodes
# Depth First Search

#! Time Limit Exceeded

class Node:
    def __init__(self):
        self.neighbors = []
        self.visited = False
        self.moves = float('inf')

class Graph:
    def __init__(self, edges: list[list[int]], n: int):
        self.n = n
        self.nodes = [Node() for _ in range(n)]

        for u, v, subnodes in edges:
            self.insert_subnodes(u, v, subnodes)

    def insert_subnodes(self, u, v, subnodes):
        def insert_subnodes(node1, node2, subnodes):
            if subnodes == 0:
                node2.neighbors += [node1]

                return node2
            
            subnode = Node()
            subnode.neighbors += [node1, insert_subnodes(subnode, node2, subnodes - 1)]

            return subnode

        self[u].neighbors += [insert_subnodes(self[u], self[v], subnodes)]

    def __getitem__(self, key):
        return self.nodes[key]

def Reachable_Nodes(graph: Graph, max_moves: int):
    reached = 0

    def dfs(node: Node, moves: int):
        if moves == 0:
            return

        nonlocal reached
        if node.visited:
            if moves < node.moves:
                return
        else:
            node.visited = True
            reached += 1

        node.moves = moves

        for neighbor in node.neighbors:
            dfs(neighbor, moves - 1)

    dfs(graph[0], max_moves+1)

    return reached


if __name__ == '__main__':
    edges = [[0, 4, 1], [0, 3, 3], [3, 1, 2], [3, 2, 4], [1, 2, 5]]
    max_moves = 7
    n = 5

    graph = Graph(edges, n)
    print(Reachable_Nodes(graph, max_moves))