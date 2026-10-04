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

    for (int i = 0; i < 6; i++) {
        D->table[i].data = EMPTY;
        D->table[i].next = -1;
    }

    for (int i = 6; i < MAX; i++) {
        D->table[i].data = EMPTY;

        if (i == MAX - 1) {
            D->table[i].next = -1;
        } else {
            D->table[i].next = i + 1;
        }
    }

    D->avail = 6;
}

void insertDict(CursorDict *D, char elem) {
    // TODO: 
    // 1. Compute H = HASH(elem)
    // 2. If table[H] is EMPTY or DELETED, store elem directly at H
    // 3. Else, pull index from D->avail, store elem, and append to table[H].next chain

    int H = HASH(elem);

    // If the prime slot is empty or deleted,
    // insert the element directly into the prime area.
    if (D->table[H].data == EMPTY ||
        D->table[H].data == DELETED) {

        D->table[H].data = elem;
        D->table[H].next = -1;

        return;
    }

    // No free synonym slots available.
    if (D->avail == -1) {
        printf("Synonym area is full. Cannot insert '%c'.\n", elem);
        return;
    }

    // Get the first available synonym slot.
    int newIndex = D->avail;

    // Move avail to the next free slot.
    D->avail = D->table[newIndex].next;

    // Store the new element.
    D->table[newIndex].data = elem;
    D->table[newIndex].next = -1;

    // Traverse to the end of the synonym chain.
    int curr = H;

    while (D->table[curr].next != -1) {
        curr = D->table[curr].next;
    }

    // Append the new synonym.
    D->table[curr].next = newIndex;
}

void deleteDict(CursorDict *D, char elem) {
    // TODO: Search key in prime slot or linked synonym chain. Unlink node and recycle index to avail.

    int H = HASH(elem);

    // Check the prime slot first.
    if (D->table[H].data == elem) {

        /*
         * If there are no synonyms, simply mark
         * the prime slot as DELETED.
         */
        if (D->table[H].next == -1) {
            D->table[H].data = DELETED;
            return;
        }

        /*
         * If synonyms exist, move the first synonym
         * into the prime slot.
         */
        int synonym = D->table[H].next;

        D->table[H].data = D->table[synonym].data;
        D->table[H].next = D->table[synonym].next;

        /*
         * Recycle the synonym slot by placing it
         * at the front of the free list.
         */
        D->table[synonym].data = EMPTY;
        D->table[synonym].next = D->avail;
        D->avail = synonym;

        return;
    }

    /*
     * The element was not in the prime slot.
     * Search through the synonym chain.
     */
    int prev = H;
    int curr = D->table[H].next;

    while (curr != -1) {

        if (D->table[curr].data == elem) {

            /*
             * Unlink curr from the chain.
             */
            D->table[prev].next = D->table[curr].next;

            /*
             * Recycle curr by placing it at
             * the front of the available list.
             */
            D->table[curr].data = EMPTY;
            D->table[curr].next = D->avail;
            D->avail = curr;

            return;
        }

        prev = curr;
        curr = D->table[curr].next;
    }

    printf("Element '%c' not found.\n", elem);
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
