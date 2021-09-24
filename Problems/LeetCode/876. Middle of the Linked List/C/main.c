#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* newListNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    
    return node;
}

void addListNode(ListNode* head, int val) {
    ListNode* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newListNode(val);
}

ListNode* middleNode(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    ListNode* head = newListNode(1);
    addListNode(head, 2);
    addListNode(head, 3);
    addListNode(head, 4);
    addListNode(head, 5);

    printf("%d\n", middleNode(head)->val);

    addListNode(head, 6);

    printf("%d\n", middleNode(head)->val);
    return 0;
}