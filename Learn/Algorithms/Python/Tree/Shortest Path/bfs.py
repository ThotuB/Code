import sys, os
sys.path.append(os.path.abspath(sys.path[0] + '/..'))
from tree import Tree, presetTree

def bfs(tree: Tree, goal: int) -> None:
    """
        BFS shortest path
    """
    queue = [tree.root]

    while queue:
        vertex = queue.pop(0)

        if vertex.data == goal:
            break

        for child in vertex.children:
            queue += [child]


def bfs_backtracking_dict(tree: Tree, goal: int):
    """
        BFS shortest path with backtracking
    """
    queue = [tree.root]
    parents = {tree.root: None}

    while queue:
        vertex = queue.pop(0)

        if vertex.data == goal:
            path = [tree[goal]]
            prev_node = parents[path[0]]

            while prev_node:
                path.insert(0, prev_node)
                prev_node = parents[path[0]]

            return path

        for child in vertex.children:
            queue += [child]
            parents[child] = vertex

    return []


def bfs_backtracking_paths(tree: Tree, goal: int):
    """
        BFS shortest path with backtracking
    """
    queue = [[tree.root]]

    while queue:
        path = queue.pop(0)
        vertex = path[-1]

        if vertex.data == goal:
            return path

        new_paths = []
        children = [child for child in vertex.children if child not in path]    
        for child in children:
            new_paths += [path + [child]]

        queue += new_paths

    return []


if __name__ == "__main__":
    tree = presetTree()
    print(bfs_backtracking_paths(tree, 8))