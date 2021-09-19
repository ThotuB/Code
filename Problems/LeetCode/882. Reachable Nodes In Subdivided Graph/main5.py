# Object Version
# Nodes and Edges
# Breadth-First Search

#* Accepted: 1150 ms (11.5%) | 24.1 MB (5.5%)

class PriorityQueue:
    #* CONSTRUCTOR
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0

        self.prios: list[int]        = [None] * self.capacity
        self.keys: list[int]         = [None] * self.capacity
        self.position_map: list[int] = [None] * self.capacity


    #* METHODS
    # Is Empty
    def is_empty(self):
        return self.size == 0

    # Swap
    def swap(self, i, j):
        self.prios[i], self.prios[j] = self.prios[j], self.prios[i]
        self.keys[i], self.keys[j] = self.keys[j], self.keys[i]
        self.position_map[self.keys[i]] = i
        self.position_map[self.keys[j]] = j

    # Heapify
    def heapify_up(self, index):
        pos = index
        while pos > 0:
            parent = (pos - 1) // 2
            if self.prios[parent] < self.prios[pos]:
                self.swap(parent, pos)
                pos = parent
            else:
                break

    def heapify_down(self, index):
        pos = index
        while pos < self.size:
            left = 2 * pos + 1
            right = 2 * pos + 2
            largest = pos

            if left < self.size and self.prios[left] > self.prios[largest]:
                largest = left

            if right < self.size and self.prios[right] > self.prios[largest]:
                largest = right

            if largest != pos:
                self.swap(pos, largest)
                pos = largest
            else:
                break

    # Enqueue and Dequeue
    def enqueue(self, priority: int, key: int) -> None:
        self.prios[self.size] = priority
        self.keys[self.size] = key
        self.position_map[key] = self.size
        self.size += 1
        
        self.heapify_up(self.size - 1)

    def dequeue(self) -> int:
        if self.size == 0:
            return None

        key = self.keys[0]
        self.swap(0, self.size - 1)
        self.position_map[self.keys[0]] = 0
        self.size -= 1

        self.heapify_down(0)

        return key

    # Change Priority
    def change_priority(self, new_priority: int, key: int):
        if key < 0 or key >= self.capacity:
            return

        index = self.position_map[key]
        self.prios[index] = new_priority

        self.heapify_up(index)

    def __contains__(self, key) -> bool:
        return self.position_map[key] != None

class Node:
    def __init__(self, index: int):
        self.index = index
        self.edges: list[tuple['Node', int]] = []
        self.moves_remaining = -1
        self.visited = False
    
    def __str__(self):
        return ' -> ' + '\n -> '.join([f'{edge[1]}' for edge in self.edges])

class Graph:
    def __init__(self, edges: list[list[int]], n: int):
        self.n = n
        self.nodes = [Node(i) for i in range(n)]

        for u, v, subnodes in edges:
            self[u].edges += [(self[v], subnodes)]
            self[v].edges += [(self[u], subnodes)]

    def __getitem__(self, key):
        return self.nodes[key]

    def __str__(self):
        return '\n'.join(f'{idx}:\n{node}' for idx, node in enumerate(self.nodes))

def Reachable_Nodes(edges: list[list[int]], max_moves: int, n: int) -> int:
    graph = Graph(edges, n)

    def dijkstra(source_node: 'Node'):
        node_pq = PriorityQueue(n)
        
        source_node.moves_remaining = max_moves
        node_pq.enqueue(max_moves, source_node.index)

        while not node_pq.is_empty():
            # print(node_pq)
            idx = node_pq.dequeue()
            node = graph[idx]

            if node.moves_remaining >= 0:
                node.visited = True
            if node.moves_remaining < 0:
                continue

            for neighbor, subnodes in node.edges:
                moves = node.moves_remaining - subnodes - 1
                if moves > neighbor.moves_remaining:
                    neighbor.moves_remaining = moves
                    
                    if neighbor.index in node_pq:
                        node_pq.change_priority(moves, neighbor.index)
                    else:
                        node_pq.enqueue(moves, neighbor.index)


    dijkstra(graph[0])

    for i in range(n):
        graph[i].moves_remaining = max(graph[i].moves_remaining, 0)
    
    # printing
    # print(' '.join([f'{graph[i].moves_remaining}' for i in range(n)]))
    # print(' '.join([f'{graph[i].index}' for i in range(n) if graph[i].visited]))

    reached = sum([1 for i in range(n) if graph[i].visited])
    for (u, v, subnodes) in edges:
        reached += min(subnodes, graph[u].moves_remaining + graph[v].moves_remaining)

    return reached


if __name__ == "__main__":
    edges = [[1,2,5],[0,3,3],[1,3,2],[2,3,4],[0,4,1]]
    max_moves = 7
    n = 5

    print(Reachable_Nodes(edges, max_moves, n))