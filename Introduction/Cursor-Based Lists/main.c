#include <stdio.h>
#include <stdlib.h>
#include "cursorbased.h"

int main() {
    VHeap vh;
    initVHeap(&vh);
    
    List myList = -1;
    List list2 = -1;
    
    visualize(vh);
    displayList(vh, myList);
    displayList(vh, list2);
    
    insertFront(&vh, &myList, 10);
    displayList(vh, myList);
    displayList(vh, list2);
    
    insertFront(&vh, &myList, 20);
    displayList(vh, myList);
    displayList(vh, list2);
    
    insertFront(&vh, &list2, 35);
    displayList(vh, myList);
    displayList(vh, list2);
    
    visualize(vh);
    
}