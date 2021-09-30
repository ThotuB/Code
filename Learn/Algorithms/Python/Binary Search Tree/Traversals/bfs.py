import sys, os
sys.path.append(os.path.abspath(sys.path[0] + '/..'))
from bintree import BinTree

# Breadth-First Search
# Iterative - queue
def bfs(tree: BinTree) -> None:
    if tree.root is None:
        return

    queue = [tree.root]
    while queue:
        node = queue.pop(0)

        print(node.data, end=' ')

        if node.left:
            queue += [node.left]
        if node.right:
            queue += [node.right]


if __name__ == '__main__':
    tree = BinTree()
    tree.insert(5, 4, 10, 8, 9, 2, 3, 1, 7, 6)
    bfs(tree)
