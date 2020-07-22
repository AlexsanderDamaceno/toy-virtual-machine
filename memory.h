#ifndef MEMORY_H
#define MEMORY_H

#include  "common.h"


void * reallocate(void *pointer ,  size_t oldsize , size_t newsize);


#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : capacity * 2)

#define GROW_ARRAY(type , pointer , oldcount  , newCount) \
        (type *)reallocate(pointer , sizeof(type)*oldcount  , sizeof(type)*newCount)

#define FREE_ARRAY(type , pointer , oldcount) \
        reallocate(pointer , sizeof(type) *(oldcount) , 0)


#endif