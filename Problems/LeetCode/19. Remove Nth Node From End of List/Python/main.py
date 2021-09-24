class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

#* LISTNODE FUCNTIONS
def addNode(head: ListNode, val: int):
    node = head
    while node.next:
        node = node.next
    
    node.next = ListNode(val)

def removeNode(head: ListNode, prev: ListNode, node: ListNode):
    if prev:
        prev.next = node.next
    else:
        head = node.next

    return head

def printList(node: ListNode):
    while node:
        print(node.val)
        node = node.next

#********************

def removeNthFromEnd(head: ListNode, n: int) -> ListNode:
    size = 0

    def removeNth(prev: ListNode, node: ListNode):
        if node.next:
            removeNth(node, node.next)
        
        nonlocal size
        size += 1

        if size == n:
            nonlocal head
            head = removeNode(head, prev, node)

    removeNth(None, head)

    return head


if __name__ == "__main__":
    head = ListNode(1)

    # printList(head)
    printList(removeNthFromEnd(head, 1))

