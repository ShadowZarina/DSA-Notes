#include<stdio.h>
#include "myheader.h"


int main() {
    Queue q1 = newQueue();
    
    display(q1);
    visualize(q1);
    
    Queue q2;
    initQueue(&q2);
    
    display(q2);
    visualize(q2);
    
    
    enqueue(&q1, 10);
    display(q1);
    enqueue(&q1, 20);
    display(q1);
    enqueue(&q1, 30);
    display(q1);
    enqueue(&q1, 40);
    display(q1);
    
    // 
    enqueue(&q1, 50);
    display(q1);
    enqueue(&q1, 60);
    display(q1);
    
    visualize(q1);
    
    
    return 0;
}



myheader.h

  #ifndef MYHEADER_H
#define MYHEADER_H

#define MAX 5

// Auxilliary Struct
typedef struct {
    int id;
    char name[20];
    double price;
} Product;

typedef struct {
    int elems[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
Queue newQueue();

int isEmpty(Queue q);
int isFull(Queue q);

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int front(Queue q);
/*
void enqueue(Queue *q, Product p);
Product dequeue(Queue *q);
Product front(Queue q);
*/

void display(Queue q);
void visualize(Queue q);

// Auxilliary Functions
Product newProduct(int id, char *name, double price);
void displayProduct(Product p);

#endif

myheader.c

  #include<stdio.h>

#define MAX 5

void initQueue(Queue *q) {
    q->rear = 0; // can be 1 or MAX - 1 as long as rear and front are the same
    q->front = 0;
}

// Similar to Queue but returns queue
Queue newQueue() {
    Queue q;
    
    q.rear = MAX - 1;
    q.front = MAX - 1;
    
    return q;
}

int isEmpty(Queue q) { // without count implementation
    return q.front == q.rear;
}
int isFull(Queue q){
    return q.front == (q.rear + 1) % MAX;
}

void enqueue(Queue *q, int item) {
    if(!isFull(*q) {
        q->elems[q->rear] = item;
        q->rear = (q->rear+1) % MAX;
    }
}

int dequeue(Queue *q) {
    if(!isEmpty(*q) {
        q->front = (q->front + 1) % MAX;
    }
}

int front(Queue q) {
    int data = -1;
    if(!isEmpty(q)) {
        data = q.elems[q.front];
    }
    return data;
}

/*
Product dequeue(Queue *q) {
    if(!isEmpty(*q) {
        q->front = (q->front + 1) % MAX;
    }
}

Product front(Queue q) {
    int data = -1;
    if(!isEmpty(q)) {
        data = q.elems[q.front];
    }
    return data;
}
*/

void display(Queue q) {
    printf("{");
    while (!isEmpty(q)) {
        printf("%d", dequeue(&q));
        if(!isEmpty(q)) {
            printf(", ");
        }
    }
    printf("}\n");
}

void visualize(Queue q) {
    printf("%-10s | %s\n", "INDEX", "VALUE");
    for (int i = 0; i < MAX; ++i) {
        printf("%-10d | %d", i, q.elems[i]);
        
        if (i == q.front) {
            printf(" -> front");
        }
        
        // Two for the cases where "i" has the same values as front and rear
        
        if (i == q.rear) {
            printf(" -> rear");
        }
        printf("\n");
    }
}

/*
Product newProduct(int id, char *name, double price) {
    Product p;
    if(!isFull()) {
        p.id = id;
        strcpy(p.name, name);
        p.price = price;
        
        return p;
    }
}

void displayProduct(Product p) {
    
}

// Create a function that would filter and remove product prices below a given threshold


*/
Queue filterProduct(Queue *q, double limit_price);
