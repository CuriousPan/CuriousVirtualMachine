#ifndef INSTR_FUN_H
#define INSTR_FUN_H

#include "Registers.h"

typedef void (*InstructionFunction)(Instruction *);

extern InstructionFunction instructionFunctions[NUM_INSTRUCTIONS];

void PUSH_function(Instruction *instruction);

void POP_function(Instruction *instruction);

void ADD_function(Instruction *instruction);

void SUB_function(Instruction *instruction);

void PRT_LST_function(Instruction *instruction);

void HLT_function(Instruction *instruction);

void CMP_LT_function(Instruction *instruction);

void CMP_GT_function(Instruction *instruction);

void CMP_LET_function(Instruction *instruction);

void CMP_GET_function(Instruction *instruction);

void CMP_EQ_function(Instruction *instruction);

void CMP_NEQ_function(Instruction *instruction);

void LD_VAL_function(Instruction *instruction);

void STR_VAL_function(Instruction *instruction);

void JMP_BY_IF_ZERO_function(Instruction *instruction);

void JMP_BY_IF_ONE_function(Instruction *instruction);

void JMP_BY_function(Instruction *instruction);

void DBG_PRT_function(Instruction *instruction);

#endif /* INSTR_FUN_H */
