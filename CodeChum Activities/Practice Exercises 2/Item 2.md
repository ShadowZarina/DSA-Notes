# 02 - The Registry Expulsion Protocol
by Gran Sabandal

## SCENARIO


Sample Output 1
```
Enter number of students to populate: 0
Enter record numbers from the pool:
=== INITIAL INPUT SEQUENCE (RAW/SELECTED POOL DATA) ===
Total Items Selected: 0
  [None]

=== INITIAL LINKED LIST (BUILT FROM APPEND) ===
  [Empty List / NULL]
Enter number of students to delete: 1

=== DELETION PROCESS ===
Enter which student to delete: 1042
-> Deleting Target ID 1042  | Status: FAILED (0)  | Reason: ID Not Found / Empty

=== FINAL LINKED LIST (AFTER DELETIONS) ===
  [Empty List / NULL]
```
Sample Output 2
```
Enter number of students to populate: 1
Enter record numbers from the pool: 0

=== INITIAL INPUT SEQUENCE (RAW/SELECTED POOL DATA) ===
Total Items Selected: 1
  [0] ID: 1042  | Alice Smith        | BSIT   | Yr 2

=== INITIAL LINKED LIST (BUILT FROM APPEND) ===
  [0] ID: 1042  | Alice Smith        | BSIT   | Yr 2 ->
  NULL
Enter number of students to delete: 1

=== DELETION PROCESS ===
Enter which student to delete: 1042
-> Deleting Target ID 1042  | Status: SUCCESS (1) | Removed: Alice Smith        (BSIT, Yr 2)

=== FINAL LINKED LIST (AFTER DELETIONS) ===
  [Empty List / NULL]
```
Sample Output 3
```
Enter number of students to populate: 3
Enter record numbers from the pool: 0 1 2

=== INITIAL INPUT SEQUENCE (RAW/SELECTED POOL DATA) ===
Total Items Selected: 3
  [0] ID: 1042  | Alice Smith        | BSIT   | Yr 2
  [1] ID: 1005  | Bob Vance          | BSCS   | Yr 1
  [2] ID: 1088  | Charlie Brown      | BSIS   | Yr 3

=== INITIAL LINKED LIST (BUILT FROM APPEND) ===
  [0] ID: 1042  | Alice Smith        | BSIT   | Yr 2 ->
  [1] ID: 1005  | Bob Vance          | BSCS   | Yr 1 ->
  [2] ID: 1088  | Charlie Brown      | BSIS   | Yr 3 ->
  NULL
Enter number of students to delete: 1

=== DELETION PROCESS ===
Enter which student to delete: 1042
-> Deleting Target ID 1042  | Status: SUCCESS (1) | Removed: Alice Smith        (BSIT, Yr 2)

=== FINAL LINKED LIST (AFTER DELETIONS) ===
  [0] ID: 1005  | Bob Vance          | BSCS   | Yr 1 ->
  [1] ID: 1088  | Charlie Brown      | BSIS   | Yr 3 ->
  NULL
```

## STRUCT AND FUNCTION PROTOTYPE
(myheader.h)

```
#ifndef MYHEADER_H
#define MYHEADER_H

#define POOL_SIZE 30

typedef struct {
    int idNumber;
    char name[32];
    char course[8];
    int yearLevel;
} Student;

typedef struct Node {
    Student data;
    struct Node *next;
} StudentNode, *StudentLinkedList;

/* -------------------------------------------------------------
 * STUDENT TASK: Complete this function ONLY.
 * Delete the node matching 'targetID'.
 * Copy the deleted data to *deletedRecord and free the node.
 * Return 1 on success, or 0 if not found / list is empty.
 * ------------------------------------------------------------- */
int deleteStudent(StudentLinkedList *head, int targetID, Student *deletedRecord);

/* -------------------------------------------------------------
 * DISPLAY FUNCTIONS
 * ------------------------------------------------------------- */

void printStudent(const Student *s);

// Displays the raw selected records from the pool
void printInitialInputs(const Student arr[], int count);

// Displays the linked list node-by-node
void printLinkedList(StudentLinkedList head, const char *title);

// Displays single deletion audit event
void printDeleteLog(int targetID, int status, const Student *deletedRecord);

/* -------------------------------------------------------------
 * HELPER MEMORY ROUTINES
 * ------------------------------------------------------------- */

void appendStudent(StudentLinkedList *head, Student s);

void clearList(StudentLinkedList *head);

#endif
```

## ANSWER CODE
(answer.c)

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myheader.h"

/* -------------------------------------------------------------
 * STUDENT TASK: Complete this function ONLY.
 * Delete the node matching 'targetID'.
 * Copy the deleted data to *deletedRecord and free the node.
 * Return 1 on success, or 0 if not found / list is empty.
 * ------------------------------------------------------------- */
int deleteStudent(StudentLinkedList *head, int targetID, Student *deletedRecord) {

    return -1;
}
```
