#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "myheader.h"


/* =========================
   LIST CREATION
   ========================= */

void initList(List *list, int size)
{
    list->elems = malloc(sizeof(int) * size);

    if (list->elems == NULL) {
        list->size = 0;
        list->count = 0;
        return;
    }

    list->size = size;
    list->count = 0;
}


List newList(int size)
{
    List list;

    list.elems = malloc(sizeof(int) * size);

    if (list.elems == NULL) {
        list.size = 0;
        list.count = 0;
        return list;
    }

    list.size = size;
    list.count = 0;

    return list;
}


void freeList(List *list)
{
    free(list->elems);

    list->elems = NULL;
    list->count = 0;
    list->size = 0;
}


/* =========================
   RESIZE HELPER
   ========================= */

static bool resizeList(List *list)
{
    int newSize;
    int *temp;

    newSize = (list->size == 0) ? 1 : list->size * 2;

    temp = realloc(list->elems, sizeof(int) * newSize);

    if (temp == NULL) {
        return false;
    }

    list->elems = temp;
    list->size = newSize;

    return true;
}


/* =========================
   INSERT SORTED
   ========================= */

bool insertSorted(List *list, int item)
{
    int i;

    /* Resize if list is full */
    if (list->count == list->size) {
        if (!resizeList(list)) {
            return false;
        }
    }

    /*
     * Start at the end and move larger
     * elements one position to the right.
     */
    i = list->count;

    while (i > 0 && list->elems[i - 1] > item) {
        list->elems[i] = list->elems[i - 1];
        i--;
    }

    list->elems[i] = item;
    list->count++;

    return true;
}


/* =========================
   INSERT FIRST
   ========================= */

bool insertFirst(List *list, int item)
{
    int i;

    if (list->count == list->size) {
        if (!resizeList(list)) {
            return false;
        }
    }

    /*
     * Shift all elements one position
     * to the right.
     */
    for (i = list->count; i > 0; i--) {
        list->elems[i] = list->elems[i - 1];
    }

    list->elems[0] = item;
    list->count++;

    return true;
}


/* =========================
   INSERT LAST
   ========================= */

bool insertLast(List *list, int item)
{
    if (list->count == list->size) {
        if (!resizeList(list)) {
            return false;
        }
    }

    list->elems[list->count] = item;
    list->count++;

    return true;
}


/* =========================
   INSERT AT INDEX
   ========================= */

bool insertIndex(List *list, int item, int index)
{
    int i;

    /*
     * Valid insertion indexes:
     *
     * 0 <= index <= count
     */
    if (index < 0 || index > list->count) {
        return false;
    }

    if (list->count == list->size) {
        if (!resizeList(list)) {
            return false;
        }
    }

    /*
     * Shift elements to the right.
     */
    for (i = list->count; i > index; i--) {
        list->elems[i] = list->elems[i - 1];
    }

    list->elems[index] = item;
    list->count++;

    return true;
}


/* =========================
   DELETE FIRST
   ========================= */

bool deleteFirst(List *list)
{
    int i;

    if (list->count == 0) {
        return false;
    }

    /*
     * Shift everything to the left.
     */
    for (i = 0; i < list->count - 1; i++) {
        list->elems[i] = list->elems[i + 1];
    }

    list->count--;

    return true;
}


/* =========================
   DELETE LAST
   ========================= */

bool deleteLast(List *list)
{
    if (list->count == 0) {
        return false;
    }

    list->count--;

    return true;
}


/* =========================
   DELETE AT INDEX
   ========================= */

bool deleteIndex(List *list, int index)
{
    int i;

    /*
     * Valid deletion indexes:
     *
     * 0 <= index < count
     */
    if (index < 0 || index >= list->count) {
        return false;
    }

    /*
     * Shift everything after the index
     * one position to the left.
     */
    for (i = index; i < list->count - 1; i++) {
        list->elems[i] = list->elems[i + 1];
    }

    list->count--;

    return true;
}


/* =========================
   DELETE FIRST OCCURRENCE
   ========================= */

bool deleteFirstOccur(List *list, int item)
{
    int i;

    /*
     * Find first occurrence.
     */
    for (i = 0; i < list->count; i++) {

        if (list->elems[i] == item) {

            /*
             * Shift elements left.
             */
            for (; i < list->count - 1; i++) {
                list->elems[i] = list->elems[i + 1];
            }

            list->count--;

            return true;
        }
    }

    return false;
}


/* =========================
   DELETE LAST OCCURRENCE
   ========================= */

bool deleteLastOccur(List *list, int item)
{
    int i;

    /*
     * Search backwards for the last occurrence.
     */
    for (i = list->count - 1; i >= 0; i--) {

        if (list->elems[i] == item) {

            /*
             * Shift everything after it left.
             */
            for (; i < list->count - 1; i++) {
                list->elems[i] = list->elems[i + 1];
            }

            list->count--;

            return true;
        }
    }

    return false;
}


/* =========================
   DELETE ALL OCCURRENCES
   ========================= */

bool deleteAllOccur(List *list, int item)
{
    int i;
    int newCount = 0;
    bool deleted = false;

    /*
     * Keep only elements that are NOT
     * equal to item.
     */
    for (i = 0; i < list->count; i++) {

        if (list->elems[i] != item) {

            list->elems[newCount] = list->elems[i];
            newCount++;

        }
        else {
            deleted = true;
        }
    }

    list->count = newCount;

    return deleted;
}


/* =========================
   BOOLEAN SEARCH
   ========================= */

bool boolSearch(List list, int item)
{
    int i;

    for (i = 0; i < list.count; i++) {

        if (list.elems[i] == item) {
            return true;
        }
    }

    return false;
}


/* =========================
   INDEX SEARCH
   ========================= */

int indexSearch(List list, int item)
{
    int i;

    for (i = 0; i < list.count; i++) {

        if (list.elems[i] == item) {
            return i;
        }
    }

    /*
     * -1 means not found.
     */
    return -1;
}


/* =========================
   COUNT OCCURRENCES
   ========================= */

int countOccur(List list, int item)
{
    int i;
    int count = 0;

    for (i = 0; i < list.count; i++) {

        if (list.elems[i] == item) {
            count++;
        }
    }

    return count;
}


/* =========================
   DISPLAY
   ========================= */

void display(List list)
{
    int i;

    printf("{");

    for (i = 0; i < list.count; i++) {

        printf("%d", list.elems[i]);

        if (i < list.count - 1) {
            printf(", ");
        }
    }

    printf("}\n");
}
