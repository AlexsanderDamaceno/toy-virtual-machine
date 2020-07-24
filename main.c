#include "common.h"
#include "memory.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void repl(){
  char line[1024]; 

  for(;;){
    printf("> ");

    if(!fgets(line , sizeof(line)  , stdin)){
      printf("\n");
      break; 
    }

     interpret(line);
  }


}

char *readFile(char *path){
   FILE *file = fopen(path , "rb");
   fseek(file , 0 , SEEK_END);
   size_t fileSize = ftell(file);
   rewind(file);

   char *buffer = (char *)malloc(fileSize+1);

   if(buffer == NULL){
     printf("Not enough ");
   }

   size_t bytesread = fread(buffer , sizeof(char) , fileSize , file);

   if(bytesread  < fileSize){
     printf("failed to read file \n");
     exit(1);

   }

   buffer[bytesread] = '\0';
   fclose(file);
   return buffer;
}



void RunFile(char *path){
  
   if(path == NULL)
   {
      printf("could not open file %s \n " , path);
   }

   char *source =  readFile(path);
   InterpretResult result = interpret(source);
   free(source);

   if(result == INTERPRET_COMPILE_ERROR) return exit(65);
   if(result == INTERPRET_RUNTIME_ERROR) return exit(70);



}




int main(int argc ,  char  *argv[]){
  	Chunk chunk; 
   	init_chunk(&chunk);
	  init_Vm();
    
    if(argc == 1){
       repl();
     }else if(argc == 2){
      RunFile(argv[1]);
     }else{
       printf("Error use  [lox file] format \n");
       exit(-1);
     }



    free_Vm();
   	free_chunk(&chunk);
    return 0; 
}




