#include <string.h>
#include <stdlib.h>
#include "fifo.h"

FifoStack mkStack() {
	return (FifoStack){
		NULL,
		0
	};
}

void *addToStack(FifoStack *stack, void *object, size_t objectSize) {
	if (stack->objects == NULL) {
		void **objects = malloc(sizeof (void *));
		if (!objects) 
			return NULL;
		stack->objects = objects;
		stack->size++;
	} else {
		void **objects = realloc(stack->objects, sizeof (void *) * ++stack->size);
		if (!objects)
			return NULL;
	}
	void *objectBuffer = malloc(objectSize);
	if (!objectBuffer)
		return NULL;
	memcpy(objectBuffer, object, objectSize);
	stack->objects[stack->size - 1] = objectBuffer;
	return objectBuffer;
}

void *popFromStack(FifoStack *stack) {
	if (stack->size == 0)
		return NULL;
	else {
		/* perform a realloc, but truncate from the front */
		void *poppedObject = stack->objects[0]; /* save the element we're about to pop, we need to return this later */
		size_t newSize = sizeof (void *) * (--stack->size); /* calculate the new decreased size of the stack */
		void **newObjects = malloc(newSize);
		if (!newObjects)
			return NULL;
		memcpy(newObjects, &stack->objects[1], newSize);
		free(stack->objects);
		stack->objects = newObjects;
		return poppedObject;
	}
}

void destroyStack(FifoStack *stack) {
	for (long i = 0; i < stack->size; i++)
		free(stack->objects[i]);
	free(stack->objects);
	stack->objects = NULL;
	stack->size = 0;
}
