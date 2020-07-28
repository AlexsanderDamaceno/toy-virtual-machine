#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "scanner.h"
#include "compiler.h"


typedef struct {
  Token current;
  Token previous;
  int hadError;
  int panicMode;
} Parser;

Parser parser;


void errorAt(Token * token , char *message ){
	 parser.panicMode = true; 
	 fprintf(stderr, "[line %d] Error  ",  token->line);

	 if(token->type == TOKEN_EOF){
	 	fprintf(stderr, "at end");

	 }else if(token->type  == TOKEN_ERROR){

	 }else{
	 	fprintf(stderr , "at '%.*s' " , token->length  , token->start);

	 }

 
   fprintf(stderr, "%s\n", message);
   parser.hadError = true; 

}


void error(char *message){
	errorAt(&parser.previous , message);
}

void errorAtcurrent(char *message){
	if(parser.panicMode) return; 
	errorAt(&parser.current , message);
}





static void advance(){
	parser.previous = parser.current; 

	for(;;){
		parser.current = scanToken();
		if(parser.current.type != TOKEN_ERROR) break; 


		errorAtcurrent(parser.current.start); 
	}
}









static void consume(TokenType type , char *message){
	if(parser.current.type == type){
		advance();
		return; 
	}

	errorAtcurrent(message);
}


int expression(){
	
}



 int compile(char *source , Chunk *chunk){
	 initScanner(source);
	 parser.hadError = false; 
	 parser.panicMode = false;
	 advance();

	 expression();


	 consume(TOKEN_EOF , "expression end expression.");
	 return !parser.hadError;

    

     
}