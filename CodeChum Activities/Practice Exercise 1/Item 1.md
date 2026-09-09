# Dean's List Eligibility Filter (Dynamic GPA Computation)

## SCENARIO
The academic registrar evaluates students for the Dean's List. Instead of storing pre-computed GPAs, each student record contains an array of courses
taken that term, with each course represented by its numeric grade and credit unit value:
`GPA = Sum(grade * units)/Sum(units)`
Implement the function:
`StudentList filterHonorRoll(StudentList studList, float minGpa);`
The function must traverse the master linked list, calculate the weighted GPA for each student, and if the student meets or exceeds minGPA, copy their information (including the calculated GPA) into a newly allocated linked list in the original relative order. The original linked list must remain unmodified.

### Sample Outputs 

Sample Output 1
```
Input format <count> <order> <minGpa>: 5 1 1.4

DATASET:
ID         | Name            | Courses  | GPA
1001       | Uang            | 3        | 1.26
1003       | Codilla         | 8        | 1.21
1005       | Pangan          | 3        | 1.40
1007       | To Chip         | 8        | 1.12
1009       | Gillera         | 8        | 1.32

HONORS:
ID         | Name            | Courses  | GPA
1001       | Uang            | 3        | 1.26
1003       | Codilla         | 8        | 1.21
1005       | Pangan          | 3        | 1.40
1007       | To Chip         | 8        | 1.12
1009       | Gillera         | 8        | 1.32
```
Sample Output 2
```
Input format <count> <order> <minGpa>: 6 2 1.5

DATASET:
ID         | Name            | Courses  | GPA
1002       | Jarmon          | 8        | 2.65
1004       | Olsen           | 3        | 2.18
1006       | Morante         | 8        | 2.87
1008       | Torred          | 3        | 1.89
1010       | Auditor         | 3        | 2.79
1012       | Canicula        | 3        | 2.30

HONORS:
NO QUALIFIERS
```
Sample Output 3
```
Input format <count> <order> <minGpa>: 0 1 1.5

DATASET:
NO QUALIFIERS

HONORS:
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
