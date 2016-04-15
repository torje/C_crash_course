#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

struct Buffer{
    void * start;
    void * end;
    //size_t size;
};
struct Buffer * Buffer_create(){
    struct Buffer * buffer = calloc(1, sizeof(struct Buffer) );
    return buffer;
}

void Buffer_clear(struct Buffer * buffer){
    free( buffer->start );
    buffer->start = 0x0;
    buffer->end = 0x0;
}

void Buffer_alloc_from_zero(struct Buffer * buffer, size_t size){
	buffer -> start =  calloc(1, size);
	buffer -> end =  buffer -> start + size;
}

int Buffer_resize(struct Buffer * buffer, size_t size){
    void * new = realloc(buffer -> start, size);
    if ( !new ){
	    printf("Buffer_resize():  buffer->start %p , buffer->size %zu \n",buffer->start,size);
	return 1;
    }else{
	//printf("OMG; YES!\n");
	buffer -> start = new;
	buffer -> end  =  buffer->start + size;
	return 0;
    }
}

void *Buffer_at(struct Buffer *buffer, size_t pos){
    void * ret = buffer -> start + pos;
    return ret;
}

size_t Buffer_size(struct Buffer *buffer){
	size_t size = buffer->end - buffer ->start;
    return  size;
}
