# Benjamin Bloomfield, bloomfib, November 17, 2024 

# makefile to handle compilation of all .c files; default
convert: clean.c checkParameters.c checkParameters.h cleaningOperations.c cleaningOperations.h
	gcc -o clean clean.c checkParameters.c cleaningOperations.c

