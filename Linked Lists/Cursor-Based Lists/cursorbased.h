#ifndef CURSORBASED_H
#define CURSORBASED_H

#define MAX 10 
#define BLANK 1000

typedef int Pos;

typedef struct {
    int data;
    Pos next;
} SType;

typedef struct {
    SType elems[MAX]; 
    int avail;
} VHeap;

typedef int List;

void initVHeap(VHeap *vh);
int allocSpace(VHeap *vh);
void freeSpace(VHeap *vh, int i);
void visualize(VHeap vh);
void insertFront(VHeap *vh, List *list, int item);
void displayList(VHeap vh, List list);

#endif