#include <stdio.h>
#include <stdlib.h>
#include "cursorbased.h"

void initVHeap(VHeap *vh) {
    vh->avail = MAX-1;
    for(int i = vh->avail; i >= 0; --i) {
        vh->elems[i].next = i-1;
        vh->elems[i].data = BLANK;
    }    
}

int allocSpace(VHeap *vh) {
    int retVal = vh->avail;
    if(retVal != -1) {
        vh->avail = vh->elems[retVal].next;
    }
    return retVal;
}

void freeSpace(VHeap *vh, int i) {
    if(i != -1 && i < MAX) {
        vh->elems[i].next = vh->avail;
        vh->avail = i;
    }    
}

void visualize(VHeap vh) {
    printf("%5s | %5s | %5s\n", "INDEX", "DATA", "NEXT");
    for(int i = 0; i < MAX; ++i) {
        printf("%5d |", i);
        if(vh.elems[i].data != BLANK) {
            printf(" %5d |", vh.elems[i].data);
        } else {
            printf(" %5s |", "");
        }
        printf(" %5d\n", vh.elems[i].next);
    }
}
void insertFront(VHeap *vh, List *list, int item) {
    List temp = allocSpace(vh);
    
    vh->elems[temp].data = item;
    vh->elems[temp].next = *list;
    *list = temp;
}

void displayList(VHeap vh, List list) {
    printf("{");
    while(list != -1) {
        printf("%5d", vh.elems[list].data);
        list = vh.elems[list].next;
    }
    printf("}\n");
}