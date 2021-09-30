class Node:
    def __init__(self, data, left: 'Node'=None, right: 'Node'=None):
        self.data = data
        self.left = left
        self.right = right

    def preorder(self):
        print(self.data, end=" ")
        if self.left:
            self.left.preorder()
        if self.right:
            self.right.preorder()

    def inorder(self):
        if self.left:
            self.left.inorder()
        print(self.data, end=" ")
        if self.right:
            self.right.inorder()
    
    def postorder(self):
        if self.left:
            self.left.postorder()
        if self.right:
            self.right.postorder()
        print(self.data, end=" ")


def defaultTree():
    root = Node(1,
                Node(2,
                    Node(4,
                        Node(8),
                        Node(9,
                            None,
                            Node('d')
                        ),
                    ),
                    Node(5,
                        None,
                        Node('a')
                    ),
                ),
                Node(3,
                    Node(6,
                        Node('b'),
                        Node('c',
                            Node('e')
                        ),
                    ),
                    Node(7)
                )
            )

    return root


if __name__ == '__main__':
    root = defaultTree()
    root.preorder()
    print()
    root.inorder()
    print()
    root.postorder()