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
- **Visualize**:
- **Display**:

## Array vs Linked List Operations
- Arrays are fastest with rear elements, linked lists are fastest with front elements

**ARRAY**
- insertRear
- deleteRear

**LINKED LIST**
- insertFront
- deleteFront

# STACK EXAMPLES

## Array-based Stack Implementation
- uses a Stack struct with data[MAX] and top
  
```
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
	int data[MAX_SIZE];
	int top;
} Stack;

void push(Stack* stack, int element) {
	if (stack->top == MAX_SIZE - 1) {
		printf("Stack Overflow\n");
		return;
	}
	stack->data[++stack->top] = element;
}

int pop(Stack* stack) {
	if (stack->top == -1) {
		printf("Stack Underflow\n");
		return -1; // Return a sentinel value indicating error
	}
	return stack->data[stack->top--];
}

int peek(Stack* stack) {
	if (stack->top == -1) {
		printf("Stack is empty\n");
		return -1; // Return a sentinel value indicating error
	}
	return stack->data[stack->top];
}

int main() {
	Stack stack;
	stack.top = -1;

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);

	printf("Peek: %d\n", peek(&stack));
	printf("Pop: %d\n", pop(&stack));
	printf("Peek: %d\n", peek(&stack));

	return 0;
}
```
## Linked List-based Stack Implementation
- uses TWO structs: one for the whole stack and one for each node
```
typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* top;
} Stack;
```


```
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* top;
} Stack;

void push(Stack* stack, int element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->next = stack->top;
	stack->top = newNode;
}

int pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("Stack Underflow\n");
		return -1; // Return a sentinel value indicating error
	}
	Node* temp = stack->top;
	int data = temp->data;
	stack->top = temp->next;
	free(temp);
	return data;
}

int peek(Stack* stack) {
	if (stack->top == NULL) {
		printf("Stack is empty\n");
		return -1; // Return a sentinel value indicating error
	}
	return stack->top->data;
}

int main() {
	Stack stack;
	stack.top = NULL;

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);

	printf("Peek: %d\n", peek(&stack));
	printf("Pop: %d\n", pop(&stack));
	printf("Peek: %d\n", peek(&stack));

	return 0;
}
```

## Stacks in Mathematical Operations
post-polish

## Stacks in Sorting
- You only need 2 stacks to sort elements: 1 stack for elements that match CRITERIA, and 1 temporary stack for all elements that do NOT
