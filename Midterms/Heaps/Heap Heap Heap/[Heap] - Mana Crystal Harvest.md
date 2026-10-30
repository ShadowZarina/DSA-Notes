# 2. [Heap] - Mana Crystal Harvest
by Gran Sabandal

Max Heap · write one function:<br>
_int harvestMana(MaxHeap *H, int k)_

## Story Version
- You are a wizard in the Crystal Caves. Each crystal stores some mana. You have exactly k turns before the cave collapses.
- On each turn you pick one crystal, absorb all of its mana, and the crystal slowly regrows to half its previous mana (rounded down).
- A greedy wizard always picks the richest crystal on every turn. Return the total mana absorbed after k turns.

## Direct Version
Given a max heap of N non-negative integers and an integer k, repeat k times:
1. Remove the largest value m.
2. Add m to a running total.
3. Insert m / 2 (integer division).
Return the total. If the heap is empty, stop early.


## Sample Outputs
### Sample Output 1
```
Number of crystals and number of turns: 1 5
N crystal mana values: 100
Total mana harvested: 193
```
### Sample Output 2
```
Number of crystals and number of turns: 3 4
N crystal mana values: 0 0 0
Total mana harvested: 0
```
### Sample Output 3
```
Number of crystals and number of turns: 4 6
N crystal mana values: 1 1 1 1
Total mana harvested: 4
```

## Code & Boilerplates

### MANA.C
```
#include <stdio.h>
#include "mana.h"

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
#include "mana.h"

int main() {
    MaxHeap H;
    int n, k, i, m;
    initHeap(&H);

    printf("Number of crystals and number of turns: ");
    scanf("%d %d", &n, &k);

    printf("N crystal mana values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        insert(&H, m);
    }

    printf("Total mana harvested: %d\n", harvestMana(&H, k));

    return 0;
}
```
### PROBLEM.C

WRITE YOUR ANSWER IN THIS BOILERPLATE!
```
#include <stdio.h>
#include "mana.h"

/*  TODO: Return the total mana harvested after k turns.
    Each turn: take the richest crystal, add its mana, put back half (integer division).
    Available: size(*H), isEmpty(*H), deleteMax(H), insert(H, x), peekMax(*H) */
int harvestMana(MaxHeap *H, int k) {
    // Code here...
}
```

## ANSWER
```
int harvestMana(MaxHeap *H, int k) {
    int total = 0;
    int mana;
    int i;

    for (i = 0; i < k && !isEmpty(*H); i++) {
        mana = deleteMax(H);

        total += mana;

        if (mana / 2 > 0) {
            insert(H, mana / 2);
        }
    }

    return total;
}
```
