These notes are taken from my Programming 2 Notes.<br>
Link to the Programming Notes repository: [Stacks & Queues](https://github.com/ShadowZarina/Programming-Notes/tree/main/CIS%201201/Stacks%20%26%20Queues)

# STACKS

```
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
} Stack;

bool isEmpty(Stack *s) {
    return (s->top == 0);
}

bool isFull(Stack *s) {
    return (s->top == MAX);
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Cannot push!");
        return;
    }
    
    s->arr[s->top] = value;
    printf("\n%d pushed.", s->arr[s->top++]);
    // Or simply: printf("\n%d pushed.", value);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Cannot pop!");
        return;
    }
    
    printf("\n%d popped.", s->arr[--s->top]);
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Cannot peek!");
        return;
    }
    
    printf("\nThe value at the top is %d.", s->arr[s->top - 1]);
}

void print(Stack *s) {
    int i;
    printf("\nStack: \n");
    for (i = 0; i < s->top; i++) {
        printf("%d ", s->arr[i]);
    }
}

int main() {
    Stack *s = malloc(sizeof(Stack));
    s->top = 0;
    
    push(s, 10);
    push(s, 20);
    push(s, 30);
    print(s);
    pop(s);
    peek(s);
    push(s, 40);
    print(s);
    
    free(s);
    
    return 0;
}
```

# QUEUES

```
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

bool isEmpty(Queue *q) {
    return (q->front == q->rear);
}

bool isFull(Queue *q) {
    return (q->rear == MAX);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Cannot enqueue!");
        return;
    }
    
    q->arr[q->rear] = value;
    printf("%d enqueued.", q->arr[q->rear]);
    q->rear++;
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Cannot dequeue!");
        return;
    }
    
    printf("%d dequeued.", q->arr[q->front]);
    q->front++;
}

void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Cannot peek!");
        return;
    }
    
    printf("The value in the front is %d.", q->arr[q->front]);
}

void print(Queue *q) {
    int i;
    for (i = q->front; i < q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
}

int main() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    print(q);
    dequeue(q);
    peek(q);
    enqueue(q, 40);
    print(q);
    
    return 0;
}
```
