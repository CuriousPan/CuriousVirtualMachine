#ifndef REGISTERS_C
#define REGISTERS_C

#include "Registers.h"

Instruction *instruction_pointer = 0;

int stack_pointer = 0;

int running = 0;

int stack[STACK_SIZE];

#endif /* REGISTERS_C */
