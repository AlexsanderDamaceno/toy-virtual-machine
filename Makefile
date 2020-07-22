
SRC      = *.c
INCLU    = *.h
COMPILER = gcc

all: $(SRC) $(INCLU) 
	 $(COMPILER) -o vm $(SRC) $(INCLU)

rm: 
	rm *.o
