from tree import Node

def makeTreeFromParentArray1(arr: list[int]) -> Node:
    node_dict: dict[int, Node] = {}
    
    root = -1
    for (node_idx, parent_idx) in enumerate(arr):
        if parent_idx == -1:
            root = node_idx
            continue
  
        node = node_dict[node_idx] if node_idx in node_dict else Node(node_idx)
        parent = node_dict[parent_idx] if parent_idx in node_dict else Node(parent_idx)

        if parent.left is None:
            parent.left = node
        else:
            parent.right = node

        node_dict[node_idx] = node
        node_dict[parent_idx] = parent

    return node_dict[root]

def makeTreeFromParentArray2(arr: list[int]) -> Node:
    node_dict: dict[int, Node] = {}
    
    root = -1
    for (node_idx, parent_idx) in enumerate(arr):
        if parent_idx == -1:
            root = node_idx
            continue

        if node_idx in node_dict:
            node = node_dict[node_idx] # old node
        else:
            node = Node(node_idx) # new node
            node_dict[node_idx] = node

        if parent_idx in node_dict:
            parent = node_dict[parent_idx] # old parent
            # old parent -> need to check
            if parent.left is None:
                parent.left = node
            else:
                parent.right = node
        else:
            parent = Node(parent_idx) # new parent
            node_dict[parent_idx] = parent
            # new parent -> no need to check
            parent.left = node

    return node_dict[root]



if __name__ == '__main__':
    arr = [1, 5, 5, 2, 2, -1, 3]
    root = makeTreeFromParentArray2(arr)
    print(root)

    arr = [-1, 0, 0, 1, 1, 3, 5]
    root = makeTreeFromParentArray2(arr)
    print(root)