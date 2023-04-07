#ifndef REGISTERS_H
#define REGISTERS_H

#include "Instructions.h"

#define IP  instruction_pointer
#define SP  stack_pointer
#define RUN running

#define STACK_SIZE 256 

extern Instruction *instruction_pointer;

extern int stack_pointer;

extern int running;

extern int stack[STACK_SIZE];

#endif /* REGISTERS_H */
