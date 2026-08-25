#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>

typedef struct {
    int *elems;
    int count;
    int size;
} List;


/* LIST CREATION */

void initList(List *list, int size);
List newList(int size);
void freeList(List *list);


/* INSERT */

bool insertSorted(List *list, int item);
bool insertFirst(List *list, int item);
bool insertLast(List *list, int item);
bool insertIndex(List *list, int item, int index);


/* DELETE */

bool deleteFirst(List *list);
bool deleteLast(List *list);
bool deleteIndex(List *list, int index);
bool deleteFirstOccur(List *list, int item);
bool deleteLastOccur(List *list, int item);
bool deleteAllOccur(List *list, int item);


/* SEARCH */

bool boolSearch(List list, int item);
int indexSearch(List list, int item);
int countOccur(List list, int item);


/* DISPLAY */

void display(List list);

#endif
