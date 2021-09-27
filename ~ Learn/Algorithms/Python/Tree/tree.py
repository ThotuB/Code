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

class Tree:
    def __init__(self):
        self.root = None


    def insert(self, *data):
        def insertData(data):
            if not self.root:
                self.root = Node(data)

            self.root.insert(data)

        for d in data:
            insertData(d)


if __name__ == '__main__':
    tree = Tree()
    tree.insert(10, 5, 15, 2, 7, 12, 20)