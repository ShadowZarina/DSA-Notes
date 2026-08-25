#include <stdio.h>
#include <stdlib.h>

#include "statistics.h"


/* =========================
   MEAN
   ========================= */

float mean(List list)
{
    int i;
    float sum = 0.0f;

    if (list.count == 0) {
        return 0.0f;
    }

    for (i = 0; i < list.count; i++) {
        sum += list.elems[i];
    }

    return sum / list.count;
}


/* =========================
   MEDIAN
   ========================= */

float median(List list)
{
    int middle;

    if (list.count == 0) {
        return 0.0f;
    }

    /*
     * insertSorted() keeps the array sorted,
     * so we can directly find the middle.
     */

    middle = list.count / 2;

    /*
     * Odd number of elements.
     */
    if (list.count % 2 != 0) {
        return list.elems[middle];
    }

    /*
     * Even number of elements.
     */
    return (list.elems[middle - 1] + list.elems[middle]) / 2.0f;
}


/* =========================
   MODE
   ========================= */

float mode(List list)
{
    int i;
    int currentCount;
    int maxCount;
    int modeValue;

    if (list.count == 0) {
        return 0.0f;
    }

    /*
     * Because insertSorted() keeps the list
     * sorted, equal values are beside each other.
     */

    maxCount = 1;
    currentCount = 1;
    modeValue = list.elems[0];

    for (i = 1; i < list.count; i++) {

        if (list.elems[i] == list.elems[i - 1]) {

            currentCount++;

        }
        else {

            if (currentCount > maxCount) {
                maxCount = currentCount;
                modeValue = list.elems[i - 1];
            }

            currentCount = 1;
        }
    }

    /*
     * Check the final group.
     */
    if (currentCount > maxCount) {
        maxCount = currentCount;
        modeValue = list.elems[list.count - 1];
    }

    return modeValue;
}
