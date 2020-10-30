#include <stdio.h>
#include <stdlib.h>

typedef struct _dllist{
  int val;
  struct _dllist *prev, *next;
}dllist;

/// -------------- PRINTING FUNCTIONS --------------

void print_dllist_node(dllist *node){
  printf("%p <-prev- %p %d -next-> %p\n", node->prev, node, node->val, node->next);
}

void print_dllist_iter(dllist *root){
  if ( root == NULL){
    printf("%p - NULL\n", root);
  }
  for ( dllist *node = root; node != NULL ; node = node->next ){
    print_dllist_node( node );
  }
}

void print_dllist_recur(dllist *root){
  if ( root != NULL){
    print_dllist_node(root);
    print_dllist_recur(root->next);
  }
}

/// -------------- CREATING FUNCTION --------------

// ~~~~~~~~~~~~ METHOD I ~~~~~~~~~~~~
// - SET AMOUNT OF ELEMENTS

dllist *get_dllist_node1(dllist *prev, int val){
  dllist *node = (dllist*)malloc(sizeof(dllist));

  node->val = val;
  node->prev = prev;

  return node;
}

dllist *get_dllist1(dllist *prev, unsigned index, unsigned size){
  dllist *node = get_dllist_node1(prev, index);

  if ( index < size ){
    node->next = get_dllist1(node, index + 1, size);
    return node;
  }
  else {
    return NULL;
  }
}

// ~~~~~~~~~~~~ METHOD II ~~~~~~~~~~~~
// - DYNAMIC AMOUNT OF ELEMENTS

dllist *get_dllist_node2(dllist *prev, dllist *next, int val){
  dllist *node = (dllist*)malloc(sizeof(dllist));

  node->val = val;
  node->prev = prev;
  node->next = next;

  return node;
}

dllist *add_dllist_node2(dllist *root, dllist **node, int val){
  if ( root == NULL ){
    root = get_dllist_node2(NULL, NULL, val);
    *node = root;
  }
  else {
    (*node)->next = get_dllist_node2(*node, NULL, val);
    *node = (*node)->next;
  }

  return root;
}

// ~~~~~~~~~~~~ METHOD III ~~~~~~~~~~~~
// - DYNAMIC AMOUNT OF ELEMENTS
// - ORDERED

dllist *get_dllist_node3(dllist *prev, dllist *next, int val){
  dllist *node = (dllist*)malloc(sizeof(dllist));

  node->val = val;
  node->prev = prev;
  node->next = next;

  return node;
}

dllist *add_dllist_node3(dllist *root, int val){
  if ( root == NULL ){
    root = get_dllist_node3(NULL, NULL, val);
  }
  else {
    dllist *node = root, *prev = root, *next = root;

    if ( root->val < val){
      next = next->next;
      for ( ; node->next != NULL && node->next->val < val ; node = node->next ){
        prev = prev->next;
        next = next->next;
      }
      node = get_dllist_node3(prev, next, val);
      prev->next = node;
      if ( next != NULL ){
        next->prev = node;
      }
    }
    else if ( root->val > val ){
      node = get_dllist_node3(prev, next, val);
      next->prev = node;
      root = node;
    }
  }

  return root;
}

/// -------------- CHOOSING METHODE --------------

void choose_creating_method(dllist **root, FILE *stream){
  int method;

  printf("Method: ");
  scanf("%d", &method);

  if ( method == 1){
    unsigned rootSize;

    printf("Nr of Elems: ");
    scanf("%u",&rootSize);

    *root = (dllist*)malloc(sizeof(dllist));
    *root = get_dllist1(NULL, 0 , rootSize );
  }
  else if ( method == 2 ){
    dllist *node;
    int val;

    while ( fscanf(stream, "%d", &val) == 1 ){
      *root = add_dllist_node2(*root, &node, val);
    }
  }
  else if ( method == 3 ){
    int val;

    while ( fscanf(stream, "%d", &val) == 1 ){
      *root = add_dllist_node3(*root, val);
    }
  }
}

int main(){
  FILE *in = fopen("../in.txt", "r");
  dllist *root = NULL;

  choose_creating_method(&root, in);

  print_dllist_iter(root);
  return 0;
}
