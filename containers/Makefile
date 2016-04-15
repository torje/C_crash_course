
array_unittests.o:array_unittests.c array.h
buffer_unittests.o:buffer_unittests.c  buffer.h
array.o: array.c array.h
buffer.o: buffer.c buffer.h
array_units: array_unittests.o array.o buffer.o
	$(CC) -o $@ $^
buffer_units: buffer_unittests.o buffer.o
	$(CC) -o $@ $^
stack.o: stack.c stack.h
stack_unittests.o: stack_unittests.c stack.h
stack_units: stack_unittests.o stack.o buffer.o
	$(CC) -o $@ $^
