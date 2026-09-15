# 01 - The University Registrar's Archive
by Gran Sabandal

## SCENARIO

The registrar's office is transitioning from paper folders to a digital student indexing system. To keep lookup operations fast, records must always remain sorted in ascending order by their ID Number.
<br><br>
When a new enrollee submits their documents, their record cannot simply be appended to the bottom. Instead, it must be inserted directly into its exact numerical position in the archive, shifting all subsequent student records one slot down to make room. Because storage cabinets in this terminal are capped at a capacity of 10 (MAX), the system must reject any new records if the list is already full.
<br><br>
Your task is to implement the function:
`int insertSortedStudent(StudentArrayList *list, Student newStudent);`

Specifications:
- Capacity Check: If list->count >= MAX, insertion cannot proceed. Return 0.
- Sorted Placement: Find the correct index where newStudent.idNumber belongs so the list remains in ascending order.
- Shift Elements: Shift all records with an ID greater than newStudent.idNumber one position to the right.
- Update State: Place newStudent into the opened slot, increment list->count by 1, and return 1 to indicate success.
 

Sample Output 1
```
Enter number of operations: 3
Enter selected students: 1 17 5


=== INITIAL INPUT SEQUENCE (RAW/UNSORTED) ===
Total Items Entered: 3
  [0] ID: 1005  | Bob Vance          | BSCS   | Yr 1
  [1] ID: 1099  | Riley Reid         | BSN    | Yr 3
  [2] ID: 1050  | Fiona Gallagher    | BSIT   | Yr 1

=== INSERTION PROCESS ===
-> Inserting ID 1005  (Bob Vance         ) | Status: SUCCESS (1)
-> Inserting ID 1099  (Riley Reid        ) | Status: SUCCESS (1)
-> Inserting ID 1050  (Fiona Gallagher   ) | Status: SUCCESS (1)

=== FINAL ARCHIVE STATE (SORTED) === (Count: 3/10)
  [0] ID: 1005  | Bob Vance          | BSCS   | Yr 1
  [1] ID: 1050  | Fiona Gallagher    | BSIT   | Yr 1
  [2] ID: 1099  | Riley Reid         | BSN    | Yr 3
```
Sample Output 2
```
Enter number of operations: 2
Enter selected students: 0 18


=== INITIAL INPUT SEQUENCE (RAW/UNSORTED) ===
Total Items Entered: 2
  [0] ID: 1042  | Alice Smith        | BSIT   | Yr 2
  [1] ID: 1042  | Alice Twin         | BSIT   | Yr 1

=== INSERTION PROCESS ===
-> Inserting ID 1042  (Alice Smith       ) | Status: SUCCESS (1)
-> Inserting ID 1042  (Alice Twin        ) | Status: SUCCESS (1)

=== FINAL ARCHIVE STATE (SORTED) === (Count: 2/10)
  [0] ID: 1042  | Alice Smith        | BSIT   | Yr 2
  [1] ID: 1042  | Alice Twin         | BSIT   | Yr 1
```
Sample Output 3
```
Enter number of operations: 3
Enter selected students: 3 19 3


=== INITIAL INPUT SEQUENCE (RAW/UNSORTED) ===
Total Items Entered: 3
  [0] ID: 1015  | Diana Prince       | BSECE  | Yr 2
  [1] ID: 1015  | Diana Double       | BSCS   | Yr 4
  [2] ID: 1015  | Diana Prince       | BSECE  | Yr 2

=== INSERTION PROCESS ===
-> Inserting ID 1015  (Diana Prince      ) | Status: SUCCESS (1)
-> Inserting ID 1015  (Diana Double      ) | Status: SUCCESS (1)
-> Inserting ID 1015  (Diana Prince      ) | Status: SUCCESS (1)

=== FINAL ARCHIVE STATE (SORTED) === (Count: 3/10)
  [0] ID: 1015  | Diana Prince       | BSECE  | Yr 2
  [1] ID: 1015  | Diana Double       | BSCS   | Yr 4
  [2] ID: 1015  | Diana Prince       | BSECE  | Yr 2
```

## STRUCT AND FUNCTION PROTOTYPE
(myheader.h)

```
#ifndef MYHEADER_H
#define MYHEADER_H

#define MAX 10
#define POOL_SIZE 30

typedef struct {
    int idNumber;
    char name[32];
    char course[8];
    int yearLevel;
} Student;

typedef struct {
    Student students[MAX];
    int count;
} StudentArrayList;

/* -------------------------------------------------------------
 * STUDENT TASK: Complete this function ONLY.
 * Insert 'newStudent' into 'list' sorted ascending by idNumber.
 * Return 1 on success, or 0 if list is full.
 * ------------------------------------------------------------- */
int insertSortedStudent(StudentArrayList *list, Student newStudent);
```

## ANSWER CODE
(answer.c)

```
#include <stdio.h>
#include <string.h>
#include "myheader.h"

/* -------------------------------------------------------------
 * STUDENT TASK: Complete this function ONLY.
 * Insert 'newStudent' into 'list' sorted ascending by idNumber.
 * Return 1 on success, or 0 if list is full.
 * ------------------------------------------------------------- */
int insertSortedStudent(StudentArrayList *list, Student newStudent) {
    if (list->count >= MAX) return 0;
    
    int i;
    
    for (i = list->count - 1; i >= 0 && list->students[i].idNumber > newStudent.idNumber; i--) {
        list->students[i+1] = list->students[i]; 
        // i+1 to point to the open space, MOVES ONE SPACE TO THE RIGHT
    } 
    
    list->students[i+1] = newStudent; // ASSIGNS VALUE
    
    ++(list->count);
    
    return 1;
}
```
