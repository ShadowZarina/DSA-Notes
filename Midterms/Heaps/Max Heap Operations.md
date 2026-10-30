Heaps & Priority Structures
This subtab introduces heaps, a tree-based data structure commonly implemented using arrays. This question focuses on the basic operations of a Max Heap, including insertion, deletion, checking the heap’s current state, and restoring the heap property.
1. MAX HEAP OPERATIONS
by Gran Sabandal
Description
A Max Heap is an array where every parent is greater than or equal to its children. Because of this property, the largest value is always stored at index 0.
For an element located at index i, its parent and children can be determined using the following formulas:
Parent      = (i - 1) / 2
Left Child  = 2i + 1
Right Child = 2i + 2
The heap can hold a maximum of:
MAX = 20
lastNdx represents the index of the last element currently stored in the heap.
lastNdx = -1
indicates that the heap is empty.
The program contains a pool of 50 numbers. The function:
populateData(count, order)
inserts up to count values into the heap using the insert function.
The values inserted depend on the specified order.
Order     Numbers Used

0         All numbers, in sequence
1         Odd records
2         Even records
3         First half
4         Second half
After the heap has been populated, the program deletes the maximum element D times.
Task
Complete the following 5 TODO functions:
1. isEmpty
Return 1 if the heap contains no elements.
int isEmpty(Heap H)
The heap is considered empty when:
lastNdx == -1

2. isFull
Return 1 if the heap already contains MAX elements.
int isFull(Heap H)
Since array indexing begins at 0, a full heap has its final element at:
lastNdx == MAX - 1

3. insert
Insert a new value into the Max Heap.
void insert(Heap *H, int value)
The operation should:
1. Check whether the heap is full.
2. Add the new value at the end.
3. Compare the new value with its parent.
4. If the new value is larger, swap them.
5. Continue moving upward until the Max Heap property is restored.
If the heap is already full, print:
Heap is full: <x> not inserted.
where <x> is the value that could not be inserted.

4. maxHeapify
Restore the Max Heap property starting from a given index.
void maxHeapify(Heap *H, int i)
Determine the children using:
left  = 2i + 1
right = 2i + 2
The operation should:
1. Find the larger child.
2. Compare it with the current element.
3. Swap if the child is larger.
4. Continue downward until the current element
   is greater than or equal to both children.

5. deleteMax
Delete the maximum value from the heap.
void deleteMax(Heap *H)
Since this is a Max Heap, the maximum value is located at:
index 0
The operation should:
1. Check whether the heap is empty.
2. Save the value at index 0.
3. Move the last element to index 0.
4. Decrease the heap size.
5. Call maxHeapify(H, 0).
6. Print the deleted value.
The required output is:
Deleted: <value>
If the heap is empty, print:
Heap is empty
Sample Output 1
Enter number of data to insert and sequence: 5 0
Enter number of data to delete: 1
Initial Heap: 78 56 45 3 12
Deleted: 78
Final Heap: 56 12 45 3
Size: 4
Sample Output 2
Enter number of data to insert and sequence: 0 0
Enter number of data to delete: 0
Initial Heap: (empty)
Final Heap: (empty)
Size: 0
Sample Output 3
Enter number of data to insert and sequence: 0 0
Enter number of data to delete: 2
Initial Heap: (empty)
Heap is empty
Heap is empty
Final Heap: (empty)
Size: 0


CODE BOILERPLATE


#include <stdio.h>
#define MAX 20

typedef struct {
    int Elem[MAX];
    int lastNdx;            /* index of last element, -1 if empty */
} ListHeap;

/* ============================================================================
   MASTER POOL (50 NUMBERS)
   Includes duplicates, zero and negative numbers.
   ============================================================================ */
static const int MASTER_DATA[50] = {
    /* 1 to 10  */  45, 12, 78,  3, 56, 89, 23, 67, 34, 91,
    /* 11 to 20 */  15, 72,  8, 60, 41, 99, 27, 50,  5, 83,
    /* 21 to 30 */  38, 64, 19, 76, 30, 55, 55, -7,  0, 42,
    /* 31 to 40 */  42, 18, -15, 70, 9, 88, -3, 61, 25, 25,
    /* 41 to 50 */ 100, -20, 47, 13, 36, 2, 95, -1, 58, 74
};

void initHeap(ListHeap *H) {
    // Code here...
}

int isEmpty(ListHeap H) {
    // Code here...
}

int isFull(ListHeap H) {
    // Code here...
}

void insert(ListHeap *H, int x) {
	// Code here...
}

void maxHeapify(ListHeap *H, int ndx) {
// Code here...
}

int deleteMax(ListHeap *H) {
// Code here...
}

/* ============================================================================
   POPULATE FUNCTION
   order 0 = all records in sequence (1st to 50th)
   order 1 = odd records  (1st, 3rd, 5th ...)
   order 2 = even records (2nd, 4th, 6th ...)
   order 3 = 1st half     (1st to 25th)
   order 4 = 2nd half     (26th to 50th)
   ============================================================================ */
void populateData(ListHeap *H, int count, int order) {
    int start = 0, end = 50, step = 1, loaded = 0, i;

    if (order == 1)      { start = 0;  step = 2; }
    else if (order == 2) { start = 1;  step = 2; }
    else if (order == 3) { start = 0;  end = 25; }
    else if (order == 4) { start = 25; end = 50; }

    for (i = start; i < end && loaded < count; i += step) {
        insert(H, MASTER_DATA[i]);
        loaded++;
    }
}

void display(ListHeap H, char label[]) {
    int i;
    printf("%s:", label);
    if (isEmpty(H)) { printf(" (empty)\n"); return; }
    for (i = 0; i <= H.lastNdx; i++) printf(" %d", H.Elem[i]);
    printf("\n");
}
int main() {
    ListHeap H;
    int count, order, del, i;
    initHeap(&H);

    printf("Enter number of data to insert and sequence: ");
    scanf("%d %d", &count, &order);
    printf("Enter number of data to delete: ");
    scanf("%d", &del);

    populateData(&H, count, order);
    display(H, "Initial Heap");

    for (i = 0; i < del; i++) deleteMax(&H);
    display(H, "Final Heap");
    printf("Size: %d\n", H.lastNdx + 1);
    return 0;
}


SAMPLE ANSWER


#include <stdio.h>
#define MAX 20

typedef struct {
    int Elem[MAX];
    int lastNdx;            /* index of last element, -1 if empty */
} ListHeap;

/* ============================================================================
   MASTER POOL (50 NUMBERS)
   Includes duplicates, zero and negative numbers.
   ============================================================================ */
static const int MASTER_DATA[50] = {
    /* 1 to 10  */  45, 12, 78,  3, 56, 89, 23, 67, 34, 91,
    /* 11 to 20 */  15, 72,  8, 60, 41, 99, 27, 50,  5, 83,
    /* 21 to 30 */  38, 64, 19, 76, 30, 55, 55, -7,  0, 42,
    /* 31 to 40 */  42, 18, -15, 70, 9, 88, -3, 61, 25, 25,
    /* 41 to 50 */ 100, -20, 47, 13, 36, 2, 95, -1, 58, 74
};

void initHeap(ListHeap *H) {
    H->lastNdx = -1;
}

int isEmpty(ListHeap H) {
    return (H.lastNdx == -1) ? 1 : 0;
}

int isFull(ListHeap H) {
    return (H.lastNdx == MAX - 1) ? 1 : 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(ListHeap *H, int x) {
    if (isFull(*H)) {
        printf("Heap is full: %d not inserted\n", x);
        return;
    }
    
    H->lastNdx++;
    int i = H->lastNdx;
    H->Elem[i] = x;
    
    
    while (i > 0) {
        int parent = (i - 1) / 2;
        
        if (H->Elem[i] > H->Elem[parent]) {
            swap(&H->Elem[i], &H->Elem[parent]);
            i = parent;
        } else {
            break;
        }
    }
    
}

void maxHeapify(ListHeap *H, int ndx) {
    int i = ndx;
    
    while (1) {
        int largest = i;
        int left = (2*i) + 1;
        int right = (2*i) + 2;
        
        if (left <= H->lastNdx && (H->Elem[left] > H->Elem[largest])) {
            largest = left;
        } 
        
        if (right <= H->lastNdx && H->Elem[right] > H->Elem[largest]) {
            largest = right;
        } 
        
        if (largest == i) {
            break;
        }
        
        swap(&H->Elem[largest], &H->Elem[i]);
        i = largest;
    }
    
}

int deleteMax(ListHeap *H) {
    if (isEmpty(*H)) {
        printf("Heap is empty\n");
        return 0;
    }
    
    int root = H->Elem[0];
    int max = root;
    H->Elem[0] = H->Elem[H->lastNdx--];
    
    if (H->lastNdx >= 0) maxHeapify(H, 0);
    
    printf("Deleted: %d\n", max);
    
    return 0;
}

/* ============================================================================
   POPULATE FUNCTION
   order 0 = all records in sequence (1st to 50th)
   order 1 = odd records  (1st, 3rd, 5th ...)
   order 2 = even records (2nd, 4th, 6th ...)
   order 3 = 1st half     (1st to 25th)
   order 4 = 2nd half     (26th to 50th)
   ============================================================================ */
void populateData(ListHeap *H, int count, int order) {
    int start = 0, end = 50, step = 1, loaded = 0, i;

    if (order == 1)      { start = 0;  step = 2; }
    else if (order == 2) { start = 1;  step = 2; }
    else if (order == 3) { start = 0;  end = 25; }
    else if (order == 4) { start = 25; end = 50; }

    for (i = start; i < end && loaded < count; i += step) {
        insert(H, MASTER_DATA[i]);
        loaded++;
    }
}

void display(ListHeap H, char label[]) {
    int i;
    printf("%s:", label);
    if (isEmpty(H)) { printf(" (empty)\n"); return; }
    for (i = 0; i <= H.lastNdx; i++) printf(" %d", H.Elem[i]);
    printf("\n");
}
int main() {
    ListHeap H;
    int count, order, del, i;
    initHeap(&H);

    printf("Enter number of data to insert and sequence: ");
    scanf("%d %d", &count, &order);
    printf("Enter number of data to delete: ");
    scanf("%d", &del);

    populateData(&H, count, order);
    display(H, "Initial Heap");

    for (i = 0; i < del; i++) deleteMax(&H);
    display(H, "Final Heap");
    printf("Size: %d\n", H.lastNdx + 1);
    return 0;
}


