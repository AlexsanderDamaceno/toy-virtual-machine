#include <stdlib.h>
#include "chunk.h"
#include "memory.h"
void init_chunk(Chunk *chunk){
	chunk->count    = 0; 
	chunk->capacity = 0; 
	chunk->code     = (uint8_t *)NULL; 
	chunk->lines     = NULL;
	initValueArray(&chunk->constants);

}

void write_chunk(Chunk *chunk , uint8_t byte , int line){
	if(chunk->capacity  < chunk->count + 1){
		int oldcapacity = chunk->capacity;
		chunk->capacity = GROW_CAPACITY(oldcapacity); 
		chunk->code     = GROW_ARRAY(uint8_t , chunk->code , oldcapacity , chunk->capacity);
        chunk->lines    = GROW_ARRAY(int , chunk->lines , oldcapacity , chunk->capacity);
	}
    

	chunk->code[chunk->count]  = byte;
	chunk->lines[chunk->count] = line; 
	chunk->count++; 
}

void free_chunk(Chunk * chunk){
	FREE_ARRAY(uint8_t , chunk->code , chunk->capacity);
	freeValueArray(&chunk->constants);
	init_chunk(chunk);
}

int add_constant(Chunk *chunk , Value value){
	writeValueArray(&chunk->constants , value);
	return chunk->constants.count - 1;
}