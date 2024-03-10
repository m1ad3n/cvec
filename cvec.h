#ifndef CVEC_H
#define CVEC_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void** items;
    unsigned int capacity;
    unsigned int size;
} cvec;

cvec* new_cvec();
cvec* cvec_from(int count, ...);

int cvec_resize(cvec* vec, unsigned int capacity);
int cvec_push(cvec* vec, void* item);
int cvec_pop(cvec* vec);
int cvec_remove(cvec* vec, unsigned int index);
int cvec_clean(cvec* vec);

void* cvec_aoit(cvec* vec);
void* cvec_at(cvec* vec, int index);
void* cvec_front(cvec* vec);
void* cvec_back(cvec* vec);
void cvec_debug(cvec* vec, const char* format);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CVEC_H
