#include <stddef.h>
#include <stdint.h>
int floormod (int dividend, int divisor);
int ceildiv(int dividend, int divisor);
int floordiv(int dividend, int divisor);

int ceildiv(int dividend, int divisor){
    if (dividend > 0 ){
	return (dividend -1)/divisor+1;
    }else{
	return (dividend )/divisor;	
    }
}

int floordiv(int dividend, int divisor){
    if (dividend > 0 ){
	return (dividend )/divisor;
    }else{
	return (dividend +1-divisor)/divisor;	
    }
}

int floormod (int dividend, int divisor){
    return dividend - divisor * floordiv(dividend, divisor);
}
