class Node:
    def __init__(self, data):
        self.data = data
        self.children = []
        

    def insert(self, data) -> 'Node':
        new_node = Node(data)
        self.children += [new_node]

        return new_node

    def __repr__(self):
        return str(self.data)
        

class Tree:
    def __init__(self, data):
        self.root = Node(data)
        self.node_map = {data: self.root}


    def addChild(self, node: Node, data) -> None:
        if data in self.node_map:
            raise ValueError("Node already exists")    
            
        new_node = node.insert(data)
        self.node_map[data] = new_node

    
    def __getitem__(self, data):
        return self.node_map[data]


def presetTree() -> Tree:
    tree = Tree(0)
    tree.addChild(tree[0], 1)
    tree.addChild(tree[0], 2)
    tree.addChild(tree[0], 3)
    tree.addChild(tree[1], 4)
    tree.addChild(tree[1], 5)
    tree.addChild(tree[2], 6)
    tree.addChild(tree[3], 7)
    tree.addChild(tree[6], 8)

    return tree


if __name__ == "__main__":
    tree = presetTree()
    