class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data

        self.left = left
        self.right = right

    def __str__(self):
        def preorder(node):
            if not node:
                return ''
            return str(node.data) + ' ' + preorder(node.left) + preorder(node.right)

        return preorder(self)