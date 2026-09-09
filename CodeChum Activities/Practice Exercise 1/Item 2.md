# Registrar's Dilemma: The Latin Honors Tally
by Gran Sabandal

## Scenario

The university registrar's office is generating the official Latin Honors and Dean's List leaderboard
for the graduating class. In our university's grading scale:
- 1.0 is the highest possible grade (Excellent)
- 3.0 is the minimum passing grade
- 5.0 represents failure

Consequently, academic performance is inversely proportional to numeric GPA: a lower GPA indicates higher
academic achievement (eg., a student with a 1.15 GPA outranks a student with a 1.35 GPA).<br><br>
A student qualifies for the honors pool if their weighted Grade Point Average (GPA) meets/beats a 
specified cutoff threshold <br>`(computedGpa <= cutoffGpa)`. <br>The list of qualifying students has already been filtered, but the registrar now needs an automated module to sort and assign official institutional ranks.

### Ranking Mechanism: Standard Competition Ranking ("1224" Scheme)

The ranking must adhere strictly to standard competition rules:

1. **Sort Order:** <br>The honors list must be ordered by computedGpa in ascending order (lowest numeric value first). If two students have identical GPAs, preserve their original relative arrival order.
2. **First Place:** <br>The top student receives Rank 1.
3. **Ties:** <br>If two or more students have identical GPAs (evaluated to two decimal places, matching %2f precision), they are assigned the same rank.
4. **Rank Gaps / Accounting for Ties:** <br>The rank assigned to the subsequent student must equal their 1-based physical position in the sorted list. In other words, every student who ties consumes a rank number.
- *Example:* If two students tie for Rank 1, both are assigned Rank 1. The next student is assigned Rank 3 (Rank 2 is skipped).
- *Example:* If three students tie for Rank 4, all three receive Rank 4. The subsequent student receives Rank 7 (Ranks 5 and 6 are skipped).

### Your Task
Implement the following function in problem.c:
`void rankHonors(StudentList *honorsList);`

### Function Specifications
1. **honorsList:** A pointer to the head pointer of the filtered honors linked list (StudentList*).
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
    float cutoffGpa;

    // Standard input: <count> <order> <cutoffGpa>
    printf("Input format <count> <order> <minGpa>: ");
    if (scanf("%d %d %f", &count, &order, &cutoffGpa) != 3) {
        return 0;
    }

    StudentList dataset = populateData(count, order);
    StudentList honors = filterHonorRoll(dataset, cutoffGpa);

    printf("\nDATASET: \n");
    displayStudents(dataset);

    // Call ranking function
    rankHonors(&honors);

    printf("\nHONORS RANKING:\n");
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
    float grade; // 1.0 (Highest) to 3.0 (Passing), 5.0 (Fail)
    int units;   // e.g., 2, 3
} Course;

typedef struct {
    int id;
    char name[50];
    int courseCount;
    Course courses[MAX_COURSES];
    float computedGpa; // Populated by filterHonorRoll
    int rank;          // Populated by rankHonors
} Student;

typedef struct studNode {
    Student data;
    struct studNode* next;
} StudentNode, *StudentList;

// FUNCTION TASK: Sorts the honors list in ascending order of GPA (1.00 is best)
// and assigns competition ranking (1, 2, 2, 4...)
void rankHonors(StudentList *honorsList);

// Environment Utilities
StudentList populateData(int count, int order);
StudentList filterHonorRoll(StudentList studList, float cutoffGpa);
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
#include <math.h>
#include "cis2101.h"

// Helper comparison for floating-point 2-decimal rounded equality
static int isSameGPA(float gpa1, float gpa2) {
    int r1 = (int)roundf(gpa1 * 100.0f);
    int r2 = (int)roundf(gpa2 * 100.0f);
    return r1 == r2;
}

// ============================================================================
// STUDENT TASK: SORT & ASSIGN COMPETITION RANK (1, 2, 2, 4...)
// ============================================================================
void rankHonors(StudentList *honorsList) {

    if (honorsList == NULL || *honorsList == NULL) {
        return;
    }

    // Traversal #1 = Sort the nodes

    int swapped;

    do {
        swapped = 0;
        StudentList *curr = honorsList;

        while (*curr != NULL && (*curr)->next != NULL) {

            StudentList next = (*curr)->next;
            if ((*curr)->data.computedGpa > next->data.computedGpa) {

                (*curr)->next = next->next;
                next->next = *curr;
                *curr = next;

                swapped = 1;
            }

            curr = &(*curr)->next;
        }

    } while (swapped);

    // Traversal #2 = Assign ranks

    int position = 1;
    int rank = 1;

    StudentList curr = *honorsList;

    while (curr != NULL) {

        if (curr == *honorsList) {
            curr->data.rank = 1;
        }
        else if (isSameGPA(
                    curr->data.computedGpa,
                    curr->next == NULL
                        ? curr->data.computedGpa
                        : curr->data.computedGpa)) {
        }

        curr = curr->next;
    }

    curr = *honorsList;
    position = 1;
    rank = 1;

    float previousGpa = curr->data.computedGpa;

    while (curr != NULL) {

        if (position == 1) {
            rank = 1;
        }
        else if (!isSameGPA(curr->data.computedGpa, previousGpa)) {
            rank = position;
        }

        curr->data.rank = rank;

        previousGpa = curr->data.computedGpa;
        position++;
        curr = curr->next;
    }
}
```

My Thought Process
```
/*
#define MAX_COURSES 10

typedef struct {
    float grade; // 1.0 (Highest) to 3.0 (Passing), 5.0 (Fail)
    int units;   // e.g., 2, 3
} Course;

typedef struct {
    int id;
    char name[50];
    int courseCount;
    Course courses[MAX_COURSES];
    float computedGpa; // Populated by filterHonorRoll
    int rank;          // Populated by rankHonors
} Student;

typedef struct studNode {
    Student data;
    struct studNode* next;
} StudentNode, *StudentList;

// FUNCTION TASK: Sorts the honors list in ascending order of GPA (1.00 is best)
// and assigns competition ranking (1, 2, 2, 4...)

void rankHonors(StudentList *honorsList);


STEPS:
1. Traverse through Honor list with curr
2. If curr < next node (eg. 1.0 < 1.5), then swap the two nodes
2a. next of curr = next of the next node
3. Traverse again, assign int rank based on position
3a. Check if curr and the node/s after have the same GPA, rank = position doesn't execute
*/
```
