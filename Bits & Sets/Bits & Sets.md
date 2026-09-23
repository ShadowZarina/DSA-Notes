From Bitwise Operators to Set ADTs — Concepts, Math, and C Code

# BITS
- BIT is short for Binary Digit — values are built only from 1s and 0s. 
- In value terms: 1 = true, 0 = false (the "bit value").
- In sign terms: 1 = negative, 0 = positive (the "sign bit", the leftmost/most significant bit).
- Everything else we do with bits — logic, shifting, negative numbers — builds on these two roles.

Example: byte: char A = 75

> Leftmost bit (bold outline) = SIGN BIT → 0 means positive

## Bitwise Operators

▸ & (AND) — "band": both bits must be 1 to get 1.
▸ | (OR) — at least one bit is 1 to get 1.
▸ ^ (XOR) — 1 only when bits differ: "Not (A and B) but (A or B)".
▸ ~ (NOT) — flips every bit to its opposite.
