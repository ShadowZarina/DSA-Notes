# BIG-OH NOTATION

The most fundamental operation of a computer is ADDITION. They don’t do subtraction, multiplication, etc.

Your programs will try to fall into the categories below. It’s best to have it as O(1) but we can’t force it. Just because a program has a for loop doesn’t mean a program is O(n). If a program is O(2n) or O(2n+5) or O(n/2), they will both fall into O(n).

O(1) = constant
O(n) = depends on value
O(n^2)
O(log n)

If n = 500:
- O(1) = 1
- O(n) = 500
- O(n^2) = 250000
- O(log n) = 10

## EXAMPLE 1:
```
for (i = 0; i < n; ++i)
i = 0 -> executed 1 time
i < n -> n + 1
++i -> n
```
- 0 < 3
- 1 < 3
- 2 < 3
- 3 < 3<br>
== a total of 4 runs

 Final notation: O(2n + 2) -> O(n)

## EXAMPLE 2:
```
for (int i = 0; i < min(3,n); ++i)
i = 0 -> executed 1 time
i < min(3,n) -> executed 4 times max (regardless of value of n)
++i -> executed 3 times max
```

Final notation: O(7) -> O(1)
> Therefore a for loop doesn’t guarantee O(n) or greater.

# POINTERS

## ARRAYS WITH STRUCTURES
```
#define N 20
Typedef struct {
	Int arr[N];
	Int count;
} List;

List list; -> List *pList;
pList = &list;
```
The datatype of list is List, List is a structure
The datatype of pList is List pointer

ARRAYS BY NATURE CONTAIN ADDRESSES, NOT THE VALUES THEMSELVES

Arr[0] is the same as *(arr+0)<br>
List arr[1] = 5; is the same as pList->arr[1] = 5; (SINCE PLIST POINTS TO LIST ARR)<br>
OR (*pList).arr[1] = 5;

## EXAMPLE 1:
```
Int x;
X = 5;  → 2 access methods
(x = access data)
(&x = address of data)

Int *p; → 3 access methods
P = &x; (p = address of x/value of p)
(&p = address of p)
(*p = value of x)

Int **d;  → 4 access methods
(d, &d, *d, **d)
D = &p;

D points to p, and p is pointing to x
If x = 5 and address is A100
Then *d/p = A100 and address is A500
Then d = A500 and address is A1000
4 properties of a variable = name, value, data type/size, address
```

The primary difference between the stack and the heap is how memory is allocated and managed: the stack is a fast, fixed-size memory region managed automatically by the CPU, whereas the heap is a larger, flexible memory region managed manually by the developer or a garbage collector.

Stack memory allocation is Automatic by compiler
Heap memory allocation is Manual via code (new, malloc) & MUST BE FREED

—
```
List *pList;
pList = malloc(sizeof(List))
```
= the pList and array have fixed sizes, it will only change when the array is borrowing memory

