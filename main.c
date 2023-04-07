#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "InstructionFunctions.h"

/*
 * Registers:
 * IP - instruction pointer - holds address of the current instruction.
 * SP - stack pointer - points to the top of the stack. Not the top-most element. SP element is alwasy empty for the machine, though it's may not be the truth in reality.
 * RUN - running - identifies if the program is running right now.
 */

void run();

//use this carefully
void printStack(int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
    printf("Stack pointer %d\n", SP);
}

Instruction program[] = {
    { PSH_I, 10   },
    { PSH_I, 10   },
    { LD_VAL_I, 1 },
    { PSH_I, 1    },

    { CMP_LET_I,  },
    { JMP_BY_IF_ONE_I, 5 }, //if <= 1

    { PSH_I, 2       },
    { SUB_I          },
    { STR_VAL_I, 1   },
    { JMP_BY_I, -7   },

    { HLT_I       }
};

int main()
{
    IP = &program[0];
    SP = 0;
    RUN = true;

    run(IP);

    printStack(15);

    return 0;
}

void run() {
    while (RUN == true) {
        Instruction *instruction = IP;
        instructionFunctions[instruction->opcode](instruction);
    }
}
