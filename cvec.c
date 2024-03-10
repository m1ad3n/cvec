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

void* cvec_front(cvec* vec) {
	if (!vec || vec->size < 1) return NULL;
	return vec->items[vec->size - 1];
}

void* cvec_back(cvec* vec) {
	if (!vec || vec->size < 1) return NULL;
	return vec->items[0];
}

int cvec_remove(cvec* vec, unsigned int index) {
    if (!vec || vec->size <= index || vec->size < 1) return false;
    for (int i = index; i < vec->size - 1; i++)
        vec->items[i] = vec->items[i + 1];

    vec->size--;
    vec->items = (void**)realloc(vec->items, vec->size * sizeof(void*));
    return true;
}

int cvec_clean(cvec* vec) {
    if (!vec || vec->size < 1) return false;
    vec->items = (void**)realloc(vec->items, 0);
    vec->size = 0;
    return true;
}

void cvec_debug(cvec* vec, const char* format) {
    if (vec->size < 1) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < vec->size - 1; i++) {
        printf(format, cvec_iter(vec));
        printf(" ");
    }

    printf(format, cvec_iter(vec));
    printf("]\n");
}

int cvec_resize(cvec* vec, unsigned int capacity) {
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
    if (!vec || vec->size <= index) return NULL;
	return vec->items[index];
}

void* cvec_iter(cvec* vec) {
    if (vec->size < 1) return NULL;
	static int count = 0;
	if (count >= vec->size)
		count = 0;

	return vec->items[count++];
}
