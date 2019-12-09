/************************************************************************/
/* File Name : lc4_disassembler.c 										*/
/* Purpose   : This file implements the reverse assembler 				*/
/*             for LC4 assembly.  It will be called by main()			*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"
#include "lc4_disassembler.h"

int reverse_assemble (row_of_memory* memory) {
    row_of_memory* code_node ;
    short unsigned int opcode = 1 ;
    code_node = search_opcode(memory ,opcode) ;
	return 0 ;
}
