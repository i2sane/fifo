#pragma once

typedef struct {
	void **objects;
	long size;
} FifoStack;

FifoStack mkStack();
void *addToStack(FifoStack *, void *, size_t);
void *popFromStack(FifoStack *); 
void destroyStack(FifoStack *);
