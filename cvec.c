#include "cvec.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

cvec* new_cvec() {
	cvec* temp = (cvec*)malloc(sizeof(cvec));
	temp->capacity = 0;
	temp->size = 0;
	temp->items = (void**)malloc(temp->capacity);
	return temp;
}

cvec* cvec_from(int count, ...) {
    cvec* temp = new_cvec();
    va_list list;
    va_start(list, count);

    for (int i = 0; i < count; i++)
        cvec_push(temp, va_arg(list, void*));

    va_end(list);
    return temp;
}

void cvec_debug(cvec* vec) {
    printf("[");
    for (int i = 0; i < vec->size - 1; i++)
        printf("%d ", cvec_aoit(vec));
    printf("%d]\n", cvec_aoit(vec));
}

int cvec_resize(cvec* vec, int capacity) {
	if (!vec) return false;
	if (vec->items == NULL) vec->items = (void**)malloc(capacity);
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
	if (!vec || !vec->items || vec->size < 1) return false;

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
    if (vec->size < 1) return NULL;
	static int count = 0;
	if (count >= vec->size)
		count = 0;

	return vec->items[count++];
}
