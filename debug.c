#include <stdio.h>

#include "debug.h"

int simpleInstruction(char *name , int offset){
	printf("%s\n", name);
	return offset + 1;
}


int constantInstruction(char *s , Chunk * chunk  , int offset){
	uint8_t constant = chunk->code[offset+1];
	printf("%s %4d" , s , constant);
	printValue(chunk->constants.values[constant]);
	printf("\n");
	return offset + 2;
}

void printValue(Value value){
	printf("%g" , value);

}
void disassembleChunk(Chunk *chunk , char *name){
	 printf("%s\n" , name); 
     int offset = 0;
	 for(int i = 0; i <  chunk->count; i++)
	 	offset = disassembleInstruction(chunk , offset);

	 	
}

int disassembleInstruction(Chunk *chunk , int offset){
	printf("offset:%04d " , offset);
	switch(chunk->code[offset]){
		case OP_RETURN:
		  return simpleInstruction("OP_RETURN" , offset);
        case OP_CONSTANT:
          return constantInstruction("OP_CONSTANT" , chunk
          	, offset);
     
		default:
		  printf("Unkown opcode %d\n" , chunk->code[offset]);
		  return offset + 1;

	}
}

