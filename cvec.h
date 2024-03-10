#ifndef CVEC_H
#define CVEC_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void** items;
    int capacity;
    int size;
} cvec;

cvec* new_cvec();
cvec* cvec_from(int count, ...);

int cvec_resize(cvec* vec, int capacity);
int cvec_push(cvec* vec, void* item);
int cvec_pop(cvec* vec);

void* cvec_aoit(cvec* vec);
void* cvec_at(cvec* vec, int index);
void cvec_debug(cvec* vec);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CVEC_H
