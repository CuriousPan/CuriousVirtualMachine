#ifndef INSTR_FUN_C
#define INSTR_FUN_C

#include <stdio.h>
#include <stdbool.h>

#include "InstructionFunctions.h"

InstructionFunction instructionFunctions[NUM_INSTRUCTIONS] = {
    PUSH_function,
    POP_function,
    ADD_function,
    SUB_function,
    PRT_LST_function,
    HLT_function,
    CMP_LT_function,
    CMP_GT_function,
    CMP_LET_function,
    CMP_GET_function,
    CMP_EQ_function,
    CMP_NEQ_function,
    LD_VAL_function,
    STR_VAL_function,
    JMP_BY_IF_ZERO_function,
    JMP_BY_IF_ONE_function,
    JMP_BY_function,
    DBG_PRT_function
};

void PUSH_function(Instruction *instruction)
{
    printf("PUSH\n");
    stack[SP++] = instruction->o1;
    ++IP;
}

void POP_function(Instruction *instruction)
{
    printf("POP\n");
    --SP;
    ++IP;
}

void ADD_function(Instruction *instruction)
{
    printf("ADD\n");
    int rightNumber = stack[--SP];
    int leftNumber = stack[--SP];
    stack[SP++] = leftNumber + rightNumber;
    ++IP;
}

void SUB_function(Instruction *instruction)
{
    printf("SUB\n");
    int rightNumber = stack[--SP];
    int leftNumber = stack[--SP];
    stack[SP++] = leftNumber - rightNumber;
    ++IP;
}

void PRT_LST_function(Instruction *instruction)
{
    printf("PRT_LST\n");
    if (SP >= 1) {
        printf("%d\n", stack[SP - 1]);
    } else {
        printf("No elements on the stack\n");
    }
    ++IP;
}

void HLT_function(Instruction *instruction)
{
    printf("HLT\n");
    RUN = false;
}

void CMP_LT_function(Instruction *instruction)
{
    printf("CMP_LT\n");
    int rightNumber = stack[--SP];
    int leftNumber = stack[--SP];
    stack[SP++] = leftNumber < rightNumber;
    ++IP;
}

void CMP_GT_function(Instruction *instruction)
{
    printf("CMP_GT\n");
    int rightNumber = stack[--SP];
    int leftNumber = stack[--SP];
    stack[SP++] = leftNumber > rightNumber;
    ++IP;
}

void CMP_LET_function(Instruction *instruction)
{
    printf("CMP_LET\n");
    int rightNumber = stack[--SP];
    int leftNumber = stack[--SP];
    stack[SP++] = leftNumber <= rightNumber;
    ++IP;
}

void CMP_GET_function(Instruction *instruction)
{
    printf("CMP_GET\n");
    int rightNumber = stack[--SP];
    int leftNumber = stack[--SP];
    stack[SP++] = leftNumber >= rightNumber;
    ++IP;
}

void CMP_EQ_function(Instruction *instruction)
{
    printf("CMP_EQ\n");
    int rightNumber = stack[--SP];
    int leftNumber = stack[--SP];
    stack[SP++] = leftNumber == rightNumber;
    ++IP;
}

void CMP_NEQ_function(Instruction *instruction)
{
    printf("CMP_NEQ\n");
    int rightNumber = stack[--SP];
    int leftNumber = stack[--SP];
    stack[SP++] = leftNumber != rightNumber;
    ++IP;
}

void LD_VAL_function(Instruction *instruction)
{
    printf("LD_VAL\n");
    stack[SP++] = stack[instruction->o1];
    ++IP;
}

void STR_VAL_function(Instruction *instruction) //TODO think of going out of bounds etc.
{
    printf("STR_VAL\n");
    stack[instruction->o1] = stack[--SP];
    ++IP;
}

void JMP_BY_IF_ZERO_function(Instruction *instruction)
{
    printf("JMP_BY_IF_ZERO\n");
    if (stack[--SP] == 0) {
        IP += instruction->o1;
    } else {
        IP += 1;
    }
}

void JMP_BY_IF_ONE_function(Instruction *instruction)
{
    printf("JMP_BY_IF_ZERO\n");
    if (stack[--SP] == 1) {
        IP += instruction->o1;
    } else {
        IP += 1;
    }
}

void JMP_BY_function(Instruction *instruction)
{
    printf("JMP_BY\n");
    IP += instruction->o1;
}

void DBG_PRT_function(Instruction *instruction)
{
    printf("DBG_PRT\n");
    printf("Debug message\n");
    ++IP;
}

#endif /* INSTR_FUN_C */
