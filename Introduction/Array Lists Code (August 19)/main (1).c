#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "myheader.h"
#include "statistics.h"

int main() {
	List myList = newList(5);
	printf("\n");
	display(myList);
	insertSorted(&myList, 15);
	display(myList);
	insertSorted(&myList, 2);
	display(myList);
	insertSorted(&myList, 10);
	display(myList);
	insertSorted(&myList, 20);
	display(myList);
	
	return 0;
}
