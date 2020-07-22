#ifndef  DEBUG_H
#define  DEBUG_H

#include "chunk.h"

void disassembleChunk(Chunk *chunk ,  char *name);
int  disassembleInstruction(Chunk *chunk , int offset);
int  simpleinstruction(char *s , int offset);
void printValue(Value value);
#endif