From Bitwise Operators to Set ADTs — Concepts, Math, and C Code

# BITS
- BIT is short for Binary Digit — values are built only from 1s and 0s. 
- In value terms: 1 = true, 0 = false (the "bit value").
- In sign terms: 1 = negative, 0 = positive (the "sign bit", the leftmost/most significant bit).
- Everything else we do with bits — logic, shifting, negative numbers — builds on these two roles.

Example: byte: char A = 75

> Leftmost bit (bold outline) = SIGN BIT → 0 means positive

## Bitwise Operators

- & (AND) — "band": both bits must be 1 to get 1.
- | (OR) — at least one bit is 1 to get 1.
- ^ (XOR) — 1 only when bits differ: "Not (A and B) but (A or B)".
- ~ (NOT) — flips every bit to its opposite.

> XOR = "exclusive" or → true when exactly one input is true.
> Think of & as a strict gatekeeper (both must agree), | as an easy-going
gatekeeper (one is enough), and ^ as a difference-detector.

## Shift Operators — Left Shift (<<)

- Left shift is basically multiplication by powers of 2.
- Formula: x << n = x * 2ⁿ
- Every bit moves left by n places; zeros fill in from the right.

> Fractions are denoted by left shifting as there are NO decimal points

There is NO binary representation for negative.
So, we use the positive number's **2'S COMPLEMENT**

```
+67 = 01000011 (first 0 denotes positive sign)
-67 = 10111101 

+67 
--> 1's complement: 10111100 + 1 
--> 2's complement: 10111101 (first 1 denotes negative sign)
 ```
[Floating Point Format/Variables](https://www.puntoflotante.net/FLOATING-POINT-FORMAT-IEEE-754.htm)<br><br>

When you define a variable of type "float" in memory, the value is stored in 4 bytes, or 32 bits, distributed as follows: a sign bit, 8 bit exponent and a mantissa of 23 bits.<br><br>
To convert the floating point format to a decimal value, an implicit "1" is added to the 23 bit mantissa forming a 24 bit mantissa.

## Shift Operators — Right Shift (>>)

▸ Right shift is division by powers of 2.

▸ The quotient is either FLOOR (⌊ ⌋) or CEILING (⌈ ⌉),
depending on the number's sign bit.

▸ Positive numbers round down (floor); negative
numbers round up toward zero (ceiling) under
arithmetic shift.

### Two Types of Right Shift

1. Arithmetic Right Shift

Pads with the appropriate SIGN BIT on the left — 0s for
positive numbers, 1s for negative numbers.

Preserves the sign of the number.

→ This is what C uses by default.

2. Logical Right Shift

Pads with 0s — ALWAYS, no exceptions.

C does NOT have this operator natively — Java does (>>>).
To get this behavior in C, qualify your datatype as
UNSIGNED, so its memory range becomes 0 to 2ⁿ.

**BIT-LEVEL ACCESSING**

# SETS
A set is a collection of UNIQUE objects called elements or members.

List Behavior<br>
▸ Duplicate elements: YES <br>
▸ Order is significant: YES

Set Behavior<br>
▸ Duplicate elements: NO <br>
▸ Order is significant: NO

## Why Order Matters — Set vs List

LIST EXAMPLE

Looking for the name "Beyoncé" in a sorted arrayList of names? Since the list is in order, you only traverse records starting
with letters A through B — you never need to look at names starting with C or later.

SET RULE

For a set: use != to search — order gives no shortcut, so you may have to check every element.


## Notation, Cardinality & Power Set

### Set Notation

Roster/Tabular:

A = {Blossom, Bubbles, Buttercup}

Set-Builder/Set-Former:

A = {x | x is a powerpuff girl}

### Cardinality

Denoted by | |. Example: |A| = 3 because Set A has 3
elements.

### POWER SET

The power set is the set of ALL subsets of a set S.
Example: A = {1, 2} → P(A) = { {1,2}, ∅, {1}, {2} }

Rule: cardinality of the power set = 2 raised to the power of |S|. Here |A|=2, so |P(A)| = 2² = 4 ✓

## Set Operations at a Glance
1. Union
2. Intersection
3. Difference
4. Initialize
5. Make Null
6. Merge
7. isMember
8. Insert
9. Assign
10. Min
11. Max
12. Equal
13. Find
14. Delete

Union vs Intersection vs Merge
- Union & Intersection are commutative. Difference is NOT commutative. <br> 
- Merge = union of sets A and B that are DISJOINT (no intersection). -- must have no common elements to start
- Merge !== Symmetric Difference though they have the same output
- Symmetric Difference = Keeps elements that are in either set, but excludes the items they share in common.


## ADT UID & Its Implementations

ADT UID = Union, Intersection, Difference (plus Initialize / MakeNull and more).

Array
(static/dynamic)

→

Linked List
(singly/doubly)

→

Cursor-Based

→

Bit Vector
(NEW)

### OTHER ADTs BUILT ON SETS

Dictionary • Priority Queue — both reuse core set concepts and operations under different constraints (e.g. keyed lookup,
ordering by priority).

## BIT VECTOR IMPLEMENTATION

Array of Boolean -- check if a value already exists (1) in the set or not (0)

# remaining notes have to be copy-pasted/written down

# SETS -- CODING ACTIVITY

```
#include<stdio.h>
#include<stdbool.h>

#define MAX 10 

typedef bool Set[MAX];

bool addElement(Set s, int item);
bool removeElement(Set s, int item);

void display(Set s);

// Basic UID = Union, Intersection, Difference
void setUnion(Set a, Set b, Set result);
bool *setIntersection(Set a, Set b);
bool *setDifference(Set a, Set b);
// malloc REQUIRED for I & D, return address of a bool due to bool array


/*
Set A = { 1 2 3 4 5 }
Set B = { 4 5 6 7 8 }

Union (A ∪ B) = { 1 2 3 4 5 6 7 8 }
Intersection (A ∩ B) = { 4 5 }
Difference (A - B) = { 1 2 3 }
*/

int main() {
    Set a[MAX], b[MAX];
    
    addElement(a, 1);
    
}


/*
// Helper function to check if a value exists in an array
int contains(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

// 1. Union: Combines all unique elements from both sets
int setUnion(int setA[], int sizeA, int setB[], int sizeB, int result[]) {
    int k = 0;
    
    // Add all elements from setA
    for (int i = 0; i < sizeA; i++) {
        if (!contains(result, k, setA[i])) {
            result[k++] = setA[i];
        }
    }
    
    // Add elements from setB if they aren't already in the result
    for (int i = 0; i < sizeB; i++) {
        if (!contains(result, k, setB[i])) {
            result[k++] = setB[i];
        }
    }
    return k; // Return size of the union set
}

// 2. Intersection: Finds elements common to both sets
int setIntersection(int setA[], int sizeA, int setB[], int sizeB, int result[]) {
    int k = 0;
    
    // Add elements that exist in both setA and setB
    for (int i = 0; i < sizeA; i++) {
        if (contains(setB, sizeB, setA[i])) {
            if (!contains(result, k, setA[i])) {
                result[k++] = setA[i];
            }
        }
    }
    return k; // Return size of the intersection set
}

// 3. Difference (A - B): Finds elements in setA that are NOT in setB
int setDifference(int setA[], int sizeA, int setB[], int sizeB, int result[]) {
    int k = 0;
    
    // Add elements from setA only if they don't exist in setB
    for (int i = 0; i < sizeA; i++) {
        if (!contains(setB, sizeB, setA[i])) {
            if (!contains(result, k, setA[i])) {
                result[k++] = setA[i];
            }
        }
    }
    return k; // Return size of the difference set
}

// Helper function to print a set
void printSet(char *name, int set[], int size) {
    printf("%s = { ", name);
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

int main() {
    int setA[] = {1, 2, 3, 4, 5};
    int sizeA = sizeof(setA) / sizeof(setA[0]);
    
    int setB[] = {4, 5, 6, 7, 8};
    int sizeB = sizeof(setB) / sizeof(setB[0]);
    
    int result[100];
    int resultSize;
    
    printSet("Set A", setA, sizeA);
    printSet("Set B", setB, sizeB);
    printf("\n");
    
    // Compute and print Union
    resultSize = setUnion(setA, sizeA, setB, sizeB, result);
    printSet("Union (A ∪ B)", result, resultSize);
    
    // Compute and print Intersection
    resultSize = setIntersection(setA, sizeA, setB, sizeB, result);
    printSet("Intersection (A ∩ B)", result, resultSize);
    
    // Compute and print Difference (A - B)
    resultSize = setDifference(setA, sizeA, setB, sizeB, result);
    printSet("Difference (A - B)", result, resultSize);
    
    return 0;
}
*/
```
