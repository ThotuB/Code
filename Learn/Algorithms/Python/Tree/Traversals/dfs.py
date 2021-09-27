import sys, os
sys.path.append(os.path.abspath(sys.path[0] + '/..'))
from tree import Tree, Node, presetTree


def dfs_recursive(tree: Tree) -> None:
    def _dfs(node: Node) -> None:
        if not node:
            return

        print(node.data, end=' ')

        for child in node.children:
            _dfs(child)

    _dfs(tree.root)


def dfs_iterative(tree: Tree) -> None:
    stack = [tree.root]

    while stack:
        node = stack.pop()

        print(node.data, end=' ')

        for child in node.children[::-1]:
            stack.append(child)


if __name__ == '__main__':
    tree = presetTree()
    dfs_iterative(tree)
