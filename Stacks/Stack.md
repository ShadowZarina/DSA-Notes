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

# ANDREA CODE

MAIN.C

#include<stdio.h>
#include<stdbool.h>

#define MAX 10

typedef struct {
    Student stud;
    int top;
} StackArray;

typedef struct {
    int ID;
    char name[20];
    char program[20];
    int year;
    char sex;
} Student;

void initStack(StackArray *s) {
    s->top = -1;
}

bool isEmpty (StackArray s){
    return (s->top == -1);
}

bool isFull (StackArray s){
    return (s->top == MAX - 1);
}

bool push(StackArray *s, Student st) {
    if (isFull(s)) {
        printf("Stack Overflow!");
        return;
    }
    printf("Pushed Student #%d into the stack", (s->top)++);
    s->student[top] = st;
    return true;
}

bool pop(StackArray *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!");
        return;
    }
    printf("Popped Student #%d from the stack", (s->top)--);
    return true;
}

// help me
Student peek(StackArray s, Student st) {
    printf("Student #%c\n", (s.top)+1);
    printf("ID: %d\n", s.stud[top].ID);
    printf("Name: %s\n", s.stud[top].name);
    printf("Program: %s\n", s.stud[top].program);
    printf("Year: %d\n", s.stud[top].year);
    printf("Sex: %c\n", s.stud[top].sex);
    return 
}

void visualize(StackArray s) {
    int i;
    for (i = 0; i < s->top; i++) {
        printf("Student #%c\n", i+1);
        printf("ID: %d\n", s.stud[i].ID);
        printf("Name: %s\n", s.stud[i].name);
        printf("Program: %s\n", s.stud[i].program);
        printf("Year: %d\n", s.stud[i].year);
        printf("Sex: %c\n", s.stud[i].sex);
    }
}

int main() {
    StackArray *s;
    Student *st;
    int choice;
    int n = 1;
    
    initStack(&s);
    //input the data outside, push in the input
    
    do {
        printf("Enter an operation (1-5):\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Visualize\n5. End\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                push(s, st)
                break;
            case 2:
                pop(s, st);
                break;
            case 3:
                peek(s, st);
                break;
            case 4:
                visualize(s);
                break;
            case 5:
                n = 0;
                printf("Program ended.");
                break;
            default:
                printf("Invalid choice!");
        }
        
    } while (n == 1);
    
    return 0;
}

NEW.C
HEADER.H

# FILES

new.c - hidden
header.h - function prototypes
main.c - main
problem.c - answer
