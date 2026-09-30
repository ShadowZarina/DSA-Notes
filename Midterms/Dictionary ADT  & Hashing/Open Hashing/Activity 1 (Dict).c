// 1_open_hashing.c
// CODE BOILERPLATE PROVIDED BY SIR GRAN

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10

// Node structure for linked list bucket
typedef struct node {
    char elem;
    struct node *next;
} Node, *NodePtr;

typedef NodePtr OpenDict[MAX];

int HASH(char key) {
    return (toupper(key) - 'A') % MAX;
}

// 'A' = 65 so it returns (letter value - 65) % 10

void displayDict(OpenDict D) {
    printf("\n--- OPEN HASH DICTIONARY (Chaining) ---\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%d]: ", i);
        NodePtr trav = D[i];
        while (trav != NULL) {
            printf("%c -> ", trav->elem);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}

// TODO EXERCISES FOR STUDENTS:

void initDict(OpenDict D) {
    // TODO: Loop through array D and set every bucket pointer to NULL
    for (int i = 0; i < MAX; ++i) {
        D[i] = NULL;
    }
}

void insertDict(OpenDict D, char elem) {
    // TODO: Hash elem, malloc a new node, and insert at head of list at D[HASH(elem)]
    int hash = HASH(elem);
    // LINKED LIST IN ARRAY, NO NEED TO SHIFT
    
    NodePtr *trav;
    NodePtr temp = malloc(sizeof(Node));
    
    for (trav = &D[hash]; *trav != NULL; trav=&(*trav)->next) {
        if ((*trav)->elem == elem) return;
    }
    
    if (temp != NULL) {
        temp->elem = elem;
        temp->next = D[hash];
        D[hash] = temp;
    }

}


// // Node structure for linked list bucket
// typedef struct node {
//     char elem;
//     struct node *next;
// } Node, *NodePtr;

// typedef NodePtr OpenDict[MAX];


void deleteDict(OpenDict D, char elem) {
    // TODO: Search linked list at D[HASH(elem)], unlink target node, and free memory
    int hash = HASH(elem);
    NodePtr *trav, temp;
    for (trav = &D[hash]; *trav != NULL && (*trav)->elem != elem; trav=&(*trav)->next) {}
    temp = *trav; //accessing double pointer, must dereference
    *trav = temp->next;
    free(temp);
}

int main() {
    OpenDict D;
    initDict(D);

    printf("Inserting 'A', 'K', 'U' (All hash to index 0)...\n");
    insertDict(D, 'A');
    insertDict(D, 'K');
    insertDict(D, 'U');
    displayDict(D);

    printf("Deleting 'K'...\n");
    deleteDict(D, 'K');
    displayDict(D);

    return 0;
}
