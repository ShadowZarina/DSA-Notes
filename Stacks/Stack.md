# WHAT IS A STACK?
**STACK ADT**
- A data structure that can hold many elements.
- **LIFO**: Last In First Out
- Stacks can be implemented by using arrays or linked lists.
- Stacks can be used to implement undo mechanisms, to revert to previous states, to create algorithms for depth-first search in graphs, or for backtracking.

# Stack Operations
Important Operations (ONLY 3):
- **Push**: Insert a new element on the stack.
- **Pop**: Delete and return the top element from the stack.
- **Peek**: Return the top element on the stack.
Other Implementation:
- **initStack**: Initialize the stack.
- **isEmpty**: Check if the stack is empty.
- **isFull**: Check if the stack is full.

## Array vs Linked List Operations
- Arrays are fastest with rear elements, linked lists are fastest with front elements

**ARRAY**
- insertRear
- deleteRear

**LINKED LIST**
- insertFront
- deleteFront


## Stacks in Mathematical Operations
post-polish

## Stacks in Sorting
- You only need 2 stacks to sort elements: 1 stack for elements that match CRITERIA, and 1 temporary stack for all elements that do NOT
