#include "buffer.h"

struct Array;

struct Array * Array_create(size_t data_size);
void Array_finalize(struct Array ** array);
void Array_alloc_from_zero(struct Array * array, size_t size);
int Array_resize(struct Array * array, size_t size);
void *Array_at(struct Array *array, size_t pos);
size_t Array_size(struct Array *array);
size_t Array_capacity(struct Array *array);
void * Array_push_back(struct Array * array, void * data );
