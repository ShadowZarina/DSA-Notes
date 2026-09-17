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
 

### Sample Outputs

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

## CODE

### main.c
```
#include <stdio.h>
#include <string.h>
#include "myheader.h"

int main(void) {
    const Student POOL[POOL_SIZE] = {
        {1042, "Alice Smith",       "BSIT",   2}, // [0]
        {1005, "Bob Vance",         "BSCS",   1}, // [1]
        {1088, "Charlie Brown",     "BSIS",   3}, // [2]
        {1015, "Diana Prince",      "BSECE",  2}, // [3]
        {1071, "Evan Wright",       "BSBA",   4}, // [4]
        {1050, "Fiona Gallagher",   "BSIT",   1}, // [5]
        {1028, "George Clark",      "BSCS",   3}, // [6]
        {1095, "Hannah Abbott",     "BSIS",   2}, // [7]
        {1063, "Ian Malcolm",       "BSMATH", 4}, // [8]
        {1010, "Julia Roberts",     "BSIT",   1}, // [9]
        {1033, "Kevin Bacon",       "BSCS",   2}, // [10]
        {1079, "Laura Croft",       "BSCE",   3}, // [11]
        {1001, "Michael Scott",     "BSBA",   1}, // [12] Min ID
        {1055, "Nancy Wheeler",     "BSIT",   2}, // [13]
        {1082, "Oscar Martinez",    "BSCS",   4}, // [14]
        {1022, "Peter Parker",      "BSBIO",  1}, // [15]
        {1068, "Quinn Fabray",      "BSIS",   2}, // [16]
        {1099, "Riley Reid",        "BSN",    3}, // [17] Max ID
        {1042, "Alice Twin",        "BSIT",   1}, // [18] Duplicate ID (1042)
        {1015, "Diana Double",      "BSCS",   4}, // [19] Duplicate ID (1015)
        {1037, "Steve Rogers",      "BSBA",   3}, // [20]
        {1090, "Tony Stark",        "BSECE",  4}, // [21]
        {1008, "Uma Thurman",       "BSIT",   1}, // [22]
        {1047, "Victor Stone",      "BSCS",   2}, // [23]
        {1075, "Wanda Maximoff",    "BSIS",   3}, // [24]
        {1025, "Xander Harris",     "BSIT",   2}, // [25]
        {1060, "Yvonne Strahovski", "BSCS",   4}, // [26]
        {1018, "Zack Snyder",       "BSCE",   1}, // [27]
        {1052, "Arthur Dent",       "BSMATH", 2}, // [28]
        {1085, "Bruce Banner",      "BSBIO",  4}  // [29]
    };

    int numOperations;
    printf("Enter number of operations: ");
    if (scanf("%d", &numOperations) != 1 || numOperations < 0) {
        return 0;
    }

    Student initialInputs[numOperations];
    int validCount = 0;

    // 1. Buffer selected student records
    printf("Enter selected students: ");
    for (int i = 0; i < numOperations; i++) {
        int poolIndex;
        if (scanf("%d", &poolIndex) != 1) {
            break;
        }
        if (poolIndex >= 0 && poolIndex < POOL_SIZE) {
            initialInputs[validCount++] = POOL[poolIndex];
        }
    }
    printf("\n\n");

    // 2. Display raw input sequence
    printInitialInputs(initialInputs, validCount);

    // 3. Process records into the sorted archive
    StudentArrayList archive = {.count = 0};

    printf("\n=== INSERTION PROCESS ===\n");
    for (int i = 0; i < validCount; i++) {
        int status = insertSortedStudent(&archive, initialInputs[i]);
        printInsertionLog(&initialInputs[i], status);
    }

    // 4. Display sorted result
    printf("\n");
    printArchive(&archive, "=== FINAL ARCHIVE STATE (SORTED) ===");

    return 0;
}
```
### myheader.h

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
