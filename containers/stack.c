#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
struct Stack{
	struct Buffer *data;
	size_t used;
	size_t membersize;
};

size_t Stack_bytes_used( struct Stack * stack){
	return stack->used*stack->membersize;
}
size_t Stack_bytes_cap( struct Stack * stack){
	return Buffer_size(stack->data);
}

struct Stack * Stack_init( size_t membersize){
	struct Stack * stack = calloc(1, sizeof(struct Stack));
	stack ->data = Buffer_create();
	Buffer_alloc_from_zero(stack->data,membersize);
	stack->used = 0;
	stack->membersize = membersize;
	return stack;
}

void * Stack_push_back_simple(struct Stack * stack, void * data ){
	memmove( Buffer_at( stack->data, stack->used), data, stack->membersize);
	stack->used++;
	return Buffer_at( stack->data, stack->used-1);
}

void * Stack_push_back(struct Stack * stack, void * data ){
	if ( Stack_bytes_used(stack) +stack->membersize > Stack_bytes_cap(stack)){
		return Stack_push_back_simple(stack, data);
	}else{
		size_t newsize = stack->used*2 ? stack->used*2:1 ;
		Stack_resize(stack, newsize);
		return Stack_push_back_simple(stack, data);
	}
}
int Stack_resize(struct Stack * stack, size_t size){
	if ( size < stack->used ){
		Buffer_resize( stack->data, size*stack->membersize);
		stack->used = size;
		return size;
	}else{
		Buffer_resize(stack->data, size*stack->membersize);
		return size;
			
	}
}

void * Stack_pop_back(struct Stack * array, void * data );
void Stack_finalize(struct Stack ** stack){
	Buffer_clear((*stack) -> data);
	(*stack) -> data = NULL;
	(*stack) -> used = 0;
	(*stack) -> membersize = 0;
	free(*stack);
	*stack = NULL;
	       
}
size_t Stack_size(struct Stack *array);

//void Stack_alloc_from_zero(struct Stack * array, size_t size);
//void *Stack_at(struct Array *array, size_t pos);
//size_t Stack_capacity(struct Array *array);

