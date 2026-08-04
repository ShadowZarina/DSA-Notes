# BINARY TREE TRAVERSAL
Going through a Tree by visiting every node, one node at a time, is called traversal.

Since Arrays and Linked Lists are linear data structures, there is only one obvious way to traverse these: 
start at the first element, or node, and continue to visit the next until you have visited them all.

But since a Tree can branch out in different directions (non-linear), there are different ways of traversing Trees.

There are two main categories of Tree traversal methods:
- ***Breadth First Search (BFS)*** is when the nodes on the same level are visited before going to the next level in the tree. This means that the tree is explored in a more sideways direction.
- ***Depth First Search (DFS)*** is when the traversal moves down the tree all the way to the leaf nodes, exploring the tree branch by branch in a downwards direction.

There are three different types of DFS traversals:
- Pre-order
- In-order
- Post-order

# PRE-ORDER TRAVERSAL


# IN-ORDER TRAVERSAL


# POST-ORDER TRAVERSAL

A binary tree is a hierarchical data structure in computer science. 
- Each node in a binary tree can have at most two children: a left child and a right child.
  
## Example

Input:   
     1        
   /   \       
  2    3      
 / \  / \    
4  5 6   7

Output:
- Postorder Traversal : 4 5 2 6 7 3 1
- Postorder Tree Traversal in Binary Tree in C
- The postorder traversal is a way of visiting all the nodes of a binary tree in a specific order.
- It involves visiting the left subtree first, followed by the right subtree, and finally the root node.

## Workflow of Postorder Traversal

Flowchart-PostOrder_Traversal<br>
Left-->right-->root

## Algorithm for Postorder Traversal in C
Following is the algorithm for the postorder traversal of the binary tree in C:

Start
- Traverse left subtree using recursion.
- Traverse right subtree using recursion
- Visit the root node
- Repeat steps 3-5 until root node != NULL
Stop
- C Program for Postorder Traversal in a Binary Tree
- The following program demonstrates how we can implement the postorder traversal in a binary tree in C:

```
// C Program for Postorder Traversal in a Binary Tree
#include <stdio.h>
#include <stdlib.h>

// __________ CODE FOR BINARY TREE IMPLEMENTATION __________

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node in a Binary Tree
struct Node* createNode(int data)
{
    // Allocate memory for the new node
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    // Initialize node data and children pointers
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// __________ CODE FOR POSTORDER TRAVERSAL  __________

// Function to perform postorder traversal
void postorderTraversal(struct Node* root)
{
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// driver code
int main()
{
    struct Node* root = NULL;

    // Create the binary tree
    /*     1
                 /   \
             2    3
                / \  / \
                4  5 6  7
    */
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform postorder traversal
    printf("Postorder traversal of the binary tree is:\n");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
```

# REFERENCES

[Pre-Order Traversal](https://www.w3schools.com/dsa/dsa_algo_binarytrees_preorder.php)<br>
[Pre-Order Traversal in C](https://www.geeksforgeeks.org/c/preorder-tree-traversal-of-binary-tree-in-c/)<br>
[In-Order Traversal](https://www.w3schools.com/dsa/dsa_algo_binarytrees_inorder.php)<br>
[In-Order Traversal in C](https://www.geeksforgeeks.org/c/inorder-tree-traversal-in-binary-tree-in-c/)<br>
[Post-Order Traversal](https://www.w3schools.com/dsa/dsa_algo_binarytrees_postorder.php)<br>
[Post-Order Traversal in C](https://www.geeksforgeeks.org/c/postorder-tree-traversal-in-binary-tree-in-c/)

