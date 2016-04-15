#include <stdio.h>
#include "array.h"

int main(){
	struct Array * array = Array_create( sizeof(int));
    for( int i = 0 ; i < 8 ; i++){
	int a = i;
	Array_push_back( array, &i);
    }
    printf("size: %lu -- ", Array_size(array));
    printf("capacity: %lu\n", Array_capacity(array));
    for ( int i = 0 ; i < Array_size(array) ; i++){
	    //printf("%d ", *(int*)Array_at(array,i));
	    //printf("%p \n", Array_at(array,i));
    }
    printf("size: %lu -- ", Array_size(array));
    printf("capacity: %lu\n", Array_capacity(array));
    Array_finalize ( &array);
    
    return 0;
}
