class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    carry = 0

    l3 = ListNode()
    root = l3

    while l1 or l2:
        l1_val = l1.val if l1 else 0
        l2_val = l2.val if l2 else 0

        sum = l1_val + l2_val + carry
        carry = sum // 10
        digit = sum % 10

        l3.next = ListNode(digit)

        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
        l3 = l3.next

    if carry:
        l3.next = ListNode(1)

    return root.next


if __name__ == '__main__':
    l1 = ListNode(2, ListNode(4, ListNode(3)))
    l2 = ListNode(5, ListNode(6, ListNode(4)))

    l3 = addTwoNumbers(l1, l2)

    while l3:
        print(l3.val)
        l3 = l3.next