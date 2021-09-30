class Node:
    def __init__(self, data, left: 'Node'=None, right: 'Node'=None):
        self.data = data
        self.left = left
        self.right = right

    def insert(self, data) -> None:
        if data < self.data:
            if not self.left:
                self.left = Node(data)
                return                

            self.left.insert(data)
        else:
            if not self.right:
                self.right = Node(data)
                return

            self.right.insert(data)

class BinTree:
    def __init__(self):
        self.root = None


    def insert(self, *data):
        def insertData(data):
            if not self.root:
                self.root = Node(data)
                return

            self.root.insert(data)

        for d in data:
            insertData(d)


if __name__ == '__main__':
    tree = BinTree()
    tree.insert(4, 2, 6, 1, 3, 5, 7)
    print(tree.root.data)
    print(tree.root.left.data)
    print(tree.root.right.data)
    print(tree.root.left.left.data)
    print(tree.root.left.right.data)
    print(tree.root.right.left.data)
    print(tree.root.right.right.data)