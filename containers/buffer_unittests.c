#include <stdio.h>
#include "buffer.h"

int main(){
    struct Buffer * buffer = Buffer_create();
    Buffer_alloc_from_zero(buffer, 1024);
    Buffer_resize(buffer, 8196);
    Buffer_resize(buffer, 4196);
    for ( int i = 0 ; i < Buffer_size(buffer) ; i++){
	char * val = Buffer_at( buffer, i);
	*val = 'l';
    }
    for ( int i = 0 ; i < Buffer_size(buffer) ; i++){
	char * val = Buffer_at( buffer, i);
	printf("%c", *val);
    }
    Buffer_clear(buffer);
    Buffer_clear(buffer);
}
