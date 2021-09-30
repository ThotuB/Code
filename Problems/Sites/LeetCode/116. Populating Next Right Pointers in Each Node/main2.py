from tree import Node, newTree, printTree

def connect(root: Node) -> Node:
    if not root:
        return root
    
    def connectNextLayer(root: Node):
        node = root
        right_node = None
        while node:
            if node.left:
                node.left.next = node.right
            if right_node:
                right_node.next = node.left
                
            right_node = node.right
            node = node.next

    node = root
    while node:
        connectNextLayer(node)
        node = node.left
    
    return root
    

if __name__ == '__main__':
    root = newTree(4)

    root = connect(root)

    printTree(root)

