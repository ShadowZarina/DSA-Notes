// 4_closed_linear_probing_student.c
// CODE BOILERPLATE PROVIDED BY SIR GRAN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define EMPTY -1
#define DELETED -2

// ============================================================================
// DATA STRUCTURE DEFINITIONS
// ============================================================================

// 1. Nested Linked List Node for Enrolled Courses
typedef struct courseNode {
    char courseCode[10];
    float grade;
    int units;
    struct courseNode *next;
} CourseNode, *CourseList;

// 2. Student Structure
typedef struct {
    int studentID;         // Key used for Hashing
    char name[50];
    CourseList enrolled;   // Head pointer to linked list of courses
} Student;

// 3. Closed Dictionary Slot & Dictionary Type
typedef struct {
    Student data;
    int status;            // 0 = Occupied, EMPTY (-1), DELETED (-2)
} DictionarySlot;

typedef DictionarySlot ClosedDict[MAX];

// ============================================================================
// HELPER & DISPLAY FUNCTIONS (PRE-MADE)
// ============================================================================

// Hash Function: Hash studentID to index 0..MAX-1
int HASH(int studentID) {
    return studentID % MAX;
}

// Add a course to a student's enrolled linked list (Insert First)
void addCourse(CourseList *list, const char *code, float grade, int units) {
    CourseNode *newNode = (CourseNode *)malloc(sizeof(CourseNode));
    if (newNode != NULL) {
        strcpy(newNode->courseCode, code);
        newNode->grade = grade;
        newNode->units = units;
        newNode->next = *list;
        *list = newNode;
    }
}

// Display Function matching your required format
void displayDictionary(ClosedDict D) {
    printf("\n=================================================================\n");
    printf("                    CLOSED DICTIONARY STATE                      \n");
    printf("=================================================================\n");

    // Line 1: Index
    printf("Index:\t");
    for (int i = 0; i < MAX; i++) {
        printf("[%2d]  ", i);
    }
    printf("\n");

    // Line 2: Value (Student ID or Status)
    printf("Value:\t");
    for (int i = 0; i < MAX; i++) {
        if (D[i].status == 0) {
            printf("[%2d]  ", D[i].data.studentID);
        } else if (D[i].status == DELETED) {
            printf("[ ! ]  ");
        } else {
            printf("[   ]  ");
        }
    }
    printf("\n");

    // Line 3: Ideal (Hash Value)
    printf("Ideal:\t");
    for (int i = 0; i < MAX; i++) {
        if (D[i].status == 0) {
            printf(" %2d   ", HASH(D[i].data.studentID));
        } else {
            printf("  -   ");
        }
    }
    printf("\n-----------------------------------------------------------------\n");

    // Detailed Itemized Student Records with Nested Linked Lists
    printf("\n--- DETAILED STUDENT RECORDS ---\n");
    for (int i = 0; i < MAX; i++) {
        if (D[i].status == 0) {
            printf("\n[%d] ID: %d | Name: %s (Ideal Hash: %d)\n", 
                   i, D[i].data.studentID, D[i].data.name, HASH(D[i].data.studentID));
            printf("    Enrolled Courses:\n");
            
            CourseNode *curr = D[i].data.enrolled;
            if (curr == NULL) {
                printf("      (No courses enrolled)\n");
            }
            while (curr != NULL) {
                printf("      -> Course: %-8s | Grade: %.2f | Units: %d\n", 
                       curr->courseCode, curr->grade, curr->units);
                curr = curr->next;
            }
        }
    }
    printf("\n=================================================================\n");
}

// ============================================================================
// STUDENT EXERCISES (TODO SECTION)
// ============================================================================

/**
 * TODO 1: Initialize Closed Dictionary
 * Set all slots' status field to EMPTY (-1) and data.enrolled pointers to NULL.
 */
void initDict(ClosedDict D) {
    // TODO: Write your code here
}

/**
 * TODO 2: Insert Student into Closed Dictionary (Linear Probing)
 * 1. Compute H = HASH(s.studentID).
 * 2. Probe using circular array (H + i) % MAX to find first EMPTY or DELETED slot.
 * 3. Copy student data into target slot and set status to 0 (Occupied).
 */
void insertStudent(ClosedDict D, Student s) {
    // TODO: Write your code here
}

/**
 * TODO 3: Delete Student from Closed Dictionary
 * 1. Search for studentID using Linear Probing starting at HASH(studentID).
 * 2. If found, free all nodes in their enrolled linked list.
 * 3. Set slot status to DELETED (-2).
 */
void deleteStudent(ClosedDict D, int studentID) {
    // TODO: Write your code here
}

// ============================================================================
// MAIN DRIVER FOR TESTING
// ============================================================================

int main() {
    ClosedDict D;
    initDict(D);

    // Create Dummy Student 1 (ID: 102 -> Hash: 2)
    Student s1 = {102, "Alice Smith", NULL};
    addCourse(&s1.enrolled, "CS101", 1.25, 3);
    addCourse(&s1.enrolled, "CS102", 1.50, 4);

    // Create Dummy Student 2 (ID: 202 -> Hash: 2 -> Collides! Probes to 3)
    Student s2 = {202, "Bob Jones", NULL};
    addCourse(&s2.enrolled, "MATH1", 2.00, 3);
    addCourse(&s2.enrolled, "CS101", 1.75, 3);

    // Create Dummy Student 3 (ID: 302 -> Hash: 2 -> Collides! Probes to 4)
    Student s3 = {302, "Charlie Brown", NULL};
    addCourse(&s3.enrolled, "PHYS1", 1.00, 4);

    printf("Inserting Students (IDs 102, 202, 302 - all hash ideally to Index 2)...\n");
    insertStudent(D, s1);
    insertStudent(D, s2);
    insertStudent(D, s3);

    displayDictionary(D);

    printf("\nDeleting Student ID 202 (Bob Jones)...\n");
    deleteStudent(D, 202);

    displayDictionary(D);

    return 0;
}
