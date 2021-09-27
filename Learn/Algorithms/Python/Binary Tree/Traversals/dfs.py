import sys, os
sys.path.append(os.path.abspath(sys.path[0] + '/..'))
from bintree import BinTree, Node

# Depth-First Search
# Recursive
def dfs(tree: BinTree) -> None:
    def _dfs(node: Node) -> None:
        if not node:
            return
           
        print(node.data, end=' ')

        _dfs(node.left)
        _dfs(node.right)

    _dfs(tree.root)


if __name__ == '__main__':
    tree = BinTree()
    tree.insert(5, 4, 10, 8, 9, 2, 3, 1, 7, 6)
    dfs(tree)
