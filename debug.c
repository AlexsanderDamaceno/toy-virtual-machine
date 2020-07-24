#include <stdio.h>

#include "debug.h"

int simpleInstruction(char *name , int offset){
	printf("%s\n", name);
	return offset + 1;
}


int constantInstruction(char *s , Chunk * chunk  , int offset){
	uint8_t constant = chunk->code[offset+1];
	printf("%s %4d " , s , constant);
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
     printf("ddf %d\n" , chunk->count);
	 for(int i = 0; i <  chunk->count && offset < chunk->count ; i++)
	 	offset = disassembleInstruction(chunk , offset);

	 	
}

int disassembleInstruction(Chunk *chunk , int offset){
	
	

	printf("offset:%04d " , offset);
    
	if(offset > 0 && chunk->lines[offset] == chunk->lines[offset-1]){
		printf("  | ");


	}else{
		printf("%4d " , chunk->lines[offset]);
	}

	switch(chunk->code[offset]){
		case OP_RETURN:
	     return simpleInstruction("OP_RETURN" , offset);
		  
        case OP_CONSTANT:
          return constantInstruction("OP_CONSTANT" , chunk
          	, offset);
        case OP_NEGATE:
           return simpleInstruction("OP_NEGATE" , offset); 
        

       case OP_ADD:    simpleInstruction("OP_ADD" , offset);  break;
      
       case OP_SUBTRACT: simpleInstruction("OP_SUBTRACT" , offset); break;
      
       case OP_MULTIPLY:
         	   simpleInstruction("OP_MULTIPLY" , offset);  break;
       case OP_DIVIDE:
         	     simpleInstruction("OP_DIVIDE" , offset);  break;
        

		default:
		  printf("Unkown opcode %d\n" , chunk->code[offset]);
		  return offset + 1;

	}
}

