class Node:
    def __init__(self, val: int = 0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right

def newTree(nums):
    if not nums:
        return None

    root = Node(nums[0])

    queue = [root]
    i = 1
    while i < len(nums):
        node = queue.pop(0)

        if nums[i] != None:
            node.left = Node(nums[i])
            queue.append(node.left)
        i += 1
        
        if i < len(nums):
            if nums[i] != None:
                node.right = Node(nums[i])
                queue.append(node.right)
            i += 1

    return root