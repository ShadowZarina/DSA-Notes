#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "myheader.h"
#include "statistics.h"

// C FILE THAT EXECUTES FUNCTIONS & DISPLAYS

int main(void)
{
    List myList = newList();

    printf("Initial list:\n");
    display(myList);


    /* INSERT SORTED */

    printf("\nINSERT SORTED:\n");

    insertSorted(&myList, 15);
    display(myList);

    insertSorted(&myList, 2);
    display(myList);

    insertSorted(&myList, 10);
    display(myList);

    insertSorted(&myList, 20);
    display(myList);

    insertSorted(&myList, 10);
    display(myList);

    insertSorted(&myList, 5);
    display(myList);


    /* INSERT FIRST */

    printf("\nINSERT FIRST:\n");

    insertFirst(&myList, 100);
    display(myList);


    /* INSERT LAST */

    printf("\nINSERT LAST:\n");

    insertLast(&myList, 200);
    display(myList);


    /* INSERT INDEX */

    printf("\nINSERT INDEX:\n");

    insertIndex(&myList, 50, 2);
    display(myList);


    /* SEARCH */

    printf("\nSEARCH:\n");

    printf("Search for 10: ");

    if (boolSearch(myList, 10)) {
        printf("Found\n");
    }
    else {
        printf("Not found\n");
    }

    printf("Index of 10: %d\n",
           indexSearch(myList, 10));

    printf("Occurrences of 10: %d\n",
           countOccur(myList, 10));


    /* STATISTICS */

    printf("\nSTATISTICS:\n");

    printf("Mean: %.2f\n", mean(myList));
    printf("Median: %.2f\n", median(myList));
    printf("Mode: %.2f\n", mode(myList));


    /* DELETE FIRST */

    printf("\nDELETE FIRST:\n");

    deleteFirst(&myList);
    display(myList);


    /* DELETE LAST */

    printf("\nDELETE LAST:\n");

    deleteLast(&myList);
    display(myList);


    /* DELETE INDEX */

    printf("\nDELETE INDEX:\n");

    deleteIndex(&myList, 2);
    display(myList);


    /* DELETE FIRST OCCURRENCE */

    printf("\nDELETE FIRST OCCURRENCE:\n");

    deleteFirstOccur(&myList, 10);
    display(myList);


    /* DELETE LAST OCCURRENCE */

    printf("\nDELETE LAST OCCURRENCE:\n");

    deleteLastOccur(&myList, 10);
    display(myList);


    /* DELETE ALL OCCURRENCES */

    printf("\nDELETE ALL OCCURRENCES:\n");

    deleteAllOccur(&myList, 10);
    display(myList);


    /* FREE */

    freeList(&myList);

    return 0;
}
