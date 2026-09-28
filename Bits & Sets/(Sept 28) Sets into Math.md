
# REFERENCES
https://alpharithms.s3.amazonaws.com/assets/img/ascii-chart/ascii-table-alpharithms-scaled.jpg
https://drive.google.com/drive/folders/13co-MUfx08MWekD2iVn9vN_M7KEfnCCz

```
#define MAX 10

typedef int Set[MAX]; // 4 bytes
typedef bool Set[MAX]; // 1 byte

typedef struct {
    bool elems[MAX];
    int count; // cardinality
} Set;

/*
bool *elems;
int count;
int max;
*/

Cartesian Plane = Universal Set
char setA = 75
what is the universal set of setA? 75
= 8 values {0,1,2,3,4,5,6,7} in universal set 
what is inside setA?

SetA = {0,1,3,6}
what is the cardinality of SetA?
|SetA| = 4 

HOW?

128 - 64 - 32 - 16 - 8 - 4 - 2 - 1 (value as 2^n)
7 - 6 - 5 - 4 - 3 - 2 - 1 - 0 (value as index)
0   1   0   0   1   0   1   1  -> 64 + 8 + 2 + 1 = 75

if char setB = -47, what is the universal set?
what's the cardinality of set B?

Get the 2's complement
00101111 --> 11010000 + 1 = 11010001

setB = {0,4,6,7}
|setB| = 4 


setC = setA U setB 
= setA | setB 
= 75 | -47 
= setC = {0,1,3,4,6,7} or -39 (if int setC)

use 2's complement due to negative value
11011011 --> 00100100 + 1 = 00100111

2^5 + 2^2 + 2^1 + 2^0 = -39 

int setD;
char setF[5];

```
