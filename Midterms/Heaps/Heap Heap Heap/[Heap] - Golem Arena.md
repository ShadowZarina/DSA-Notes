# 1. [Heap] - Golem Arena
by Gran Sabandal

Max Heap · write one function: 
_int lastGolem(MaxHeap *H)_

## Story Version
Welcome to the Golem Arena! The crowd only wants to see the two heaviest golems fight.<br>
Every round, the two heaviest golems step into the ring and smash into each other:<br>
- If they weigh the same, both shatter into dust.
- If one is heavier, the lighter golem is destroyed. The heavier golem survives but loses weight equal to the lighter golem's weight, and it limps back into the waiting line.
- The tournament ends when one golem or none is left. As the Arena Master, you must announce the weight of the champion. If no golem survives, return 0.

## Direct Version
Given a max heap of N positive integers, repeat until at most one value remains:
- Remove the largest value a and the second largest value b.
- If a != b, insert a - b.
  - Return the last remaining value, or 0 if the heap is empty.

## Sample Outputs
### Sample Output 1
```
N (number of golems): 0
N golem weights:
Arena is empty. No golem survives!
```
### Sample Output 2
```
N (number of golems): 1
N golem weights: 9
Champion golem weight: 9
```
### Sample Output 3
```
N (number of golems): 2
N golem weights: 5 5
Arena is empty. No golem survives!
```

## Code & Boilerplates

### GOLEM.C
```
#include <stdio.h>
#include "golem.h"

void initHeap(MaxHeap *H) { H->lastNdx = -1; }

int isEmpty(MaxHeap H) { return H.lastNdx == -1; }

int size(MaxHeap H) { return H.lastNdx + 1; }

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

/* Inserts x and bubbles it up. */
void insert(MaxHeap *H, int x) {
    int child, parent;
    if (H->lastNdx == MAX - 1) return;
    H->Elem[++H->lastNdx] = x;
    child = H->lastNdx;
    parent = (child - 1) / 2;
    while (child > 0 && H->Elem[child] > H->Elem[parent]) {
        swap(&H->Elem[child], &H->Elem[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

/* Removes and returns the LARGEST value. Returns -1 if empty. */
int deleteMax(MaxHeap *H) {
    int max, ndx = 0, largest, left, right;
    if (isEmpty(*H)) return -1;
    max = H->Elem[0];
    H->Elem[0] = H->Elem[H->lastNdx--];
    while (1) {
        largest = ndx; left = 2 * ndx + 1; right = 2 * ndx + 2;
        if (left <= H->lastNdx && H->Elem[left] > H->Elem[largest]) largest = left;
        if (right <= H->lastNdx && H->Elem[right] > H->Elem[largest]) largest = right;
        if (largest == ndx) break;
        swap(&H->Elem[ndx], &H->Elem[largest]);
        ndx = largest;
    }
    return max;
}

/* Returns the largest value without removing it. Returns -1 if empty. */
int peekMax(MaxHeap H) { return isEmpty(H) ? -1 : H.Elem[0]; }
```

### MAIN.C

```
#include <stdio.h>
#include "golem.h"

int main() {
    MaxHeap H;
    int n, i, w, result;
    initHeap(&H);

    printf("N (number of golems): ");
    scanf("%d", &n);

    printf("N golem weights: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &w);
        insert(&H, w);
    }

    result = lastGolem(&H);

    printf("\n");
    if (result == 0) printf("Arena is empty. No golem survives!\n");
    else printf("Champion golem weight: %d\n", result);

    return 0;
}
```
### GOLEM.H
```
#ifndef GOLEM_H
#define GOLEM_H

#include <stdio.h>

#define MAX 100

typedef struct {
    int Elem[MAX];
    int lastNdx;            /* index of last element, -1 if empty */
} MaxHeap;

void initHeap(MaxHeap *H);

int isEmpty(MaxHeap H);

int size(MaxHeap H);

void swap(int *a, int *b);

/* Inserts x and bubbles it up. */
void insert(MaxHeap *H, int x);

/* Removes and returns the LARGEST value. Returns -1 if empty. */
int deleteMax(MaxHeap *H);

/* Returns the largest value without removing it. Returns -1 if empty. */
int peekMax(MaxHeap H);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
int lastGolem(MaxHeap *H);

#endif
```
### PROBLEM.C

WRITE YOUR ANSWER IN THIS BOILERPLATE!
```
#include <stdio.h>
#include "golem.h"

/*  TODO: Return the weight of the last surviving golem, or 0 if none.
    Available: size(*H), isEmpty(*H), deleteMax(H), insert(H, x), peekMax(*H) */
    
int lastGolem(MaxHeap *H) {
    // Code here...
}
```

## ANSWER
```
#include <stdio.h>
#include "golem.h"

/*  TODO: Return the weight of the last surviving golem, or 0 if none.
    Available: size(*H), isEmpty(*H), deleteMax(H), insert(H, x), peekMax(*H) */
    
int lastGolem(MaxHeap *H) {
    int first, second;

    while (size(*H) > 1) {
        first = deleteMax(H);
        second = deleteMax(H);

        if (first != second) {
            insert(H, first - second);
        }
    }

    if (isEmpty(*H)) {
        return 0;
    }

    return peekMax(*H);
}
```
