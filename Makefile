# Benjamin Bloomfield, bloomfib, November 20, 2024 

# makefile to handle compilation of all .c files; default
clean: clean.c checkParameters.c checkParameters.h cleaningOperations.c cleaningOperations.h
	gcc -o clean clean.c checkParameters.c cleaningOperations.c

