#include "buffer.h"

struct Stack;

struct Stack * Stack_init( size_t membersize);

void * Stack_push_back(struct Stack * stack, void * data );
void * Stack_pop_back(struct Stack * stack, void * data );
void Stack_clear(struct Stack * stack);
size_t Stack_size(struct Stack *stack);

void Stack_alloc_from_zero(struct Stack * stack, size_t size);
int Stack_resize(struct Stack * stack, size_t size);
//void *Stack_at(struct Stack *stack, size_t pos);
//size_t Stack_capacity(struct Stack *stack);

