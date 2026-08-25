#include <stdio.h>
#include <stdlib.h>
#include "statistics.h"

// C FILE THAT STORES MATH FUNCTIONS

/* MEAN */

float mean(List list)
{
    Node *current;
    float sum = 0.0f;

    if (list.count == 0) {
        return 0.0f;
    }

    current = list.head;

    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }

    return sum / list.count;
}


/* MEDIAN */

float median(List list)
{
    Node *current;
    Node *middle1;
    Node *middle2;
    int i;

    if (list.count == 0) {
        return 0.0f;
    }

    // Odd number of elements
    if (list.count % 2 != 0) {

        current = list.head;

        for (i = 0; i < list.count / 2; i++) {
            current = current->next;
        }

        return current->data;
    }

    // Even number of elements

    middle1 = list.head;

    for (i = 0; i < (list.count / 2) - 1; i++) {
        middle1 = middle1->next;
    }

    middle2 = middle1->next;

    return (middle1->data + middle2->data) / 2.0f;
}


/* MODE */

float mode(List list)
{
    Node *current;
    int currentCount;
    int maxCount;
    int modeValue;

    if (list.count == 0) {
        return 0.0f;
    }

    current = list.head;

    modeValue = current->data;
    maxCount = 1;

    currentCount = 1;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            currentCount++;
        }
        else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                modeValue = current->data;
            }
            currentCount = 1;
        }
        current = current->next;
    }

    if (currentCount > maxCount) {
        maxCount = currentCount;
        modeValue = current->data;
    }

    return modeValue;
}