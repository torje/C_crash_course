#include <stddef.h>

struct Buffer;

struct Buffer * Buffer_create(void);
void Buffer_clear(struct Buffer * buffer);
void Buffer_alloc_from_zero(struct Buffer * buffer, size_t size);
int Buffer_resize(struct Buffer * buffer, size_t size);
void *Buffer_at(struct Buffer *buffer, size_t pos);
size_t Buffer_size(struct Buffer *buffer);
