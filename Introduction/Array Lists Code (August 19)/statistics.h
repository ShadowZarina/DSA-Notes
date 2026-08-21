#ifndef STATISTICS_H
#define STATISTICS_H
#include<stdbool.h>


// function declarations

// CHALLENGE 3: IMPLEMENT ALL OTHER FUNCTIONS
// all inserts, all deletes (delete first, delete last, delete by index), 2 searches: return true or false, return index, count (no of occurrences)
// create new header called statistics.h for the mode, median, mean
float mode(List list);
float median(List list);
float mean(List list);

#endif


