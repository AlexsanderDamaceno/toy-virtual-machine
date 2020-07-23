#include "common.h"
#include "memory.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"
#include <stdio.h>



int main(int argc ,  char  *argv[]){
	Chunk chunk; 
	init_chunk(&chunk);
	init_Vm();
  int constant = add_constant(&chunk , 1.2);
   	
   write_chunk(&chunk , OP_CONSTANT , 11);
   write_chunk(&chunk , constant  , 11);
   write_chunk(&chunk , OP_NEGATE , 11);
   write_chunk(&chunk , OP_RETURN , 123);

   // write_chunk(&chunk , constant);
    interpret(&chunk);
    //free_Vm();
	  //free_chunk(&chunk);
    return 0; 
}




