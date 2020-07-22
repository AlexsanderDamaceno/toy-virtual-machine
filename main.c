#include "common.h"
#include "memory.h"
#include "chunk.h"
#include "debug.h"


int main(int argc ,  char  *argv[]){
	Chunk chunk; 
	init_chunk(&chunk);
	write_chunk(&chunk , OP_RETURN);
	disassembleChunk(&chunk , "test ");
 
    int constant = add_constant(&chunk , 1.2);
    write_chunk(&chunk , OP_CONSTANT);
    write_chunk(&chunk , constant);


	free_chunk(&chunk);
    return 0; 
}

