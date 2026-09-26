# WHAT ARE SETS?

# SET FUNCTIONS

# SAMPLE CODE

```
#include <stdio.h>

// Helper function to check if an element is already present in a set
int contains(int set[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (set[i] == element) {
            return 1; // True
        }
    }
    return 0; // False
}

// Helper function to print a set nicely
void printSet(int set[], int size, char name[]) {
    printf("%s = { ", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

// 1. UNION: Combines all unique elements from both sets
int setUnion(int setA[], int sizeA, int setB[], int sizeB, int result[]) {
    int resSize = 0;

    // Add all elements from setA
    for (int i = 0; i < sizeA; i++) {
        result[resSize++] = setA[i];
    }

    // Add elements from setB only if they are not already in the result
    for (int i = 0; i < sizeB; i++) {
        if (!contains(result, resSize, setB[i])) {
            result[resSize++] = setB[i];
        }
    }
    return resSize; // Returns the size of the union set
}

// 2. INTERSECTION: Finds elements common to both sets
int setIntersection(int setA[], int sizeA, int setB[], int sizeB, int result[]) {
    int resSize = 0;

    // Add elements to result if they are present in both A and B
    for (int i = 0; i < sizeA; i++) {
        if (contains(setB, sizeB, setA[i])) {
            result[resSize++] = setA[i];
        }
    }
    return resSize; // Returns the size of the intersection set
}

// 3. DIFFERENCE: Finds elements in setA that are NOT in setB (A - B)
int setDifference(int setA[], int sizeA, int setB[], int sizeB, int result[]) {
    int resSize = 0;

    // Add elements from setA only if they don't exist in setB
    for (int i = 0; i < sizeA; i++) {
        if (!contains(setB, sizeB, setA[i])) {
            result[resSize++] = setA[i];
        }
    }
    return resSize; // Returns the size of the difference set
}

int main() {
    // Define two example sets (assumed to have unique items initially)
    int setA[] = {1, 3, 5, 7, 9};
    int sizeA = sizeof(setA) / sizeof(setA[0]);

    int setB[] = {5, 7, 9, 11, 13};
    int sizeB = sizeof(setB) / sizeof(setB[0]);

    // Maximum possible result size is sizeA + sizeB
    int result[20]; 
    int resSize;

    printSet(setA, sizeA, "Set A");
    printSet(setB, sizeB, "Set B");
    printf("\n");

    // Compute Union
    resSize = setUnion(setA, sizeA, setB, sizeB, result);
    printSet(result, resSize, "Union (A U B)");

    // Compute Intersection
    resSize = setIntersection(setA, sizeA, setB, sizeB, result);
    printSet(result, resSize, "Intersection (A n B)");

    // Compute Difference (A - B)
    resSize = setDifference(setA, sizeA, setB, sizeB, result);
    printSet(result, resSize, "Difference (A - B)");

    // Compute Difference (B - A)
    resSize = setDifference(setB, sizeB, setA, sizeA, result);
    printSet(result, resSize, "Difference (B - A)");

    return 0;
}
```
