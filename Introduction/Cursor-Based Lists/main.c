#include<stdio.h>
#include<stdlib.h>

// CURSOR-BASED -> LINKS DON'T FOLLOW INDEX, BUT ARE BASED ON AVAIL 
// 3 MAIN FUNCTIONS FOR CURSOR-BASED = Initialization, Allocation, Free Space

#define TOP 100 // set to any value you won't use
#define MAX 10 

typedef struct {
    int data;
    int next; // int as it uses index
} SType;

typedef struct {
    SType elems[MAX];
    int avail; // there will be 10 elements in avail
} VHeap;

/* Initialization function = values & construction of virtual heap */

void initVSpace(VHeap *vh) {
    int i;
    for (i = MAX - 1; i >= 0; --i) {
        vh->elems[i].data = 0;
        vh->elems[i].next = i-1; // access next in the SUBSTRUCT with dot notation
    }
    vh->avail = MAX - 1;
}

/* Allocation function = return integer equal to available value in the VHeap */

int allocSpace(VHeap *vh) { // asterisk as data will be modified
    int retVal = vh->avail; 
    
    if (retVal != 1) {
        vh->avail = vh->elems[vh->avail].next;
    }
    
    return retVal;
}

// front is the last index, rear is the first INDEX

/* Free Space function = free elems with an index not null */

void freeSpace(VHeap *vh, int index) {
    if (index != -1 && index < MAX) {
        vh->elems[index].next = vh->avail;
        vh->avail = index;
    }
    // if next is -1, you cannot free it as it's already free
}

/* Visualize function */

void visualize(VHeap vh) {
    printf("%10s | %10s |%10s\n", "Index", "Data", "Next");
    int i;
    for (i = 0; i < MAX; i++) {
        printf("%10d | %10d |%10d\n", i, vh.elems[i].data, vh.elems[i].next);
    }
}

int main() {
    VHeap heap;
    initVSpace(&heap);
    // int returned = allocSpace(&heap);
    // printf("%d", returned);
    visualize(heap);
    return 0;
}
