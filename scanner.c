#include <stdio.h>
#include <string.h>
#include "common.h"
#include "scanner.h"


void initScanner(char *source){
  scanner.start   = source; 
  scanner.current = source; 
  scanner.line    = 1; 
}


char peek(){
	return *scanner.current; 
}


int isAtEnd(){
  return *scanner.current == '\0';
}


char peekNext(){
	if(isAtEnd()) return '\0';
	return *scanner.current;
}



void skipWhitespace(){
	for(;;){
		char c = peek();
		switch(c){
			case ' ':
			case '\r':
			case '\t':
			 advance();
			 break; 

			case '\n':
			   scanner.line++;
			   advance();
			   break; 
            case '/':
               if(peekNext() == '/'){
               	while(peek() !=  '\n' && !isAtEnd()) 
               		  advance();

               }else{
               	 return; 
               }

	         default: 
	            return; 		 
		}
	}
}


char advance(){
	scanner.current++; 
	return scanner.current[-1];
}

int match(char expected){
	if(isAtEnd()) return false; 
	if(*scanner.current != expected) return false; 
	scanner.current++; 

}


Token  scanToken(){
	skipWhitespace();
	scanner.start = scanner.current;

	if(isAtEnd()) return makeToken(TOKEN_EOF);
     
    char c = advance();

    switch (c) {
      case '(': return makeToken(TOKEN_LEFT_PAREN);
      case ')': return makeToken(TOKEN_RIGHT_PAREN);
      case '{': return makeToken(TOKEN_LEFT_BRACE);
      case '}': return makeToken(TOKEN_RIGHT_BRACE);
      case ';': return makeToken(TOKEN_SEMICOLON);
      case ',': return makeToken(TOKEN_COMMA);
      case '.': return makeToken(TOKEN_DOT);
      case '-': return makeToken(TOKEN_MINUS);
      case '+': return makeToken(TOKEN_PLUS);
      case '/': return makeToken(TOKEN_SLASH);
      case '*': return makeToken(TOKEN_STAR);
      case '!':
       return makeToken(match('=') ? TOKEN_BANG_EQUAL : TOKEN_BANG);
      case '=':
       return makeToken(match('=') ? TOKEN_EQUAL_EQUAL : TOKEN_EQUAL);
      case '<':
        return makeToken(match('=') ? TOKEN_LESS_EQUAL : TOKEN_LESS);
      case '>':
          return makeToken(match('=') ?   TOKEN_GREATER_EQUAL : TOKEN_GREATER);
    }
 

	return errorToken("Unexpected character.");

}


Token makeToken(TokenType Type){
	 Token token; 
	 token.type   = Type; 
	 token.start  = scanner.start; 
	 token.length = (int)(scanner.current - scanner.start);
	 token.line   = scanner.line; 
     
      

	 return token;   
}

Token errorToken(char *message){
	 Token token; 
	 token.type   = TOKEN_ERROR;
	 token.length = (int)strlen(message);
	 token.line   = scanner.line; 
	 return token;

}