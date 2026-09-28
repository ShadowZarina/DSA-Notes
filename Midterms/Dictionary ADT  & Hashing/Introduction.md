# References:
https://cs.slides.com/colt_steele/hash-tables
> And Sir Gran's AI-Generated PPT

# What Is a Dictionary (ADT)?
≡ It's a SET
A Dictionary is simply a set of elements — nothing more exotic than that.

```
JAVA COLLECTION EXAMPLE

String []names = {"Maria","Yu","Young"};

for (String name: names) {
  System.out.println(name;
}

OR

for (int i = 0; i < names.length; i++) {
  System.out.println(names[i]);
}

ArrayList list = new ArrayList();

Array Operations = insert first, last, middle, etc. list can do all of that with *preset collection frameworks*

list."command here" eg. list.add("To Chip");
```

✦ Three core operations
insert() · delete() · member() — everything else in this unit builds toward these.

✦ Real application
Database Management Systems run on exactly this pattern under the hood.

## Why It Matters
Forget the paper dictionary for a second. In CS, a
Dictionary ADT is just a set of elements with three
jobs: put something in, take something out, and
check if something's there. DBMSs use exactly this
pattern — that's why this matters.

# Ways to Implement a Dictionary
1. Linked List
2. Array
3. Cursor-Based
4. Hashing

# What Is Hashing?

Uses a HASH() function that determines / provides:

(a) the exact LOCATION of the element, OR

(b) a STARTING POINT for searching for it

Converts a key into a table index

Goal: average-case O(1) access — no linear scanning required

KEY

HASH()

INDEX

⌗

Think of It As...

A GPS coordinate for your data. Instead of walking
down every aisle to find something, the hash
function tells you exactly which aisle — or at least
where to start looking.

## Two Kinds of Hashing

### Open Hashing

a.k.a. External Hashing

“easier” to build

Potentially UNLIMITED space

Built with linked lists

### Closed Hashing

a.k.a. Internal Hashing

Stricter to manage

Uses FIXED space

Built with arrays / cursors

# Hash Function Design — Practice

1) Ones digit

int HASH(int num){

return num % 10;

}

2) Hundredths digit

int HASH(int num){

return num % 1000 / 100;

}

3) Last-name first letter

(A=0, B=1, ...)

int HASH(char lname[]){

return toupper(lname[0]) - 65;

}

4) Digit-sum mod 19

(range 0–18)

int HASH(int x){

int c = 0;

for(; x!=0; x/=10)

c += x % 10;

return c % 19;

}

Dictionary ADT & Hashing

6

OPEN HASHING

Open Hashing: Structure & Example

Set A = {0,13,26,28,30,33,45,48,108}, MAX = 10 buckets

Each bucket is the HEAD of a linked list (a “chain”)

Same-hash elements just get chained together

No overflow problem — a chain can grow indefinitely

⚓

Picture It

Bucket 0 is a coat rack — every coat that fits hook 0
just hangs on the same hook, one after another.

Open Hashing: Core Functions

struct node {

int elem;

struct node *next;

} type, *ptr;

typedef ptr Dictionary[MAX];

void initDict(Dictionary D){

for(i=0;i<MAX;i++)

D[i]=NULL;

}

⚠

Common Bug

Skip initDict() and your “empty” buckets point to
garbage memory — silent, unpredictable crashes
later.

PopDict() hashes each set element, mallocs a node,
and links it into the correct chain.

Dictionary ADT & Hashing

8

CLOSED HASHING

Closed Hashing: Key Terms

Synonyms

2+ elements with the SAME hash value.

Displacement

A NON-synonym occupies the slot you
needed.

Collision

A SYNONYM occupies the slot you needed.

Example: H(a) = 3, H(d) = 3 → 'a' and 'd' are synonyms → inserting 'd' causes a COLLISION.

🙋

The Seat Metaphor

A slot is a seat. A synonym is a roommate who wants YOUR seat — that's a collision. A displacement is just an unrelated stranger sitting there.

Dictionary ADT & Hashing

9

CLOSED HASHING

Solving Collisions #1: Linear Hashing

Hi(x) = ( H(x) + i ) % MAX

Places the element in the next available slot, wrapping circularly

Simple to implement — but DISPLACEMENT can still ripple outward

Example: 'd' & 'j' collide at index 3 → 'j' gets displaced elsewhere entirely

🌊

Ripple Effect

Bumping one element can bump another that was
never even involved in the original collision. That's
the hidden cost of Linear Hashing's simplicity.
