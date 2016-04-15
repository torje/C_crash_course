#include <stdio.h>

int main(){
	fprintf(NULL, "%s\n", "Hello, SIGSEGV! ");
	return 0;
}
