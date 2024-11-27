from tree import Node, newTree

def isSymmetric(root: Node) -> bool:
    def isMirror(left: Node, right: Node) -> bool:
        if not left and not right:
            return True
        if not left or not right:
            return False

        return left.val == right.val and isMirror(left.left, right.right) and isMirror(left.right, right.left)

    return isMirror(root, root)


if __name__ == '__main__':
    root = newTree([1, 2, 2, 3, 4, 4, 3])
    print(isSymmetric(root))