import sys, os
sys.path.append(os.path.abspath(sys.path[0] + '/..'))
from bintree import BinTree, Node

# Preorder traversal
# Recursive
def preorder(tree: BinTree) -> None:
    def traverse(node: Node) -> None:
        if not node:
            return
           
        print(node.data, end=' ')
        traverse(node.left)
        traverse(node.right)

    traverse(tree.root)


if __name__ == '__main__':
    tree = BinTree()
    tree.insert(5, 4, 10, 8, 9, 2, 3, 1, 7, 6)
    preorder(tree)
