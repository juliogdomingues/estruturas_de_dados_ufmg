CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/indice.o
#HDRS = $(INC)/Set.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/pa11.out

all: $(EXE)

test: $(EXE)
	
$(BIN)/pa11.out: $(OBJS)
	$(CC) -o $(BIN)/pa11.out $(OBJS) $(LIBS)

$(OBJ)/indice.o: $(HDRS) $(SRC)/indice.c
	$(CC) $(CFLAGS) -o $(OBJ)/indice.o $(SRC)/indice.c

clean:
	rm -f $(EXE) $(OBJS)