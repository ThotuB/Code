from tree import Node, newTree

def isSameTree(p: Node, q: Node) -> bool:
    if not p and not q:
        return True
    if not p or not q:
        return False

    return p.val == q.val and isSameTree(p.left, q.left) and isSameTree(p.right, q.right)


if __name__ == "__main__":
    p = newTree([1, 2, 3, 4, 5])
    q = newTree([1, 2, 3, 4, 5])
    print(isSameTree(p, q))

    p = newTree([1, 2, 3, 4, 5])
    q = newTree([3, 2, 1, 4, 5])
    print(isSameTree(p, q))