SRC = main.c InstructionFunctions.c Registers.c

GCC = gcc

all:
	${GCC} ${SRC} -Wall -Wpedantic -O3 -o main

debug:
	${GCC} -g ${SRC} -o main
