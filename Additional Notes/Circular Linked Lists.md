> Tutorial by Adrian Cauguiran

# CIRCULAR LINKED LISTS

## CIRCULAR LINKED LISTS vs NORMAL LINKED LISTS

- In a normal (singly) Linked List, the last node points to NULL to mark the end. 
- In a circular linked list, the last node points back to the first node (head), creating a closed loop so you can traverse the whole structure from any starting point without hitting a null.

Structure and Traversal
- Normal Linked List: Has a clear start and a dead-end NULL tail. Traversal stops when you hit NULL.
- Circular Linked List: Has no end. Traversal must check if you have looped back to your starting node to avoid infinite loops

# SAMPLE CODE

#include <stdio.h>

// every time we refer to head we can just say "tail->next"

typedef struct Node {
  int data;
  struct Node *next;
} node, *nodePtr;

nodePtr createNode (int data) {
  nodePtr newNode = malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

nodePtr insertAtBeginning() {
  
}

int main() {

}



