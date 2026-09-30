// 3_closed_cursor_based.c
// CODE BOILERPLATE PROVIDED BY SIR GRAN

#include <stdio.h>
#include <ctype.h>

#define MAX 10
#define EMPTY '?'
#define DELETED '!'

typedef struct {
    char data;
    int next;
} VirtualNode;

typedef struct {
    VirtualNode table[MAX]; // Prime Area: indices 0..5, Synonym Area: indices 6..9
    int avail;             // Points to head of free synonym list
} CursorDict;

int HASH(char key) {
    return (toupper(key) - 'A') % 6; // Hash directly into prime area (0..5)
}

void displayDict(CursorDict D) {
    printf("\n--- CLOSED HASH DICTIONARY (Cursor-Based / Synonym Area) ---\n");
    printf("Avail Head Index: %d\n", D.avail);
    printf("%5s | %-5s | %5s\n", "IDX", "DATA", "NEXT");
    printf("%5s - %5s - %5s\n", "----", "----", "----");
    for (int i = 0; i < MAX; i++) {
        printf(" %5d  |  %-5c  |  %5d\n", i, D.table[i].data, D.table[i].next);
    }
}

// TODO EXERCISES FOR STUDENTS:

void initDict(CursorDict *D) {
    // TODO: 
    // 1. Prime area (0..5): data = EMPTY, next = -1
    // 2. Synonym area (6..9): link next pointers sequentially to form free list
    // 3. Set D->avail = 6
}

void insertDict(CursorDict *D, char elem) {
    // TODO: 
    // 1. Compute H = HASH(elem)
    // 2. If table[H] is EMPTY or DELETED, store elem directly at H
    // 3. Else, pull index from D->avail, store elem, and append to table[H].next chain
}

void deleteDict(CursorDict *D, char elem) {
    // TODO: Search key in prime slot or linked synonym chain. Unlink node and recycle index to avail.
}

int main() {
    CursorDict D;
    initDict(&D);

    printf("Inserting 'A', 'G', 'M' (All hash to Prime Index 0)...\n");
    insertDict(&D, 'A');
    insertDict(&D, 'G');
    insertDict(&D, 'M');
    displayDict(D);

    printf("Deleting 'G'...\n");
    deleteDict(&D, 'G');
    displayDict(D);

    return 0;
}
