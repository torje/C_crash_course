#include <stdlib.h>
#include <string.h>
#include "array.h"

struct Array{
    struct Buffer * buffer;
    size_t data_size;
    size_t used;
};

struct Array *Array_create( size_t data_size){
    struct Array * array = calloc( sizeof( struct Array ), 1);
    array -> data_size = data_size;
    array -> used = 0;
    array -> buffer = Buffer_create();
    return array;
}

void Array_finalize(struct Array ** array){
	Buffer_clear((*array)->buffer);
	free((*array)->buffer);
	(*array)->data_size = 0;
	(*array)->used = 0;
	free( *array);
	*array=NULL;
}

void Array_alloc_from_zero( struct Array * array, size_t size){
    Buffer_alloc_from_zero(array->buffer, size*array->data_size);
}

int Array_resize(struct Array * array, size_t size){
    return Buffer_resize( array->buffer, size*array->data_size);
}


void *Array_at(struct Array *array, size_t pos){
    return Buffer_at( array->buffer, pos*array->data_size);
}

size_t Array_size(struct Array *array){
    return array ->used;
}

size_t Array_capacity(struct Array *array){
    return Buffer_size( array->buffer)/array->data_size ;
}

void * Array_push_back(struct Array * array, void * data ){
    struct Buffer *buffer =  array -> buffer; 
    if (  array -> used >= Array_capacity( array )   ){
	size_t cursize = Buffer_size(buffer);
	size_t newsize = 0 ;
	if (  cursize== 0 ){
	    newsize = 64*array -> data_size;
	}else{
	    newsize = cursize *2;
	}
	Buffer_resize(buffer, newsize);
	void *pos = Buffer_at(buffer,  array->used * array->data_size );
    	memmove( pos, data, array->data_size  ); 
	array->used ++;
	return pos;
    }else{
	void *pos = Buffer_at(buffer,  array->used * array->data_size );
    	memmove( pos, data, array->data_size  ); 
	array->used ++;
	return pos;
    }
}
