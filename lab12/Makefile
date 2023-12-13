#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa evalenum
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#           : make test - compila e roda os testes
#   		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/avl.o
HDRS = $(INC)/avl.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/pa.out

all: $(EXE)

test: $(EXE)
	
$(BIN)/pa.out: $(OBJS)
	$(CC) -o $(BIN)/pa.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/avl.o: $(HDRS) $(SRC)/avl.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/avl.o $(SRC)/avl.cpp

clean:
	rm -f $(EXE) $(OBJS)