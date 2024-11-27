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
