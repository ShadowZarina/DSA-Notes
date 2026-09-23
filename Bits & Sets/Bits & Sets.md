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
