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
OBJS = $(OBJ)/main.o $(OBJ)/set.o
HDRS = $(INC)/Set.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/pa10.out

all: $(EXE)

test: $(EXE)
	
$(BIN)/pa10.out: $(OBJS)
	$(CC) -o $(BIN)/pa10.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/set.o: $(HDRS) $(SRC)/set.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/set.o $(SRC)/set.cpp

clean:
	rm -f $(EXE) $(OBJS)