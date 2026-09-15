# 02 - The Registry Expulsion Protocol
by Gran Sabandal

## SCENARIO
Following the digitization effort, the university registrar must now handle student drops, transfers, and unenrollments.
<br>
Student records are stored dynamically using a singly linked chain (StudentLinkedList).
<br><br>
When a student unenrolls, their record cannot simply disappear into unmanaged memory. The registrar requires strict audit compliance:
- Locate & Unlink: Traverse the linked list to find the student matching targetID. The predecessor node must bypass the target node and connect directly to the target node's successor, preserving the rest of the chain.
- Head Preservation: If the target student is located at the very front (*head), the head pointer itself must advance to the next node.
- Audit Archive: The entire Student structure of the removed node must be copied to *deletedRecord before any deallocation occurs.
- Memory Hygiene: Safely deallocate the unlinked node with free() to prevent memory leaks.
- Absence Handling: If the list is empty (*head == NULL) or the targetID is not present, return 0 without altering the list or touching deletedRecord.
<br>
Your task is to implement the deletion function:

`int deleteStudent(StudentLinkedList *head, int targetID, Student *deletedRecord);`

**Specifications**
<br><br>
Function Signature:
`int deleteStudent(StudentLinkedList *head, int targetID, Student *deletedRecord)`
Input Pointer: 
- head is a double pointer (StudentNode **), permitting modification of the original head pointer when removing the first node.
Return Values:
- Return 1 on successful deletion and copy to *deletedRecord.
- Return 0 if the list is empty or targetID does not exist.

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
    if (*head == NULL) return 0;
    
    StudentLinkedList *trav;
    for (trav = head; *trav != NULL; trav = &(*trav)->next) {
        if ((*trav)->data.idNumber == targetID) {
            // Copy data to temp
            StudentLinkedList temp = *trav;
            // Copy data to deletedRecord
            *deletedRecord = temp->data;
            // Unlink node, move to next node
            *trav = temp->next;
            free(temp);
            return 1;
        }
    }
    return 0;
}
```

## SUPPLEMENTARY INFORMATION
(Linked List Deletion — Pointer Questions)

### 1. Why use trav = &(*trav)->next instead of trav = trav->next?

The reason is that trav is not a normal pointer to a node. Because we declared:
`StudentLinkedList *trav;`

and StudentLinkedList is defined as:

```
typedef struct Node {
    Student data;
    struct Node *next;
} StudentNode, *StudentLinkedList;
```
StudentLinkedList is actually a StudentNode *. Therefore, StudentLinkedList *trav is equivalent to:

`StudentNode **trav;`

So trav is a pointer to a pointer to a node.
<br><br>
Suppose the linked list looks like this:
```
head
 ↓
[A] → [B] → [C] → NULL
```
When we do:

`trav = head;`

trav points to the head pointer, which points to node A:
```
trav
 ↓
head → [A] → [B] → [C] → NULL
```
Therefore:

*trav

gives us the actual pointer to node A:
```
*trav
  ↓
[A] → [B] → [C] → NULL
```
<br><br>
To move to the next node, we first access the current node's next:

`(*trav)->next`

This gives us a StudentNode *, or the pointer to B.

However, trav itself needs to remain a StudentNode **. Therefore, we use & to get the address of the next pointer:

`trav = &(*trav)->next;`

Conceptually, it changes from:
```
trav
 ↓
head → [A] → [B] → [C] → NULL
```
to:
```
head → [A] → [B] → [C] → NULL
              ↑
             trav
```
More precisely, trav points to the pointer that leads to the current node.

We cannot simply use:

`trav = trav->next;`

because trav is a StudentNode **, not a StudentNode *. The -> operator needs a pointer to a structure. We need to dereference trav first:

`(*trav)->next`

But this produces a StudentNode *. Since trav needs a StudentNode **, we take its address:

`&(*trav)->next`

Therefore:

`trav = &(*trav)->next;`

is essentially saying:

> "Move trav to the address of the pointer that leads to the next node."

### 2. Why is temp freed instead of deletedRecord?

temp and deletedRecord represent two completely different things.

temp is a pointer to the dynamically allocated linked-list node that we want to delete:

`StudentLinkedList temp = *trav;`

Meanwhile, deletedRecord is a pointer to a Student structure provided by the caller. Its purpose is to store a copy of the deleted student's information.

For example:

Linked-list node:
```
temp
 ↓
+------------------+
| Student data     |
| next             |
+------------------+

deletedRecord
 ↓
+------------------+
| Student data     |
+------------------+
```
We first copy the student's data:

`*deletedRecord = temp->data;`

This means:

> "Copy the Student structure inside the node into the location pointed to by deletedRecord."

After copying, the two structures are separate:
```
temp
 ↓
+------------------+
| Student data     | ────── copied ──────→
| next             |                       |
+------------------+                       ↓
                                      +------------------+
                                      | Student data     |
                                      +------------------+
                                             ↑
                                      deletedRecord
```
We then remove and free the linked-list node:

`free(temp);`

We do not free deletedRecord because it belongs to the caller and is being used to preserve a copy of the deleted student's information.

For example, the caller might do:
```
Student deleted;

deleteStudent(&head, 12345, &deleted);
```

Here, deleted is a normal variable created by the caller. The function should fill it with the deleted student's data:

`*deletedRecord = temp->data;`

Doing this would be incorrect:

`free(deletedRecord);`

because deleted was not dynamically allocated with malloc().

The general rule is:
```
Dynamically allocated node
        ↓
      temp
        ↓
    free(temp)
```
while:
```
Caller-provided storage
        ↓
  deletedRecord
        ↓
  keep the copied data
```
### 3. Why use a temp in the first place?

The purpose of temp is to save the address of the node that we are about to delete before changing the links in the list.

We do:
`StudentLinkedList temp = *trav;`

Suppose the list is:
```
[A] → [B] → [C] → NULL
       ↑
      temp
```
If B is the node we want to delete, temp stores the address of B.

We can then perform the deletion in three important steps.

First, save the node:
`StudentLinkedList temp = *trav;`

Now:
```
[A] → [B] → [C]
       ↑
      temp
```
Second, copy the student's information:

`*deletedRecord = temp->data;`

Third, bypass the node:

`*trav = temp->next;`

The list becomes:

`[A] → [C] → NULL`

However, temp still points to the old B node:
```
[A] → [C] → NULL

temp
 ↓
[B]
```
Therefore, we can safely release its memory:

`free(temp);`

If we didn't use temp, we might write:
```
*deletedRecord = (*trav)->data;
*trav = (*trav)->next;
```
The problem is that after:
`*trav = (*trav)->next;`
*trav now points to the next node. We have lost our convenient pointer to the node we wanted to free.

Before:
```
trav
 ↓
[A] → [B] → [C]
       ↑
    node to delete
```
After:
```
trav
 ↓
[A] → [C]

[B]   ← no longer accessible
```
The memory occupied by B would still exist, but we would no longer have a pointer to it. This creates a memory leak.

Using temp prevents this:
```
trav
 ↓
[A] → [B] → [C]
       ↑
      temp
```
After unlinking:
```
trav
 ↓
[A] → [C]

temp
 ↓
[B]
```
Then:

`free(temp);`

releases the memory safely.

So temp essentially means:

> "Keep a copy of the address of the node I'm deleting so I can still access and free it after unlinking it."

### 4. Why use (*trav)->data instead of just trav?

The important thing to remember is that trav is a double pointer, not the actual node.

We declared:

`StudentLinkedList *trav;`

Since:
```
StudentLinkedList

is equivalent to:

StudentNode *
```
then:
```
StudentLinkedList *trav

is equivalent to:

StudentNode **trav;
```
So there are multiple levels of indirection.
```
trav
 ↓
(pointer to a pointer)
       ↓
     [NODE]
       ↓
     data
```
When we use:

`*trav`

we dereference trav once. This gives us a pointer to the actual node:
```
trav
 ↓
(pointer) ─────→ [NODE]
                    ↓
                  data
```
Then we use:

`(*trav)->data`

to access the data field inside that node.

The parentheses are important:

`(*trav)->data`

means:

*trav → get the StudentNode *
->data → access the node's data

So:
```
trav

is:

StudentNode **
```
while:
```
*trav

is:

StudentNode *
```
and:
```
(*trav)->data

is:

Student
```
We cannot simply write:

`trav->data`

because trav is a pointer to a pointer, rather than a pointer directly to a StudentNode.

### 5. Why is head a double pointer?

The reason head is a double pointer is that the function needs to be able to modify the original head pointer.

Normally, you might have:

`StudentLinkedList head;`

which is equivalent to:

`StudentNode *head;`

Suppose the list is:
```
head
 ↓
[A] → [B] → [C] → NULL
```
If we pass head directly to a function:
`deleteStudent(head, ...);`

the function receives a copy of the pointer.

Conceptually:
```
main:

head
 ↓
[A]


function:

head
 ↓
[A]
```
Both pointers point to the same node, but they are separate pointer variables.

If the function does:

`head = head->next;`

only the function's copy changes:
```
main's head
 ↓
[A] → [B] → [C]


function's head
       ↓
      [B] → [C]
```
The original head in main still points to A.

This is a problem when we want to delete the first node.

Instead, we pass the address of the original head:

`deleteStudent(&head, targetID, &deleted);`

Since head is:

`StudentNode *`

its address is:

`&head`

which is:

`StudentNode **`

Therefore the function receives:

`StudentLinkedList *head`

which is equivalent to:

`StudentNode **head`

Now the function has access to the actual head pointer.

If the original list is:
```
head
 ↓
[A] → [B] → [C] → NULL
```
we can do:

`*head = (*head)->next;`

which changes the original head:

Before:
```
head
 ↓
[A] → [B] → [C]
```

After:
```
head
 ↓
[B] → [C]
```
This is why a double pointer is necessary when a function needs to change what a pointer variable itself points to.

### Putting Everything Together

The deletion function:
```
int deleteStudent(StudentLinkedList *head, int targetID, Student *deletedRecord) {
    if (*head == NULL) return 0;

    StudentLinkedList *trav;

    for (trav = head; *trav != NULL; trav = &(*trav)->next) {
        if ((*trav)->data.idNumber == targetID) {

            StudentLinkedList temp = *trav;

            *deletedRecord = temp->data;

            *trav = temp->next;

            free(temp);

            return 1;
        }
    }

    return 0;
}
```
can be understood as:
```
head
 ↓
[A] → [B] → [C] → NULL
       ↑
      trav
```

### SUMMARY OF IMPORTANT CODE SNIPPETS

trav
- trav points to the pointer leading to the current node

*trav
- *trav gets the current node


(*trav)->data
- (*trav)->data gets the student's data


StudentLinkedList temp = *trav;
- temp saves the node before we unlink it

*deletedRecord = temp->data;
- *deletedRecord receives a copy of the student's information

*trav = temp->next 
- removes the node from the chain:

Before:

`[A] → [B] → [C]`


After:

`[A] → [C]`

Finally, `free(temp)` releases the memory occupied by the removed node:
```
temp
 ↓
[B]
↓
free(temp)
 ↓
memory released
```
The central idea is:

> head and trav are double pointers because we need to modify the pointers that connect the linked list, while temp is used to preserve the node's address so that we can safely free it after unlinking it.
