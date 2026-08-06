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

A binary tree is a hierarchical data structure composed of nodes where each node has at most two children. It can referred to as the left child and the right child. 
Due to having a non-linear structure, a binary tree can be traversed in multiple ways. One such way is preorder traversal which is a Depth First (DFS) Traversal technique.<br><br>

Preorder traversal is a DFS tree traversal technique that first visits the current node, traverses the left sub-tree as far as it can and then traverses the right sub-tree.

## Algorithm
1. Visit the root node.
2. Then, recursively traverse the left subtree.
3. Finally, recursively traverse the right subtree.

## Algorithm for Pre-Order Binary Tree Traversal

![Example Tree](https://media.geeksforgeeks.org/wp-content/uploads/20240426095901/preorderout.png)

1. Start at the root node (1).
2. Visit the root node then print it.
3. Traverse the left subtree of the root (2).
4. Visit the root of the left subtree (2) and print it.
5. Traverse the left subtree of the node 2(4) and visit 4 and print it.
6. Backtrack to the node 2 and traverse its right subtree (5) and visit and print it.
7. Backtrack to the root node (1).
8. Traverse the right subtree of root (3).
9. Visit the root of the right subtree (3) and print it.
10. The pre-order traversal of the binary tree: 1, 2, 4, 5, 3

Following is the algorithm of the pre-order binary tree traversal:
```
preOrder(root) {
     If root is NULL
          return
     visit root->data
     preOrder(root->leftChild)
     preOrder(root->rightChild)
     return
}
```

## Example Code

```
// C Program to illustrate how to implement the preorder
// binary tree traversal
#include <stdio.h>
#include <stdlib.h>
​
// creating tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
​
// utility function to create a node with given value
struct TreeNode* createNode(int val)
{
    struct TreeNode* newNode
        = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
​
// preorder traversal
void preorderTraversal(struct TreeNode* root)
{
    // if the current node is empty
    if (root == NULL)
        return;
​
    // visiting node
    printf("%d ", root->val);
​
    // going to left subtree
    preorderTraversal(root->left);
    // going to right subtree
    preorderTraversal(root->right);
}
​
// drive code
int main()
{
    // creating example tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
​
    printf("Preorder Traversal: ");
    preorderTraversal(root);
​
    return 0;
}
```

Output:
- Preorder Traversal: 1 2 4 5 3 

# IN-ORDER TRAVERSAL
- Inorder traversal is a DFS traversal technique where we try to traverse as deep as possible in the tree from the current node.
- In the inorder traversal, we first visit all the left subtree, then visit the current node and at last, we visit the right subtree.

## Inorder Traversal Overview
1. Visit the left subtree.
2. Visit the root node.
3. Visit the right subtree.

## Example Algorithm
![Example Tree](https://media.geeksforgeeks.org/wp-content/uploads/20240430112609/ex1.png)

1. Start at the root node (1).
2. Visit the left subtree of the root (2).
3. Visit the left subtree of 2(4) then 4 does not have any children so print it.
4. Backtrack to the node (2) and print it.
5. Move to the right subtree of the node 2 (5). Print it.
6. Backtrack to the root node (1).
7. Move to the right subtree of the node 1 (3).
8. Visit the left subtree of 3 and there is no nodes.
9. Visit the node (3) and print it.
10. The in-order traversal of the tree is: 4, 2, 5, 1, 3

## Example Code

```
// C program to show how to implement the binary tree
// traversal
#include <stdio.h>
#include <stdlib.h>
​
// node of the tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
​
// utility function to create a node
struct Node* createNode(int data)
{
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
​
// Function to perform inorder traversal
void inorderTraversal(struct Node* root)
{
    // cheking if the current node is NULL
    if (!root)
        return;
    // traversing left subtree
    inorderTraversal(root->left);
    // traversing current node
    printf("%d ", root->data);
    // traversing right subtree
    inorderTraversal(root->right);
}
​
int main()
{
    // Example tree creation
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
​
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    return 0;
}
```

Output
- Inorder Traversal: 4 2 5 1 3 

# POST-ORDER TRAVERSAL

A binary tree is a hierarchical data structure in computer science. 
- Each node in a binary tree can have at most two children: a left child and a right child.
- Postorder traversal involves visiting the left subtree first, followed by the right subtree, and finally the root node.
  
## Workflow of Postorder Traversal

Flowchart-PostOrder_Traversal<br>
Left-->right-->root

## Algorithm for Postorder Traversal in C
Following is the algorithm for the postorder traversal of the binary tree in C:

![Workflow of Postorder Traversal](https://media.geeksforgeeks.org/wp-content/uploads/20240526161246/Flowchart-PostOrder_Traversal.png)

Start
- Traverse left subtree using recursion.
- Traverse right subtree using recursion
- Visit the root node
- Repeat steps 3-5 until root node != NULL
Stop
- C Program for Postorder Traversal in a Binary Tree
- The following program demonstrates how we can implement the postorder traversal in a binary tree in C:

## Example

Input:   
     1        
   /   \       
  2    3      
 / \  / \    
4  5 6   7

Output:
- Postorder Traversal : 4 5 2 6 7 3 1
  
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

