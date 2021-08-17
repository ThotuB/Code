#include <stdio.h>
#include <stdlib.h>

#define SPACE_SIZE 3
#define NUMBS 20

typedef struct _btree {
    int val;
    struct _btree *left, *right;
} btree;

/// -------------- PRINTING FUNCTIONS (BINARY TREE) --------------

void print_spaces(unsigned size) {
    for (unsigned i = 0; i < size * SPACE_SIZE; i++) {
        printf(" ");
    }
}

void print_btnode(btree *cntNode, unsigned details) {
    if (details) {
        printf("%p <-left- %p ", cntNode->left, cntNode);
    }
    printf("%d", cntNode->val);
    if (details) {
        printf(" -right-> %p", cntNode->right);
    }
    printf("\n");
}

void print_tree_inorder(btree *cntNode, unsigned spaces) {
    if (cntNode != NULL) {
        print_tree_inorder(cntNode->left, spaces + 1);
        print_spaces(spaces);
        print_btnode(cntNode, 0);
        print_tree_inorder(cntNode->right, spaces + 1);
    }
}

/// -------------- CREATING FUNCTIONS (BINARY TREE) --------------

btree *get_btree_node(btree *node, btree *left, btree *right, int val) {
    node = (btree *)malloc(sizeof(btree));

    node->val = val;
    node->left = left;
    node->right = right;

    return node;
}

btree *add_btree_node(btree *BTNode, int val) {
    if (BTNode == NULL) {
        BTNode = get_btree_node(BTNode, NULL, NULL, val);
    } else {
        if (val < BTNode->val) {
            BTNode->left = add_btree_node(BTNode->left, val);
        } else if (val > BTNode->val) {
            BTNode->right = add_btree_node(BTNode->right, val);
        }
    }

    return BTNode;
}

void get_btree(btree **root) {
    int val;

    for (int i = 0; i < NUMBS; i++) {
        val = rand() % 100;
        *root = add_btree_node(*root, val);
    }
}

int main() {
    btree *rootBT = NULL;

    get_btree(&rootBT);

    printf("Binary Tree:\n");
    print_tree_inorder(rootBT, 0);
    return 0;
}
