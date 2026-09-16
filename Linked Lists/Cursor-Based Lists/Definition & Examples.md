# Definition

- A cursor-based linked list in C is a technique used to simulate a traditional pointer-based linked list using a fixed-size array of structures.
- This approach is particularly useful in environments where dynamic memory allocation (malloc, free) is unavailable, restricted, or too slow.
- Instead of physical memory addresses, the "pointers" are simply array indices (integers).

# Example Syntax

## 1. Define Data Structures

- We define a Node structure containing data and a next index.
- A global or static array named CURSOR_SPACE acts as our virtual heap.
- We use 0 to act as the NULL sentinel, and index 0 itself serves as the header for the freelist (the pool of available memory).

```
#include <stdio.h>
#include <stdbool.h>

#define SPACE_SIZE 100
#define UNUSED_DATA -1

// Struct acting as a memory block
typedef struct {
    int data;
    int next; // Acts as the "pointer" (array index)
} Node;

// The memory pool (Virtual Heap)
Node CURSOR_SPACE[SPACE_SIZE];

```
## 2. Initialize Memory Pool
- Before any list operations, we must link all array slots together into a single forward chain.
- This chain forms our freelist, which tracks unallocated blocks.
```
void init_cursor_space(void) {
    // Index 0 acts as the head of the freelist
    for (int i = 0; i < SPACE_SIZE - 1; i++) {
        CURSOR_SPACE[i].data = UNUSED_DATA;
        CURSOR_SPACE[i].next = i + 1; // Point to the next sequential array slot
    }
    // The last element points to 0 (our cursor NULL)
    CURSOR_SPACE[SPACE_SIZE - 1].data = UNUSED_DATA;
    CURSOR_SPACE[SPACE_SIZE - 1].next = 0; 
}
```
## 3. Simulate Memory Allocation (malloc & free)
- Instead of requesting memory from the operating system, we pop and push indices from our pre-allocated freelist.

```
// Simulates malloc()
int cursor_alloc(void) {
    int p = CURSOR_SPACE[0].next; // Get the first available slot from freelist
    if (p != 0) {
        CURSOR_SPACE[0].next = CURSOR_SPACE[p].next; // Remove it from freelist
    }
    return p; // Returns 0 if memory is full
}

// Simulates free()
void cursor_free(int p) {
    if (p == 0) return;
    
    // Wipe data and place the node back at the front of the freelist
    CURSOR_SPACE[p].data = UNUSED_DATA;
    CURSOR_SPACE[p].next = CURSOR_SPACE[0].next;
    CURSOR_SPACE[0].next = p;
}
```

## 4. Core List Operations
- With allocation handled, standard linked list mechanisms like insertion, deletion, and traversal can be implemented using array index manipulation.
- Insert at Front
```
bool insert_front(int *head, int value) {
    int new_node = cursor_alloc();
    if (new_node == 0) {
        printf("Error: Out of memory!\n");
        return false;
    }
    
    CURSOR_SPACE[new_node].data = value;
    CURSOR_SPACE[new_node].next = *head; // Point new node to current head
    *head = new_node;                    // Update head to be the new node
    return true;
}
```
- Delete a Value
```
bool delete_value(int *head, int value) {
    if (*head == 0) return false; // Empty list

    int current = *head;
    int previous = 0;

    // Search for the node containing the value
    while (current != 0 && CURSOR_SPACE[current].data != value) {
        previous = current;
        current = CURSOR_SPACE[current].next;
    }

    if (current == 0) return false; // Value not found

    // If it is the head node
    if (previous == 0) {
        *head = CURSOR_SPACE[current].next;
    } else {
        CURSOR_SPACE[previous].next = CURSOR_SPACE[current].next;
    }

    cursor_free(current);
    return true;
}
```
- Traverse/Print List
```
void print_list(int head) {
    int current = head;
    printf("List: ");
    while (current != 0) {
        printf("%d -> ", CURSOR_SPACE[current].data);
        current = CURSOR_SPACE[current].next;
    }
    printf("NULL\n");
}
```
## 5. Execution Example
- Here is how you initialize the environment and manage a dynamic list using the definitions above:
```
int main(void) {
    // 1. Initialize the global cursor space
    init_cursor_space();

    // 2. Create an empty list (0 acts as NULL)
    int my_list = 0;

    // 3. Perform operations
    insert_front(&my_list, 10);
    insert_front(&my_list, 20);
    insert_front(&my_list, 30);
    print_list(my_list); // Output: 30 -> 20 -> 10 -> NULL

    printf("Deleting 20...\n");
    delete_value(&my_list, 20);
    print_list(my_list); // Output: 30 -> 10 -> NULL

    return 0;
}
```

# Key Takeaways
- No Pointers Used: The next member is a pure integer tracking indices.
- Logical vs. Physical Order: Elements that are logically adjacent in the linked list do not need to be physically next to each other in the array.
- Memory Limits: The maximum capacity of all concurrent lists combined is bound by SPACE_SIZE.
