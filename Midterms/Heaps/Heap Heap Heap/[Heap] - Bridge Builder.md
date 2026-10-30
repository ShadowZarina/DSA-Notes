# 2. [Heap] - Mana Crystal Harvest
by Gran Sabandal

Min Heap · write one function: <br>
_int minBridgeCost(MinHeap *H)_
## Story Version
- A river splits the kingdom, and the villagers have collected N wooden planks of different lengths. To cross, all of the planks must be joined into one long bridge.
- The village carpenter can join two planks at a time. Joining planks of length a and b costs a + b gold and produces one plank of length a + b.
 -The village treasury is small. Find the minimum total gold needed to join all of the planks into one.
## Direct Version
Given a min heap of N positive integers, repeat while there are at least two values:
1. Remove the two smallest values a and b.
2. Add a + b to the total cost.
3. Insert a + b.
Return the total cost. If N is 0 or 1, the cost is 0.


## Sample Outputs
### Sample Output 1
```
N (number of planks): 4
N plank lengths: 4 3 2 6
Minimum gold spent: 29
```
### Sample Output 2
```
N (number of planks): 0
N plank lengths:
Minimum gold spent: 0
```
### Sample Output 3
```
N (number of golems): 2
N golem weights: 5 5

Arena is empty. No golem survives!
```

## Code & Boilerplates

### BRIDGE.H
```
#ifndef BRIDGE_H
#define BRIDGE_H

#define MAX 100

typedef struct {
    int Elem[MAX];
    int lastNdx;            /* index of last element, -1 if empty */
} MinHeap;

void initHeap(MinHeap *H);

int isEmpty(MinHeap H);

int size(MinHeap H);

void swap(int *a, int *b);

/* Inserts x and bubbles it up. */
void insert(MinHeap *H, int x);

/* Removes and returns the SMALLEST value. Returns -1 if empty. */
int deleteMin(MinHeap *H);

/* Returns the smallest value without removing it. Returns -1 if empty. */
int peekMin(MinHeap H);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
int minBridgeCost(MinHeap *H);

#endif
```
### MAIN.C

```
#include <stdio.h>
#include "bridge.h"

int main() {
    MinHeap H;
    int n, i, p;
    initHeap(&H);

    printf("N (number of planks): ");
    scanf("%d", &n);

    printf("N plank lengths: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p); insert(&H, p);
    }

    printf("\n");
    printf("Minimum gold spent: %d\n", minBridgeCost(&H));

    return 0;
}
```
### PROBLEM.C

WRITE YOUR ANSWER IN THIS BOILERPLATE!
```
#include <stdio.h>
#include "bridge.h"

/*  TODO: Return the minimum total gold needed to join all planks into one.
    Joining planks of length a and b costs a + b gold and makes one plank of length a + b.
    Available: size(*H), isEmpty(*H), deleteMin(H), insert(H, x), peekMin(*H) */
    
int minBridgeCost(MinHeap *H) {
    // Code here...
}
```

## ANSWER
```
int minBridgeCost(MinHeap *H) {
    int total = 0;
    int first, second, joined;

    while (size(*H) > 1) {
        first = deleteMin(H);
        second = deleteMin(H);

        joined = first + second;
        total += joined;

        insert(H, joined);
    }

    return total;
}
```
