#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include "fifo.h"

int main(void) {
	int testItem = 1337;
	FifoStack f = mkStack();
	if (!addToStack(&f, &testItem, sizeof(testItem)))
		err(-1, NULL);
	int *poppedItem = (int *)popFromStack(&f);
	if (!poppedItem)
		err(-1, NULL);
	printf("%d\n", *poppedItem); 
	destroyStack(&f);
	free(poppedItem);
	return 0;
}
