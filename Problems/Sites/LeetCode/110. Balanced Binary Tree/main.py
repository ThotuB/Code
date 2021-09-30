from tree import Node, newTree

def isBalanced(root: Node) -> bool:
    def checkHeight(node: Node) -> int:
        if node is None:
            return 0

        # Check if left is balanced
        leftHeight = checkHeight(node.left)
        if leftHeight == -1:
            return -1 # propagate error up
        # Check if right is balanced
        rightHeight = checkHeight(node.right)
        if rightHeight == -1:
            return -1 # propagate error up

        # Check if left and right are balanced
        if abs(leftHeight - rightHeight) > 1:
            return -1

        return max(leftHeight, rightHeight) + 1
    return checkHeight(root) != -1


if __name__ == '__main__':
    root = newTree([1, 2, 2, 3, 4, 4, 3])
    print(isBalanced(root))

    root = newTree([1, 2, 2, None, 3, None, 3])
    print(isBalanced(root))

    root = newTree([1, 2, 2, 3, 3, None, None, 4, 4])
    print(isBalanced(root))