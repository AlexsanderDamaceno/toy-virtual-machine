#include "vm.h"
#include "value.h"
#include "debug.h"
#include "common.h"
#include "compiler.h"
#include <stdio.h>

Vm vm; 

void push(Value value){
	*vm.stackTop = value; 
	 vm.stackTop++;
}

Value pop(){
	vm.stackTop--; 
	return *vm.stackTop;
}


void resetStack(){
	vm.stackTop = vm.stack;
}

int init_Vm(){
   resetStack();
}



void free_Vm(){

}

void compile(char *source){

}

InterpretResult interpret(char  *source){
   compile(source);
   return INTERPRET_OK;
}




InterpretResult run(){
   for(;;){
 
    #ifdef  DEBUG_TRACE_EXECUTION
         printf("   ");
         for(Value *slot = vm.stack; slot < vm.stackTop; slot++){
         	printf("[");
         	printValue(*slot);
         	printf("]");
         }
         printf("\n");
         disassembleInstruction(vm.chunk , (int)(vm.ip - vm.chunk->code));

    #endif

    uint8_t instruction;
    switch(instruction = READ_BYTE()){
      case OP_RETURN : {
        
        printValue(pop());
        printf("\n");
        return INTERPRET_OK;
	
	   }
   
      case  OP_CONSTANT:{
        Value  constant = READ_CONSTANT();
         push(constant);
        printf("\n");
        break; 
       }

      case OP_NEGATE:{
         	 push(-pop());  break;
      } 

       case OP_ADD:    	BINARY_OP(+);  break;
      
       case OP_SUBTRACT: BINARY_OP(-);  break;
      
       case OP_MULTIPLY:
         	  BINARY_OP(*);  break;
       case OP_DIVIDE:
         	  BINARY_OP(/); break;
        


     }
  }
}
    
