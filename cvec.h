#ifndef CVEC_H
#define CVEC_H

typedef struct {
    void** items;
    int capacity;
    int size;
} cvec;

cvec* new_vec();

int cvec_resize(cvec* vec, int capacity);
int cvec_push(cvec* vec, void* item);
int cvec_pop(cvec* vec);

void* cvec_aoit(cvec* vec);
void* cvec_at(cvec* vec, int index);

#endif
