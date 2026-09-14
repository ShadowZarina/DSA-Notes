# QUEUE ADT
- FCFS/FIFO/LILO

## OPERATIONS

### Important Operations
enqueue
- void/int/bool
- Queue*, data
dequeue
- void/int/bool/data
- Queue*
front
- data
- Queue

### Helper Functions
initQueue
- void, Queue*
newQueue
- Queue void
isEmpty
- int/bool, Queue
isFull
- int/bool, Queue

visualize
- void, Queue
display
- void, Queue

## TIME COMPLEXITY
1. insertEnd
2. deleteFront
3. deleteEnd

### ARRAY
- O(1)
- O(n)
- O(1)

### LINKED LIST (Singly Linked, Head)
head in rear
- O(1)
- O(n)
- O(n)

head in front
- O(n)
- O(1)
- O(1)

Singly Linked, two pointers: head, tail <br>
== but the insert is at tail
- O(1)
- O(1)
- O(1)
