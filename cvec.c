#include "cvec.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

cvec* new_vec() {
	cvec* temp = (cvec*)malloc(sizeof(cvec));
	return temp;
}

int cvec_resize(cvec* vec, int capacity) {
	if (!vec) return false;
	if (!vec->items) vec->items = (void**)malloc(capacity);
	else {
		vec->items = (void**)realloc(vec->items, (vec->size + 1) * capacity);
		vec->capacity = capacity;
	}
	return true;
}

int cvec_push(cvec* vec, void *item) {
	if (!vec || !item) return false;

	cvec_resize(vec, sizeof(item));
	vec->items[vec->size] = item;
	vec->size++;

	return true;
}

int cvec_free(cvec* vec) {
	if (!vec || !vec->items) return false;

	free(vec->items);
	free(vec);

	vec->items = NULL;
	vec = NULL;

	return true;
}

int cvec_pop(cvec* vec) {
	if (vec->size < 1) return false;
	vec->size--;
	vec->items = (void**)realloc(vec->items, (vec->size) * vec->capacity);
	return true;
}

void* cvec_at(cvec* vec, int index) {
	return vec->items[index];
}

void* cvec_aoit(cvec* vec) {
	static int count = 0;
	if (count >= vec->size)
		count = 0;

	return vec->items[count++];
}