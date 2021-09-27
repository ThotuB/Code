import sys

sys.path.append('..')
from tree import Tree

# Breadth-first search
# Iterative - queue
def bfs(tree: Tree):
    if tree.root is None:
        return

    queue = [tree.root]
    while queue:
        node = queue.pop(0)

        print(f'{node.data} ')

        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)


if __name__ == '__main__':
    tree = Tree()
    tree.insert(5, 1, 10, 8, 9, 2, 3, 4, 7, 6)
    bfs(tree)
