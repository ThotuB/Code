from tree import Node, newTree, printTree

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

