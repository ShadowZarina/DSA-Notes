# Definition

- A cursor-based linked list in C is a technique used to simulate a traditional pointer-based linked list using a fixed-size array of structures.
- This approach is particularly useful in environments where dynamic memory allocation (malloc, free) is unavailable, restricted, or too slow.
- Instead of physical memory addresses, the "pointers" are simply array indices (integers).
