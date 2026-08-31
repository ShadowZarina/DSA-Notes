ARRAY IMPLEMENTATION
LINKED LIST IMPLEMENTATION
NEXT MEETING: CURSOR-BASED IMPLEMENTATION

Pointer to Node

myList -> [data, link] -> [data, link] -> [data, link] -> NULL
trav -> first node (which is what myList points to)

How to declare: 
List *myList;
List *trav;  
Since they have the same content/point to the same info, trav = myList

To move to the next node:
trav = myList->link
trav = trav->link

How to for loop:
for (trav = myList; trav != NULL; trav = trav->link)

Pointer to Pointer to Node

List *myList;
List **trav;
trav = &myList; 

trav -> myList -> [data, link] -> [data, link] -> [data, link] -> NULL

for (trav = &myList; *trav != NULL; trav = &(*trav)->link)

trav = &(**trav).link
trav = &(*trav) -> link

NOTE: *trav is equal to myList, **trav is equal to the first node

SAMPLE PROBLEM: EMPTY LIST

Current setup:
list -> myList -> NULL

Struct code:
Typedef struct node {
	int data;
	struct node *next;
} List, *ListPtr;

void insertRear (ListPtr list, int item);

1. Allocate memory

*list = malloc(sizeof(List));
(*list)->next = NULL;
(*list)->data = item;

2. Make a new node

void insertRear (ListPtr list, int item) {

for (ListPtr trav = list; *trav != NULL; trav = &(*trav)->next) {

*trav = malloc(sizeof(List));
(*trav)->next = NULL;
(*trav)->data = item;
}
}

3. INSERT SORTED FUNCTION:

List -> myList
Trav -> myList
myList -> [data, link] -> [data, link] -> NULL

for (trav = list; *trav != NULL && (*trav)->data < item; trav = &(*trav)->next) {
// make temp variable
temp = malloc(sizeof(List));
temp->next = *trav;
*trav = temp;
}

temp -> NEW NODE [data, link] 
1st node link points to new node, new node link points to 3rd node
FINAL CODE:

void insertSorted(ListPtr *list, int item) { 
	ListPtr *trav, *temp;
	for (trav = list; *trav != NULL && (*trav)->data < item; trav = &(*trav)->next) {
		temp = malloc(sizeof(List));
		if(temp) {
			temp->next = *trav;
*trav = temp;	
		}
	}
}

[PUT IN NOTES FOR INSERT AT POSITION PROBLEM, ADD TO GITHUB]

Discuss new topic next meeting: cursor-based

PLEASE FREE AFTER YOU MALLOC ANDREA

Array vs Linked List




Array
Singly Linked List
Doubly Linked List
insertFront
O(n)
O(1)  – no need to traverse
O(1)
insertRear
O(1) – just add directly with index
O(n) – need to traverse
O(1)
deleteFront
O(n)
O(1)
O(1)
deleteRear
O(1)
O(n)
O(n)


Singly = head only, doubly = head & tail
Array is better for rear, linked lists for front
