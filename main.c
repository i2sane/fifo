#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include "fifo.h"

int main(void) {
	int testItem = 1337;
	FifoQueue f = mkQueue();
	if (!addToQueue(&f, &testItem, sizeof(testItem)))
		err(-1, NULL);
	int *poppedItem = (int *)popFromQueue(&f);
	if (!poppedItem)
		err(-1, NULL);
	printf("%d\n", *poppedItem); 
	destroyQueue(&f);
	free(poppedItem);
	return 0;
}
