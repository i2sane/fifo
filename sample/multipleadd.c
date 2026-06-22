#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include "../fifo.h"

int main(void) {
	int testItem = 1337;
	FifoQueue *f = mkQueue();
	if (!f)
		err(-1, NULL);
	for (int i = 0; i < 10; i++) {
		if (!addToQueue(f, &testItem, sizeof(testItem)))
			err(-1, NULL);
	}
	for (int i = 0; i < 10; i++) {
		int *poppedItem = (int *)popFromQueue(f);
		if (!poppedItem)
			err(-1, NULL);
		printf("%d: %d\n", i + 1, *poppedItem); 
		free(poppedItem);
	}
	destroyQueue(f);
	return 0;
}
