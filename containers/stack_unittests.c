#include <stdio.h>
#include "stack.h"

int main(){
	struct Stack * stack = Stack_init(sizeof(size_t));
	for ( size_t i = 9; i < 10; i++){
		Stack_push_back(stack, &i);
		//printf("%s\n", "ypdeli");
	}
	Stack_finalize(&stack);
}
