# WHAT ARE SETS?

## The Rules of a Set

In computer science, a set is an abstract data type that behaves like a mathematical set:
1. Uniqueness: No duplicate values are allowed.
2. Membership: Its primary purpose is to quickly check if an item exists.
3. Unordered (Mathematical standard): Positional indexing (like mySet[2]) is generally not supported.

## How to Implement Sets in Pure C

Depending on your performance needs and the data type you are storing, C programmers use three common approaches to build a set:

### 1. The Integer Bitmask (For Small Integer Sets)

If your set only needs to hold a predefined range of numbers (e.g., numbers from 0 to 31 or 64), you can use the individual bits of a single integer variable. A 1 bit means the number is in the set; a 0 bit means it isn't.
- Pros: Extremely fast (O(1) operations); takes up almost zero memory.
- Cons: Limited to small ranges of integers.
- 
```
#include <stdio.h>

typedef unsigned int BitSet;

// Add an element to the set
void add_element(BitSet *set, int element) {
    *set |= (1U << element);
}

// Check if element exists (Membership test)
int is_member(BitSet set, int element) {
    return (set & (1U << element)) != 0;
}

int main() {
    BitSet mySet = 0; // Empty set

    add_element(&mySet, 3);
    add_element(&mySet, 7);
    add_element(&mySet, 3); // Duplicate, ignored by bitwise OR logic

    printf("Is 3 in set? %s\n", is_member(mySet, 3) ? "Yes" : "No");
    printf("Is 5 in set? %s\n", is_member(mySet, 5) ? "Yes" : "No");

    return 0;
}
```


### 2. The Dynamic Array Approach (Simplest to Write)

You can use a standard C array or dynamically allocated memory block (malloc). Before inserting any new element, you must manually loop through the array to ensure it doesn't already exist.
- Pros: Easy to implement and debug.
- Cons: Slow insertion and lookup (O(n) time complexity) because you have to scan the entire array every time.

### 3. Hash Tables (For Large Datasets)

For robust production code, C developers build a basic hash table. Elements are hashed into buckets. If you try to add an item that hashes to a slot already containing that exact value, you discard it.
- Pros: High-performance, near O(1) average time complexity for lookup and insertion.
- Cons: Requires writing complex hashing functions and handling hash collisions.

# SET OPERATIONS
When writing a custom set library in C, you typically define the classic algebraic set operations using your array or bitmask structure:
- Union: Merging two sets together while stripping out the duplicates.
- Intersection: Creating a third set containing only the elements present in both original sets.
- Difference: Creating a set containing elements from Set A that do not exist in Set B

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
