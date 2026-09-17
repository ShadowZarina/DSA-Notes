# 03 - The Tech Depot Checkout Counter
by Gran Sabandal

## SCENARIO

During the peak enrollment rush at the campus Tech Depot, long lines of students form at the central checkout register to purchase lab kits, accessories, and components. To handle rapid transactions, the point-of-sale terminal uses a dynamic staging stack called "Cart Stash."
<br><br>
Whenever an item is scanned, it is placed directly on top of the customer's staging pile. However, students frequently change their minds right before payment—realizing they grabbed the wrong connector or exceeded their budget—and request an immediate "Undo" or "Return Item."
<br><br>
Because items are physically stacked as they are scanned, the counter operates on a strict Last-In, First-Out (LIFO) rule: the most recently scanned item resting at the top must be the first one lifted off and returned to the inventory cart.
<br><br>
During a firmware update, the low-level stack driver for the register was wiped. The hardware terminal has strict memory constraints, so the system models the cart purely as a linked chain of nodes without wrapper structures or counter variables:
```
typedef struct StackNode {
    CartItem item;
    struct StackNode *next;
} StackNode;
```
An empty counter is represented simply by NULL.

Your goal is to reconstruct the register's core driver by implementing:
- **pushItem**: Staging a newly scanned item by allocating a node on top of the pile.
- **popItem**: Handling an "Undo" request by safely removing the top item, returning its data for the void slip, and freeing the memory back to the system.


## Sample Outputs

Sample Output 1
```
Enter number of operations: 0
Enter items to add: === INITIAL INPUT SEQUENCE (RAW/SELECTED CATALOG DATA) ===
Total Items Selected for Push: 0
  [None]

=== STACK PUSH OPERATIONS ===

=== STACK STATE (AFTER ALL PUSHES) ===
  [Empty Stack / TOP is NULL]
Enter number items to remove: 0

=== STACK POP OPERATIONS ===

=== FINAL STACK STATE (AFTER ALL POPS) ===
  [Empty Stack / TOP is NULL]
```
Sample Output 2
```
Enter number of operations: 0
Enter items to add: === INITIAL INPUT SEQUENCE (RAW/SELECTED CATALOG DATA) ===
Total Items Selected for Push: 0
  [None]

=== STACK PUSH OPERATIONS ===

=== STACK STATE (AFTER ALL PUSHES) ===
  [Empty Stack / TOP is NULL]
Enter number items to remove: 1

=== STACK POP OPERATIONS ===
-> POP  OPERATION                       | Status: FAILED (0)  | Reason: Stack Underflow (Empty)

=== FINAL STACK STATE (AFTER ALL POPS) ===
  [Empty Stack / TOP is NULL]
```
Sample Output 3
```
Enter number of operations: 1
Enter items to add: 0
=== INITIAL INPUT SEQUENCE (RAW/SELECTED CATALOG DATA) ===
Total Items Selected for Push: 1
  [0] ID: 501  | Mechanical Keyboard      | PHP  2499.00 | Qty: 1

=== STACK PUSH OPERATIONS ===
-> PUSH ID 501  (Mechanical Keyboard   ) | Status: SUCCESS (1)

=== STACK STATE (AFTER ALL PUSHES) ===
  [0] [TOP] ID: 501  | Mechanical Keyboard      | PHP  2499.00 | Qty: 1
Enter number items to remove: 1

=== STACK POP OPERATIONS ===
-> POP  ID 501  (Mechanical Keyboard   ) | Status: SUCCESS (1) | Price: PHP 2499.00

=== FINAL STACK STATE (AFTER ALL POPS) ===
  [Empty Stack / TOP is NULL]
```

## CODE

### main.c
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cis2101.h"

int main(void) {
    const CartItem POOL[POOL_SIZE] = {
        {501, "Mechanical Keyboard",    2499.00f, 1}, // [0]
        {502, "Wireless Mouse",         1250.50f, 2}, // [1]
        {503, "USB-C Hub Multiport",     899.00f, 1}, // [2]
        {504, "Gaming Headset 7.1",     3150.00f, 1}, // [3]
        {505, "1080p Webcam with Mic",  1450.00f, 1}, // [4]
        {506, "Desk Mousepad XXL",       450.00f, 3}, // [5]
        {507, "Laptop Stand Aluminum",   720.00f, 1}, // [6]
        {508, "HDMI 2.1 Cable 2m",       299.00f, 2}, // [7]
        {509, "External SSD 1TB NVMe",  4899.00f, 1}, // [8]
        {510, "USB Flash Drive 64GB",    250.00f, 4}, // [9]
        {511, "Screen Cleaning Kit",     150.00f, 1}, // [10]
        {512, "Bluetooth Speaker",      1890.00f, 1}, // [11]
        {513, "Ergonomic Wrist Rest",    380.00f, 2}, // [12]
        {514, "CAT6 LAN Cable 5m",       180.00f, 3}, // [13]
        {515, "DisplayPort Cable 1.8m",  340.00f, 1}, // [14]
        {516, "Microphone Boom Arm",     850.00f, 1}, // [15]
        {517, "Ring Light 10-inch",      650.00f, 1}, // [16]
        {518, "Cable Organizer Clips",    99.00f, 5}, // [17]
        {519, "Surge Protector 6-Way", 1190.00f, 1}, // [18]
        {520, "Wireless Charger Pad",    599.00f, 2}, // [19]
        {521, "Thermal Paste 4g",        280.00f, 1}, // [20]
        {522, "Case Fan 120mm RGB",      420.00f, 3}, // [21]
        {523, "Portable Powerbank 20k", 1650.00f, 1}, // [22]
        {524, "Monitor Light Bar",      1799.00f, 1}, // [23]
        {525, "Graphic Drawing Tablet", 3299.00f, 1}, // [24]
        {526, "Earbuds TWS Wireless",   1499.00f, 1}, // [25]
        {527, "Mini Tripod Flexible",    220.00f, 2}, // [26]
        {528, "Keycap Puller Steel",      85.00f, 1}, // [27]
        {529, "SATA III SSD 500GB",     2150.00f, 1}, // [28]
        {530, "Anti-Static Wrist Band",  120.00f, 1}  // [29]
    };

    int numPushes;
    printf("Enter number of operations: ");
    if (scanf("%d", &numPushes) != 1 || numPushes < 0) return 0;

    CartItem initialInputs[numPushes];
    int validCount = 0;
    printf("Enter items to add: ");
    for (int i = 0; i < numPushes; i++) {
        int poolIndex;
        if (scanf("%d", &poolIndex) != 1) break;
        if (poolIndex >= 0 && poolIndex < POOL_SIZE) {
            initialInputs[validCount++] = POOL[poolIndex];
        }
    }

    printInitialInputs(initialInputs, validCount);

    ItemStack stack = NULL;

    printf("\n=== STACK PUSH OPERATIONS ===\n");
    for (int i = 0; i < validCount; i++) {
        int status = pushItem(&stack, initialInputs[i]);
        printPushLog(&initialInputs[i], status);
    }

    printf("\n");
    printStack(stack, "=== STACK STATE (AFTER ALL PUSHES) ===");

    int numPops;
    printf("Enter number items to remove: ");
    if (scanf("%d", &numPops) != 1 || numPops < 0) {
        clearStack(&stack);
        return 0;
    }

    printf("\n=== STACK POP OPERATIONS ===\n");
    for (int i = 0; i < numPops; i++) {
        CartItem popped;
        int status = popItem(&stack, &popped);
        printPopLog(status, &popped);
    }

    printf("\n");
    printStack(stack, "=== FINAL STACK STATE (AFTER ALL POPS) ===");

    clearStack(&stack);
    return 0;
}
```
### cis2101.h
```
#ifndef CIS2101_H
#define CIS2101_H

#define POOL_SIZE 30

typedef struct {
    int itemId;
    char itemName[32];
    float price;
    int qty;
} CartItem;

typedef struct StackNode {
    CartItem item;
    struct StackNode *next;
} StackNode, *ItemStack;

/* =============================================================
 * STUDENT TASK: Implement these two functions only
 * ============================================================= */

int pushItem(ItemStack *s, CartItem newItem);

int popItem(ItemStack *s, CartItem *outItem);

/* =============================================================
 * DISPLAY FUNCTIONS & MAIN DRIVER
 * ============================================================= */

void printCartItem(const CartItem *item);

void printInitialInputs(const CartItem arr[], int count);

void printStack(ItemStack top, const char *title);

void printPushLog(const CartItem *item, int status);

void printPopLog(int status, const CartItem *poppedItem);

void clearStack(ItemStack *s);

#endif
```

### answer.c
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cis2101.h"

/* =============================================================
 * STUDENT TASK: Implement these two functions only
 * ============================================================= */

int pushItem(ItemStack *s, CartItem newItem) {
    /*
    STACK -- insert at tail, delete at head 
    // s is at the bottom of the stack 
    */
    
    ItemStack temp = malloc(sizeof(StackNode));
    
    // Traversal is not needed as it's LIFO for O(1) notation
     if (temp != NULL) {

        temp->item = newItem;
        // 
        temp->next = *s;
        *s = temp;
        
        return 1;
     }
     
     return 0;
}

int popItem(ItemStack *s, CartItem *outItem) {
    if (*s == NULL) return 0;
    
    ItemStack temp = *s;
    
    // for (trav = s; *trav != NULL; trav = &(*trav)->next) {}
    
    if(outItem != NULL) {
        *outItem = temp->item;
    }
 
    *s = temp->next;
    free(temp);
    
    return 1;
}

/*
typedef struct {
    int itemId;
    char itemName[32];
    float price;
    int qty;
} CartItem;

typedef struct StackNode {
    CartItem item;
    struct StackNode *next;
} StackNode, *ItemStack;
*/
```
