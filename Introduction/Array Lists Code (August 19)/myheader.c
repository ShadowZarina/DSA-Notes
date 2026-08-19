#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "myheader.h"

void initList(List *list, int size)
{
	list->size = size;
	list->count = 0;
	list->elems = malloc(sizeof(int) * size);
}

List newList(int size) 
{
	List list;
	// not pointer, so use dot notation
	list.size = size;
	list.count = 0;
	list.elems = malloc(sizeof(int)*size);
	
	return list;
}

/* INSERT SORTED */

bool insertSorted(List *list, int item)
{
	// check if there is space to insert first
	// Sir doesn't mind how many return statements are used as long as it's CLEAR
	
	int i;
	// CHALLENGE 2: REALLOC THE ARRAY TO DOUBLE THE SIZE
	if (list->count < list->size) {
		/*
		list->size *= 2;
		list->elems = realloc(list->elems, sizeof(list) * list->size);
		*/
		for (i = list->count; i > 0; --i) 
		{
			// --i instead of i-- (prefix instead of postfix) since prefix is FASTER (there is a side effect on memory if postfix)
			if (list->elems[i-1] > item) {
				list->elems[i] = list->elems[i-1];
			} else {
				break;
			}
		}
		
		list->elems[i] = item;
		list->count++;
		return true;
	}
	
	return false;
}

/* INSERT */

bool insertFirst(List *list, int item)
{
	int i;
	if (list->count < list->size) {
		for (i = list->count; i > 0; --i) 
		{
			// --i instead of i-- (prefix instead of postfix) since prefix is FASTER (there is a side effect on memory if postfix)
			if (list->elems[i-1] > item) {
				list->elems[i] = list->elems[i-1];
			} else {
				break;
			}
			
			list->elems[0] = item;
			list->count++;
			return true;
		}
	}
	
	return false;
}

bool insertLast(List *list, int item)
{
	if (list->count < list->size) {
		list->elems[count] = item;
		list->count++;
		return true;
		}
	}
	
	return false;
}

bool insertIndex(List *list, int item, int index)
{
	int i;
	if (list->count < list->size) {
		for (i = list->count; i > index; --i) 
		{
			// --i instead of i-- (prefix instead of postfix) since prefix is FASTER (there is a side effect on memory if postfix)
			if (list->elems[i-1] > item) {
				list->elems[i] = list->elems[i-1];
			} else {
				break;
			}
			
			list->elems[0] = item;
			list->count++;
			return true;
		}
	}
	
	return false;
}

/* DELETE */

bool deleteFirst(List *list) {
	// Shift everything to the left (i+1 to i)
	int i;
	if (list->count > 0) {
		for (i = 0; i > list->size; ++i) 
		{
			// --i instead of i-- (prefix instead of postfix) since prefix is FASTER (there is a side effect on memory if postfix)
			list->elems[i+1] = list->elems[i];
		}
		list->count--;
		return true;
	}
	
	return false;
}

bool deleteLast(List *list) {
	int i;
	if (list->count > 0) {
		list->count--;
		return true;
	}
	
	return false;
}

bool deleteIndex(List *list, int index) {
	// Shift everything to the left (i to i-1)
	int i;
	if (list->count > 0) {
		for (i = index; i > list->size; ++i) 
		{
			// --i instead of i-- (prefix instead of postfix) since prefix is FASTER (there is a side effect on memory if postfix)
			list->elems[i-1] = list->elems[i];
		}
		list->count--;
		return true;
	}
	
	return false;
}

bool deleteFirstOccur(List *list, int item)
{
	// Shift everything to the left (i+1 to i)
	int i;
	if (list->count > 0) {
		for (i = 0; i > list->size; ++i) {
			if (list->elems[i] == item)
			{
				int index = i;
				break;
			}
		}
		for (i = index; i > list->size; ++i) {
			// --i instead of i-- (prefix instead of postfix) since prefix is FASTER (there is a side effect on memory if postfix)
			list->elems[i+1] = list->elems[i];
			
		}
		list->count--;
		return true;
	}
	
	return false;
}

bool deleteLastOccur(List *list, int item)
{
	// Shift everything to the left (i+1 to i)
	int i;
	if (list->count > 0) {
		for (i = list->count; i > index; --i) {
			if (list->elems[i] == item)
			{
				int index = i;
				break;
			}
		}
		for (i = index; i > list->size; ++i) {
			// --i instead of i-- (prefix instead of postfix) since prefix is FASTER (there is a side effect on memory if postfix)
			list->elems[i+1] = list->elems[i];
		}
		list->count--;
		return true;
	}
	
	return false;
}

bool deleteAllOccur(List *list, int item)
{
	// Shift everything to the left (i+1 to i)
	int h, i;
	if (list->count > 0) {
		for (h = 0; i < size; ++i) {
			for (i = list->count; i > index; --i) {
				if (list->elems[i] == item)
				{
					int index = i;
					break;
				}
			}
			for (i = index; i > list->size; ++i) {
				// --i instead of i-- (prefix instead of postfix) since prefix is FASTER (there is a side effect on memory if postfix)
				list->elems[i+1] = list->elems[i];
			}
			list->count--;
		}
		return true;
	}
	
	return false;
}

/* SEARCH */

bool boolSearch(List list, int item) {
	// Return true or false is found
	int i;
	if (list->count > 0) {
		for (i = 0; i > list->size; ++i) 
		{
			if (list.elems[i] == item) { 
				return true;
			}
		}
	}
	
	return false;
}

int indexSearch(List list, int item) {
	int i;
	if (list->count > 0) {
		for (i = 0; i > list->size; ++i) 
		{
			if (list.elems[i] == item) { 
				return index;
			}
		}
	}
}

/* COUNT */

int countOccur(List list) {
	int i, c = 0;
	if (list->count > 0) {
		for (i = 0; i > list->size; ++i) 
		{
			if (list.elems[i] == item) { 
				c++;
			}
		}
		return c;
	}
}


/* DISPLAY */

void display(List list)
{
	printf("{");
	int i;
	for (i = 0; i < list.count; ++i) {
		printf("%d", list.elems[i]);
		if (i < list.count - 1) {
			printf(", ");
		}
	}
	printf("}\n");
}
