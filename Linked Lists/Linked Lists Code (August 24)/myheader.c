#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"


// C FILE THAT STORES ALL FUNCTIONS

/* LIST BASIC FUNCTIONS */

void initList(List *list)
{
    list->head = NULL;
    list->count = 0;
}


List newList(void)
{
    List list;

    list.head = NULL;
    list.count = 0;

    return list;
}


void freeList(List *list)
{
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->count = 0;
}


/* INSERT SORTED */

bool insertSorted(List *list, int item)
{
    Node *newNode;
    Node *current;

    // Create new node
    newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return false;
    }

    newNode->data = item;
    newNode->next = NULL;

    // Empty list 
    if (list->head == NULL) {
        list->head = newNode;
        list->count++;
        return true;
    }

    if (item <= list->head->data) {
        newNode->next = list->head;
        list->head = newNode;
        list->count++;
        return true;
    }

    current = list->head;

    while (current->next != NULL &&
           current->next->data < item) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    list->count++;

    return true;
}


/* INSERT FIRST */

bool insertFirst(List *list, int item)
{
    Node *newNode;

    newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return false;
    }

    newNode->data = item;
    newNode->next = list->head;

    list->head = newNode;
    list->count++;

    return true;
}


/* INSERT LAST */

bool insertLast(List *list, int item)
{
    Node *newNode;
    Node *current;

    newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return false;
    }

    newNode->data = item;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->count++;
        return true;
    }

    current = list->head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    list->count++;

    return true;
}


/* INSERT AT INDEX */

bool insertIndex(List *list, int item, int index)
{
    Node *newNode;
    Node *current;
    int i;

    if (index < 0 || index > list->count) {
        return false;
    }

    newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return false;
    }

    newNode->data = item;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
        list->count++;

        return true;
    }

    current = list->head;

    for (i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    list->count++;

    return true;
}


/* DELETE FIRST */

bool deleteFirst(List *list)
{
    Node *temp;

    if (list->head == NULL) {
        return false;
    }

    temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->count--;

    return true;
}


/* DELETE LAST */

bool deleteLast(List *list)
{
    Node *current;

    // If empty
    if (list->head == NULL) {
        return false;
    }

    // If one node
    if (list->head->next == NULL) {
        free(list->head);

        list->head = NULL;
        list->count--;

        return true;
    }

    // Find second to last node
    current = list->head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    list->count--;

    return true;
}


/* DELETE AT INDEX */

bool deleteIndex(List *list, int index)
{
    Node *current;
    Node *temp;
    int i;

    if (index < 0 || index >= list->count) {
        return false;
    }

    // Delete first node 
    if (index == 0) {
        return deleteFirst(list);
    }

    // Find node before target
    current = list->head;

    for (i = 0; i < index - 1; i++) {
        current = current->next;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;

    return true;
}


/* DELETE FIRST OCCURRENCE */

bool deleteFirstOccur(List *list, int item)
{
    Node *current;
    Node *temp;

    // Empty list
    if (list->head == NULL) {
        return false;
    }

    // If item is in first node
    if (list->head->data == item) {
        return deleteFirst(list);
    }

    current = list->head;

    while (current->next != NULL) {
        
        if (current->next->data == item) {
            temp = current->next;
            current->next = temp->next;
            free(temp);
            list->count--;

            return true;
        }
        current = current->next;
    }
    return false;
}


/* DELETE LAST OCCURRENCE */

bool deleteLastOccur(List *list, int item)
{
    Node *current;
    Node *lastOccur;
    Node *beforeLastOccur;

    lastOccur = NULL;
    beforeLastOccur = NULL;

    current = list->head;

    while (current != NULL) {

        if (current->data == item) {
            lastOccur = current;
        }

        current = current->next;
    }

    // If item does not exist
    if (lastOccur == NULL) {
        return false;
    }

    // If last occurrence is the head
    if (lastOccur == list->head) {
        return deleteFirst(list);
    }

    current = list->head;

    while (current->next != lastOccur) {
        current = current->next;
    }

    beforeLastOccur = current;
    beforeLastOccur->next = lastOccur->next;
    free(lastOccur);
    list->count--;

    return true;
}


/* DELETE ALL OCCURRENCES */

bool deleteAllOccur(List *list, int item)
{
    Node *current;
    Node *temp;
    bool deleted = false;

    while (list->head != NULL &&
           list->head->data == item) {

        temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->count--;

        deleted = true;
    }

    // Delete matching nodes after head
    if (list->head != NULL) {

        current = list->head;
        while (current->next != NULL) {

            if (current->next->data == item) {

                temp = current->next;
                current->next = temp->next;
                free(temp);
                list->count--;

                deleted = true;
            }
            else {
                current = current->next;
            }
        }
    }

    return deleted;
}


/* SEARCH */

// Return true if item exists (boolean search)

bool boolSearch(List list, int item)
{
    Node *current = list.head;

    while (current != NULL) {

        if (current->data == item) {
            return true;
        }

        current = current->next;
    }

    return false;
}


// Return index of first occurrence (index search)

int indexSearch(List list, int item)
{
    Node *current = list.head;
    int index = 0;

    while (current != NULL) {

        if (current->data == item) {
            return index;
        }

        current = current->next;
        index++;
    }

    return -1;
}


// Return number of occurrences (count occurrences)

int countOccur(List list, int item)
{
    Node *current = list.head;
    int count = 0;

    while (current != NULL) {

        if (current->data == item) {
            count++;
        }
        current = current->next;
    }
    return count;
}


/* DISPLAY */

void display(List list)
{
    Node *current = list.head;

    printf("{");
    while (current != NULL) {

        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("}\n");
}
