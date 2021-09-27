import sys, os
sys.path.append(os.path.abspath(sys.path[0] + '/..'))
from tree import Tree, presetTree


def bfs(tree: Tree) -> None:
    if tree.root is None:
        return

    queue = [tree.root]
    while queue:
        node = queue.pop(0)

        print(node.data, end=' ')

        for child in node.children:
            queue += [child]


if __name__ == '__main__':
    tree = presetTree()
    bfs(tree)
