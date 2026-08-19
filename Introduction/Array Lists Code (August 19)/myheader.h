#ifndef MYHEADER_H
#define MYHEADER_H
#include<stdbool.h>

// START WITH THIS FILE; PLACE PROTOTYPES & STRUCTURES HERE

typedef struct {
	int *elems;
	// don't do elems[] or *elems[]
	int count;
	int size;
} List;

// function declarations
void initList(List *list, int size);
List newList(int size);

bool insertSorted(List *list, int item);
void display(List list);
// no need pointer for display as no values will change (retrieve only)

// CHALLENGE 3: IMPLEMENT ALL OTHER FUNCTIONS
// all inserts, all deletes (delete first, delete last, delete by index), 2 searches: return true or false, return index, count (no of occurrences)
// create new header called statistics.h for the mode, median, mean

bool insertFirst(List *list, int item);
bool insertLast(List *list, int item);
bool insertIndex(List *list, int item, int index);

bool deleteFirst(List *list);
bool deleteLast(List *list);
bool deleteIndex(List *list, int index);
bool deleteFirstOccur(List *list, int item);
bool deleteLastOccur(List *list, int item);
bool deleteAllOccur(List *list, int item);

bool boolSearch(List list, int item);
int indexSearch(List list, int item);
int countOccur(List list);

#endif
