#include <stdio.h>
#include <stdlib.h>

// node "class"
struct node {
  int data;
  struct node *parent;
  struct node *left;
  struct node *right;
};

typedef struct node node;

// create a root note
node *createRoot(int d) {
  node *root = (node*)malloc(sizeof(node));
  root->data = d;
  root->parent = NULL;
  root->left = NULL;
  root->right = NULL;
  return root;
}
// add a node, connected to a parent's left if possible, otherwise right,
// else return an error and abort
node *addNode(int d, node *par) {
  node *n = (node*)malloc(sizeof(node));
  n->data = d;
  n->parent = par;
  n->left = NULL;
  n->right = NULL;
  if (par->left == NULL) {
    par->left = n;
  }
  else if (par->right == NULL) {
    par->right = n;
  }
  else {
    printf("No available nodes for the parent, aborting.\n");
    free(n);
  }
  return n;
}
// depth first search
void dfs(node *root) {
  if (root == NULL) {
    return;
  }
  dfs(root->left);
  printf("%d\n", root->data);
  dfs(root->right);
}

int main(void) {
  node *root = createRoot(1);
  node *n2 = addNode(2, root);
  node *n3 = addNode(3, root);
  node *n4 = addNode(4, n2);
  node *n5 = addNode(5, n2);
  node *n6 = addNode(6, n3);

  // Visit left subtree of root, visit left subtree of node 2, print 4,
  // step up and print 2, visit right subtree of node 2 and print 5.
  // Return to root and print 1, visit right subtree of root node, 
  // visit left tree of node 3, print 6, step up and print 3.
  dfs(root);

  free(root);
  free(n2);
  free(n3);
  free(n4);
  free(n5);
  free(n6);
}
