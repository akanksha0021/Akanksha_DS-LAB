#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int data;
struct node *left;
struct node *right;
struct node *parent;
}node;

typedef struct binary_search_tree {
node *root;
}binary_search_tree;

node* new_node(int data) {
node *n = malloc(sizeof(node));
n->data = data;
n->left = NULL;
n->right = NULL;
n->parent = NULL;

return n;
}

binary_search_tree* new_binary_search_tree() {
binary_search_tree *t = malloc(sizeof(binary_search_tree));
t->root = NULL;

return t;
}

node* minimum(binary_search_tree *t, node *x) {
while(x->left != NULL)
  x = x->left;
return x;
}

void insert(binary_search_tree *t, node *n) {
node *y = NULL;
node *temp = t->root;
while(temp != NULL) {
  y = temp;
  if(n->data < temp->data)
    temp = temp->left;
  else
    temp = temp->right;
}
n->parent = y;

if(y == NULL) //newly added node is root
  t->root = n;
else if(n->data < y->data)
  y->left = n;
else
  y->right = n;
}

void transplant(binary_search_tree *t, node *u, node *v) {
if(u->parent == NULL) //u is root
  t->root = v;
else if(u == u->parent->left) //u is left child
  u->parent->left = v;
else //u is right child
  u->parent->right = v;

if(v != NULL)
  v->parent = u->parent;
}

void delete(binary_search_tree *t, node *z) {
if(z->left == NULL) {
  transplant(t, z, z->right);
  free(z);
}
else if(z->right == NULL) {
  transplant(t, z, z->left);
  free(z);
}
else {
  node *y = minimum(t, z->right); //minimum element in right subtree
  if(y->parent != z) {
    transplant(t, y, y->right);
    y->right = z->right;
    y->right->parent = y;
  }
  transplant(t, z, y);
  y->left = z->left;
  y->left->parent = y;
  free(z);
}
}

void inorder(binary_search_tree *t, node *n) {
if(n != NULL) {
  inorder(t, n->left);
  printf("%d\n", n->data);
  inorder(t, n->right);
}
}

int main() {
binary_search_tree *t = new_binary_search_tree();

node *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;

a = new_node(10);
b = new_node(20);
c = new_node(30);
d = new_node(100);
e = new_node(90);


insert(t, a);
insert(t, b);
insert(t, c);
insert(t, d);
insert(t, e);

delete(t, a);
delete(t, e);

inorder(t, t->root);

return 0;
}