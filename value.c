#include <stdio.h>
#include "memory.h"
#include "value.h"

void initValueArray(ValueArray *array){
	array->capacity  = 0;
	array->count     = 0;  
	array->values    = NULL; 
    
}

void writeValueArray(ValueArray *array , Value value){

	if(array->capacity < array->capacity + 1){

		int oldcapacity =  array->capacity;
		array->capacity = GROW_CAPACITY(oldcapacity);

		array->values   = GROW_ARRAY(Value , array->values , oldcapacity , array->capacity);
       
	}
    
	array->values[array->count] = value; 
	array->count++;

}

void freeValueArray(ValueArray *array){
	FREE_ARRAY(Value , array->values , array->capacity);
	initValueArray(array);
}