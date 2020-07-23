#ifndef VM_H
#define VM_H


#include "chunk.h"
#include "value.h"
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT()(vm.chunk->constants.values[READ_BYTE()])

#define STACK_MAX 256

#define BINARY_OP(op) \
  do { \
  	double b =  pop(); \
  	double a =  pop(); \
  	push(a op b); \
  }while(false)

typedef struct {
	Chunk *chunk;
	uint8_t *ip;
    Value stack[STACK_MAX];
    Value *stackTop;
}Vm;


typedef enum{
  INTERPRET_OK ,
  INTERPRET_COMPILE_ERROR  , 
  INTERPRET_RUNTIME_ERROR
}InterpretResult;

int  init_Vm();
void free_Vm();
void resetStack();
void push(Value value);
Value pop();
InterpretResult interpret(Chunk *chunk);
InterpretResult run();

#endif