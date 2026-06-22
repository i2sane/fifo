#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include "../fifo.h"

void testInt(FifoQueue *f) {
	int testInt = 1337;
	if (!addToQueue(f, &testInt, sizeof(testInt)))
		err(-1, NULL);
	int *poppedInt = (int *)popFromQueue(f);
	if (!poppedInt)
		err(-1, NULL);
	printf("%d\n", *poppedInt); 
	free(poppedInt);
}

void testFloat(FifoQueue *f) {
	float testFloat = 1234.567;
	if (!addToQueue(f, &testFloat, sizeof(testFloat)))
		err(-1, NULL);
	float *poppedFloat = (float *)popFromQueue(f);
	if (!poppedFloat)
		err(-1, NULL);
	printf("%f\n", *poppedFloat); 
	free(poppedFloat);
}

int main(void) {
	FifoQueue *f = mkQueue();
	if (!f)
		err(-1, NULL);
	testInt(f);
	testFloat(f);
	testFloat(f);
	testInt(f);
	destroyQueue(f);
	return 0;
}
