# Object Version
# Nodes and Subnodes
# Breadth First Search

#! Time Limit Exceeded

name = ''
ctr = 0

class Node:
    def __init__(self):
        self.name= None
        self.neighbors = []
        self.visited = False
        self.depth = 0

class Graph:
    def __init__(self, edges: list[list[int]], n: int):
        self.n = n
        self.nodes = [Node() for _ in range(n)]

        for u, v, subnodes in edges:
            global name, ctr
            name = f'{u}{v}'
            ctr = 1
            self.insert_subnodes(u, v, subnodes)

    def insert_subnodes(self, u, v, subnodes):
        def insert_subnodes(node1, node2, subnodes):
            if subnodes == 0:
                node2.neighbors += [node1]

                return node2
            
            subnode = Node()
            global name, ctr
            subnode.name = f'{name}{ctr}'
            ctr += 1
            subnode.neighbors += [node1, insert_subnodes(subnode, node2, subnodes - 1)]

            return subnode

        self[u].neighbors += [insert_subnodes(self[u], self[v], subnodes)]

    def __getitem__(self, key):
        return self.nodes[key]

def Reachable_Nodes(graph: Graph, max_moves: int):
    def bfs(node: Node, max_depth: int):
        reached = 0

        node.visited = True
        node.depth = 0
        node_queue = [node]

        while node_queue:
            node = node_queue.pop(0)

            reached += 1
            
            if node.depth == max_depth:
                continue

            for neighbor in node.neighbors:
                if neighbor.visited:
                    continue

                neighbor.visited = True
                neighbor.depth = node.depth + 1
                node_queue += [neighbor]

        return reached

    return bfs(graph[0], max_moves)

if __name__ == '__main__':
    edges = [[2,4,2],[3,4,5],[2,3,1],[0,2,1],[0,3,5]]
    max_moves = 14
    n = 5

    graph = Graph(edges, n)
    print(Reachable_Nodes(graph, max_moves))