#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "statistics.h"

float mean (List list) {
    if (list->count = 0) return 0;
    float sum = 0;
    for (int i = 0; i < list->size; i++) {
        sum += list->elems[i];
    }
    return sum / list->size;
}

float median (List list) {
    if (list->count = 0) return 0;
    
}

float mode (List list) {
    if (list->count = 0) return 0;
    
}
