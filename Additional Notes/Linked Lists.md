# WHAT ARE LINKED LISTS?

A linked list is a linear data structure made of nodes connected using pointers. Each node has: Data: The value stored in the node. Pointer: A reference to the next node.

Nodes are not stored in contiguous memory like arrays; they can be anywhere in memory.
To access a node, we start from the head and traverse sequentially through the list.

# SAMPLE CODE 1

```
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    // Create nodes
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Allocate memory
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Check allocation
    if (!head || !second || !third) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign data and link nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Print linked list
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    // Free allocated memory
    temp = head;
    while (temp != NULL)
    {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
```

# SAMPLE CODE 2

# SORTING

# SYNTAX

## BUBBLE SORT

### Step-by-Step Approach
1. Traverse the list multiple times, comparing adjacent nodes and swapping their positions by adjusting their links if the current node's data is greater than the next.
2. During each pass, the largest unsorted element moves to its correct position at the end of the list.
3. This process continues until no more swaps are needed, indicating that the list is sorted.

### Code

```
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to get the length of the linked list
int getLength(struct Node *head) {
    int len = 0;
    struct Node *curr = head;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

// Function to perform bubble sort on the linked list
struct Node *bubbleSort(struct Node *head) {
    struct Node *currNode = head;
    int len = getLength(head);
    int itr = 0;
    int swapped;

    // Iterating over the whole linked list
    while (itr < len) {
        struct Node *traverseNode = head;
        struct Node *prevNode = head;
        swapped = 0;

        while (traverseNode->next != NULL) {

            // Temporary pointer to store the next
            // pointer of traverseNode
            struct Node *ptr = traverseNode->next;
            if (traverseNode->data > ptr->data) {
                swapped = 1;
                if (traverseNode == head) {

                    // Performing swap operations and
                    // updating the head of the linked list
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode = ptr;
                    head = prevNode;
                }
                else {

                    // Performing swap operation
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode->next = ptr;
                    prevNode = ptr;
                }
                continue;
            }
            prevNode = traverseNode;
            traverseNode = traverseNode->next;
        }

        // If no swap occurred, break the loop
        if (!swapped) {
            break;
        }

        ++itr;
    }

    // Returning the head of the linked list
    return head;
}

void printList(struct Node *curr) {
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

struct Node *createNode(int x) {
    struct Node *newNode = 
      (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
  
  	// Create a hard-coded linked list:
	// 5 -> 1 -> 32 -> 10 -> 78
    struct Node *head = createNode(5);
    head->next = createNode(1);
    head->next->next = createNode(32);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(78);

    head = bubbleSort(head);
    printList(head);

    return 0;
}
```

## INSERTION SORT
- Gradually build a sorted portion of the list within the same memory space as the original ist
- It maintains a separate "sorted" portion of the list. For each node in the unsorted portion, it traverses the sorted portion from the beginning to find the correct spot and "relinks" it there.
- Only requires pointer manipulation (O(1)) -- adaptive!

### Step-by-Step Approach:

1. Start with an initially empty "sorted" list, which will be built by rearranging nodes from the original list.
2. Traverse the original linked list one node at a time.
    - For each node, find its correct position within the "sorted" portion of the list.
    - If the node should be placed at the beginning (i.e., it's smaller than the first node in the sorted list), it becomes the new head of the sorted list.
    - Otherwise, traverse the sorted list to find the correct position and insert the node there.
3. Continue this process until all nodes from the original list have been repositioned in the sorted order
4. Return the head of sorted list.

### Code

```
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

// Function to insert a new_node in the result list.
struct Node* sortedInsert(struct Node* createNode, 
                          struct Node* sorted) {
    
    // Special case for the head end
    if (sorted == NULL || 
        sorted->val >= createNode->val) {
        createNode->next = sorted;
        sorted = createNode;
    }
    else {
        struct Node* curr = sorted;
        
        // Locate the node before the point of insertion
        while (curr->next != NULL && 
               curr->next->val < createNode->val) {
            curr = curr->next;
        }
        createNode->next = curr->next;
        curr->next = createNode;
    }
    
    return sorted;
}

struct Node* insertionSort(struct Node* head) {
    
    // Initialize sorted linked list
    struct Node* sorted = NULL;
    struct Node* curr = head;
    
    // Traverse the given linked list and insert
    // every node to sorted
    while (curr != NULL) {
        
        // Store next for next iteration
        struct Node* next = curr->next;
        
        // Insert current in sorted linked list
        sorted = sortedInsert(curr, sorted);
        
        // Update current
        curr = next;
    }
    
    return sorted;
}

void printList(struct Node* curr) {
    while (curr != NULL) {
        printf(" %d", curr->val);
        curr = curr->next;
    }
}

struct Node* createNode(int x) {
    struct Node* node = 
     (struct Node*)malloc(sizeof(struct Node));
    node->val = x;
    node->next = NULL;
    return node;
}

int main() {
    
    // Create a hard-coded linked list:
    // 5->4->1->3->2
    struct Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(2);

    head = insertionSort(head);

    printList(head);

    return 0;
}
```

## SELECTION SORT
- Finds the smallest element in the unsorted part and swaps its value (or the node itself) with the first unsorted element.
- It minimizes swaps. In an array, it performs at most \(n\) swaps, which is useful if writing to memory is expensive.
- Not adaptive! (O(n^2)) best and worst case time

### Step-by-Step Approach (Changing Node Links)
1. The idea is to sort the linked list by rearranging its nodes rather than swapping their values.
2. We start by traversing the list from the head.
3. For each node, we maintain a pointer to find the minimum node in the remaining unsorted portion of the list.
4. Once the minimum node is found, we detach it from its current position and link it immediately after the last node of the sorted portion.
5. We adjust the links accordingly to maintain the list's structure.
6. This process is repeated until all nodes are sorted, ensuring the smallest nodes are positioned first in the portion.
7. To finalize the sorting, we reverse the sorted list to maintain the original order.
8. This final reversal ensures that the list is correctly ordered from smallest to largest.

### Code

```
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to sort the linked list using selection sort
struct Node* selectionSort(struct Node* head) {

    // If the list is empty or has one element
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* sorted = NULL;

    while (head != NULL) {
        struct Node* min_node = head;
        struct Node* prev_min = NULL;
        struct Node* curr = head;
        struct Node* prev = NULL;

        // Find the node with the minimum value
        while (curr != NULL) {
            if (curr->data < min_node->data) {
                min_node = curr;
                prev_min = prev;
            }
            prev = curr;
            curr = curr->next;
        }

        // Remove min_node from the unsorted part
        if (min_node == head) {
            head = head->next;
        } 
        else {
            prev_min->next = min_node->next;
        }

        // Insert min_node at the 
      	// beginning of the sorted list
        min_node->next = sorted;
        sorted = min_node;
    }

    // Reverse the sorted list to maintain 
  	// original order
    struct Node* prev = NULL;
    struct Node* curr = sorted;
    while (curr != NULL) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(struct Node* node) {
    struct Node* curr = node;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }
}

struct Node* createNode(int new_data) {
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int main() {
  
    // Create a hard-coded linked list:
    // 5 -> 3 -> 4 -> 1 -> 2
    struct Node* head = createNode(5);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(2);

    head = selectionSort(head);

    printList(head);

    return 0;
}
```

# REFERENCES 
The Programming 2 Repository has some sample problems on Linked Lists.<br>
Link to the Programming 2 Repository: [Linked List Repository](https://github.com/ShadowZarina/Programming-Notes/tree/main/CIS%201201/Linked%20Lists)<br>
W3Schools Link: [Linked List in C](https://www.geeksforgeeks.org/c/linked-list-in-c/)
