class Node:
    def __init__(self, val: int = 0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

def newTree(layers: int, index: int=1) -> Node:
    if layers == 0:
        return None
    
    node = Node(index)
    node.left = newTree(layers-1, index*2)
    node.right = newTree(layers-1, index*2+1)

    return node


def printTree(root: Node):
    output = ''
    def printTreeLayer(root: Node):
        nonlocal output
        node = root
        while node:
            output += f'{node.val} '
            node = node.next
        output += '# '
        

    node = root
    while node:
        printTreeLayer(node)
        node = node.left

    print(output)

def connect(root: Node) -> Node:
    if not root:
        return root
    
    left_node = root # left_node: root -> left -> left -> ...
    while left_node:
        layer_node = left_node # layer_node: left_node -> next -> next -> ...
        while layer_node:
            if layer_node.left:
                layer_node.left.next = layer_node.right
            if layer_node.right:
                layer_node.right.next = layer_node.next.left if layer_node.next else None

            layer_node = layer_node.next

        left_node = left_node.left

    return root
    

if __name__ == '__main__':
    root = newTree(4)

    root = connect(root)

    printTree(root)

