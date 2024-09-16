#include <stdio.h>
#include <stdlib.h>

// node "class" 
struct node {
  double data;
  struct node *next;
  struct node *previous;
};

// create a root node
struct node *createNode(double d) {
  struct node *n = (struct node*) malloc(sizeof(struct node));
  // set data to d and next/previous to null (since it is the first node)
  n->data = d;
  n->next = NULL;
  n->previous = NULL;
  return n;
}
// add a node to the end of the list
struct node *addNode(struct node *n, double d) {
  struct node *new_n = (struct node*) malloc(sizeof(struct node));
  // next is null because this is the new endpoint and new_n.previous is
  // current position. n.next is the new node we added
  new_n->data = d;
  new_n->next = NULL;
  new_n->previous = n;
  n->next = new_n;
  return new_n;
}
// remove a node from the list
void removeNode(struct node *n) {
  // if the previous node exists then the previous node's next pointer should point to the location of the removed node's next pointer
  if (n->previous != NULL) {
    n->previous->next = n->next;
  }
  // similarly, if the next node exists, then the next node's previous pointer should point to the location of removed node's previous pointer
  if (n->next != NULL) {
    n->next->previous = n->previous;
  }
  free(n);
}

// loop through list and print value
void printNodes(struct node *n) {
  struct node *current = n;
  while (current != NULL) {
    printf("%f\n", current->data);
    current = current->next;
  }
}

int main(void) {
  // test cases
  struct node *n1 = createNode(1.0);
  struct node *n2 = addNode(n1, 2.0);
  struct node *n3 = addNode(n2, 3.0);
  struct node *n4 = addNode(n3, 4.0);

  printNodes(n1);

  removeNode(n1);
  
  printf("After removal of root node n1:\n");
  printNodes(n2);
 
  
  removeNode(n3);
  printf("After removal of middle node n3:\n");

  printNodes(n2);

  removeNode(n4);
  printf("After removal of end node n4:\n");
  printNodes(n2);

  free(n2);
}
