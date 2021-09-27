# Matrix Version
# Graph, Distances, Moves
# Dijkstra

#* Accepted: 8253 ms (5%) | 93.8 MB (5%)

class PriorityQueue:
    #* CONSTRUCTOR
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0

        self.prios: list[int] = [None] * self.capacity
        self.keys: list[int] = [None] * self.capacity
        self.position_map: list[int]      = [None] * self.capacity


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
    def enqueue(self, priority, key):
        self.prios[self.size] = priority
        self.keys[self.size] = key
        self.position_map[key] = self.size
        self.size += 1
        
        self.heapify_up(self.size - 1)

    def dequeue(self):
        if self.size == 0:
            return None

        key = self.keys[0]
        self.swap(0, self.size - 1)
        self.position_map[self.keys[0]] = 0
        self.size -= 1

        self.heapify_down(0)

        return key

    # Change Priority
    def change_priority(self, new_priority, key):
        if key < 0 or key >= self.capacity:
            return

        index = self.position_map[key]
        self.prios[index] = new_priority

        self.heapify_up(index)

    def __contains__(self, key):
        return self.position_map[key] != None

    def __str__(self):
        return ' '.join([f'({self.prios[index]}, {self.keys[index]})' for index in range(self.size)])


def Reachable_Nodes(edges: list[list[int]], max_moves: int, n: int) -> int:
    graph = [[-1 for _ in range(n)] for _ in range(n)]
    moves_made = [-1] * n
    visited = set()

    for u, v, subnodes in edges:
        graph[u][v] = subnodes
        graph[v][u] = subnodes

    def dijkstra(source):
        nonlocal  visited, moves_made

        node_pq = PriorityQueue(n)
        moves_made[source] = max_moves
        node_pq.enqueue(max_moves, source)
        
        while not node_pq.is_empty():
            print(node_pq)
            node = node_pq.dequeue()

            if moves_made[node] >= 0:
                visited |= {node}
            if moves_made[node] < 0:
                continue

            for neighbor, subnodes in enumerate(graph[node]):
                if subnodes == -1 or neighbor == node:
                    continue

                moves = moves_made[node] - subnodes - 1
                if moves > moves_made[neighbor]:
                    moves_made[neighbor] = moves
                    if neighbor in node_pq:
                        node_pq.change_priority(moves, neighbor)
                    else:
                        node_pq.enqueue(moves, neighbor)


    dijkstra(0)

    for i in range(n):
        moves_made[i] = max(moves_made[i], 0)
    
    print(moves_made)
    print(visited)

    reached = len(visited)
    for u in range(n):
        for v in range(u + 1, n):
            if graph[u][v] == -1:
                continue
            reached += min(graph[u][v], moves_made[u] + moves_made[v])

    return reached
    

if __name__ == "__main__":
    edges = [[1,2,5],[0,3,3],[1,3,2],[2,3,4],[0,4,1]]
    max_moves = 7
    n = 5
    
    print(Reachable_Nodes(edges, max_moves, n))