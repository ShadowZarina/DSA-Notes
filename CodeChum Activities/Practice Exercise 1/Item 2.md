# Registrar's Dilemma: The Latin Honors Tally
by Gran Sabandal

## Scenario

The university registrar's office is generating the official Latin Honors and Dean's List leaderboard
for the graduating class. In our university's grading scale:
- 1.0 is the highest possible grade (Excellent)
- 3.0 is the minimum passing grade
- 5.0 represents failure

Consequently, academic performance is inversely proportional to numeric GPA: a lower GPA indicates higher
academic achievement (eg., a student with a 1.15 GPA outranks a student with a 1.35 GPA).<br>
A student qualifies for the honors pool if their weighted Grade Point Average (GPA) meets/beats a 
specified cutoff threshold `(computedGpa <= cutoffGpa)`. The list of qualifying students has already been filtered, but the registrar now needs an automated module to sort and assign official institutional ranks.

### Ranking Mechanism: Standard Competition Ranking ("1224" Scheme)

The ranking must adhere strictly to standard competition rules:

1. Sort Order: The honors list must be ordered by computedGpa in ascending order (lowest numeric value first). If two students have identical GPAs, preserve their original relative arrival order.
2. First Place: The top student receives Rank 1.
3. Ties: If two or more students have identical GPAs (evaluated to two decimal places, matching %2f precision), they are assigned the same rank.
4. Rank Gaps / Accounting for Ties: The rank assigned to the subsequent student must equal their 1-based physical position in the sorted list. In other words, every student who ties consumes a rank number.
- Example: If two students tie for Rank 1, both are assigned Rank 1. The next student is assigned Rank 3 (Rank 2 is skipped).
- Example: If three students tie for Rank 4, all three receive Rank 4. The subsequent student receives Rank 7 (Ranks 5 and 6 are skipped).

### Your Task
Implement the following function in problem.c:
`void rankHonors(StudentList *honorsList);`

### Function Specifications
1. honorsList: A pointer to the head pointer of the filtered honors linked list (StudentList*).
2. Sort the linked list in place (or rearrange node data/pointers) in ascending order of computedGpa.
3. Traverse the sorted list and assign each student's official ranking integer to curr->data.rank.
4. If the list is empty (*honorsList == NULL) or contains only one node, handle it cleanly without runtime errors or crashes.

### Sample Outputs 

Sample Output 1
```
Input format <count> <order> <minGpa>: 12 1 1.4

DATASET:
Rank  | ID         | Name            | Courses  | GPA
-     | 1001       | Uang            | 3        | 1.26
-     | 1003       | Codilla         | 8        | 1.21
-     | 1005       | Pangan          | 3        | 1.40
-     | 1007       | To Chip         | 8        | 1.12
-     | 1009       | Gillera         | 8        | 1.32
-     | 1011       | Valmonte        | 8        | 1.30
-     | 1013       | Arias           | 3        | 1.49
-     | 1015       | Maratas         | 8        | 1.09
-     | 1017       | Dawal           | 3        | 1.50
-     | 1019       | Kho             | 8        | 1.12
-     | 1021       | Apale           | 3        | 1.41
-     | 1023       | Delima          | 8        | 1.19

HONORS RANKING:
Rank  | ID         | Name            | Courses  | GPA
1     | 1015       | Maratas         | 8        | 1.09
2     | 1019       | Kho             | 8        | 1.12
2     | 1007       | To Chip         | 8        | 1.12
4     | 1023       | Delima          | 8        | 1.19
5     | 1003       | Codilla         | 8        | 1.21
6     | 1001       | Uang            | 3        | 1.26
7     | 1011       | Valmonte        | 8        | 1.30
8     | 1009       | Gillera         | 8        | 1.32
9     | 1005       | Pangan          | 3        | 1.40
```
Sample Output 2
```
Input format <count> <order> <minGpa>: 5 2 1.4

DATASET:
Rank  | ID         | Name            | Courses  | GPA
-     | 1002       | Jarmon          | 8        | 2.65
-     | 1004       | Olsen           | 3        | 2.18
-     | 1006       | Morante         | 8        | 2.87
-     | 1008       | Torred          | 3        | 1.89
-     | 1010       | Auditor         | 3        | 2.79

HONORS RANKING:
NO QUALIFIERS
```
Sample Output 3
```
Input format <count> <order> <minGpa>: 0 1 1.5

DATASET:
NO QUALIFIERS

HONORS RANKING:
NO QUALIFIERS
```

## CODE

### main.c
```
#include <stdio.h>
#include "cis2101.h"

int main(void) {
    int count, order;
    float minGpa;

    // Input format: <count> <order> <minGpa>
    printf("Input format <count> <order> <minGpa>: ");
    if (scanf("%d %d %f", &count, &order, &minGpa) != 3) {
        return 0;
    }

    StudentList dataset = populateData(count, order);
    StudentList honors = filterHonorRoll(dataset, minGpa);

    printf("\nDATASET: \n");
    displayStudents(dataset);

    printf("\nHONORS: \n");
    displayStudents(honors);

    freeStudents(dataset);
    freeStudents(honors);
    return 0;
}
```

### cis2101.h
```
#ifndef CIS2101_H
#define CIS2101_H

#define MAX_COURSES 10

typedef struct {
    float grade; // e.g., 3.5, 4.0, 1.0
    int units;   // e.g., 3, 2, 5
} Course;

typedef struct {
    int id;
    char name[50];
    int courseCount;
    Course courses[MAX_COURSES];
    float computedGpa; // To be populated by filterHonorRoll
} Student;

typedef struct studNode {
    Student data;
    struct studNode* next;
} StudentNode, *StudentList;

// Computes GPA for each student and returns a new list of students meeting minGpa
StudentList filterHonorRoll(StudentList studList, float minGpa);

StudentList populateData(int count, int order);
void appendStudent(StudentList *studList, Student s);
void displayStudents(StudentList studList);
void freeStudents(StudentList studList);
float calculateGPA(Student s);

#endif
```

new.c is hidden, but this contains all the other helper functions.

### problem.c

ANSWER:
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cis2101.h"

// ============================================================================
// STUDENT DELIVERABLE FUNCTION
// (Note: Qualifies when computed GPA <= cutoffGpa)
// ============================================================================
StudentList filterHonorRoll(StudentList studList, float cutoffGpa) {
    StudentList honorList = NULL;
    StudentList *last = &honorList;

    for (StudentList curr = studList; curr != NULL; curr = curr->next) {

        float gpa = calculateGPA(curr->data);

        if (gpa <= cutoffGpa) {

            StudentList newNode = malloc(sizeof(StudentNode));

            newNode->data = curr->data;

            newNode->data.computedGpa = gpa;

            newNode->next = NULL;

            *last = newNode;
            last = &newNode->next;
        }
    }

    return honorList;
}
```

My Thought Process
```
/* STEPS
GPA = s(grade * units) / s(units)

1. Traverse master linked studList
2. Calculate weighted GPA per StudentList -> calculateGPA()
3. If student <= minGPA
3a. copy information including calculated GPA into 
3b. newly allocated linked list in original relative order 
-- DO NOT MODIFY ORIGINAL LINKED LIST
*/

// call: StudentList honors = filterHonorRoll(dataset, minGpa);

/*
typedef struct {
    float grade; // e.g., 3.5, 4.0, 1.0
    int units;   // e.g., 3, 2, 5
} Course;

typedef struct {
    int id;
    char name[50];
    int courseCount;
    Course courses[MAX_COURSES];
    float computedGpa; // To be populated by filterHonorRoll
} Student;

typedef struct studNode {
    Student data;
    struct studNode* next;
} StudentNode, *StudentList;
*/
```
