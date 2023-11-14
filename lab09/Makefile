#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa evalenum
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#           : make test - compila e roda os testes
#   		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/evalenum.o
# HDRS = $(INC)/sort.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/pa9.out

all: $(EXE)

test: $(EXE)
	$(EXE) -z 98 -s 16 -a s
	$(EXE) -z 98 -s 16 -a i
	$(EXE) -z 98 -s 16 -a q
	$(EXE) -z 98 -s 16 -a q3
	$(EXE) -z 98 -s 16 -a qi
	$(EXE) -z 98 -s 16 -a q3i
	$(EXE) -z 98 -s 16 -a h
	$(EXE) -z 98 -s 16 -a rs
	$(EXE) -z 473 -s 2 -a s
	$(EXE) -z 473 -s 2 -a i
	$(EXE) -z 473 -s 2 -a q
	$(EXE) -z 473 -s 2 -a q3
	$(EXE) -z 473 -s 2 -a qi
	$(EXE) -z 473 -s 2 -a q3i
	$(EXE) -z 473 -s 2 -a h
	$(EXE) -z 473 -s 2 -a rs
	$(EXE) -z 8721 -s 44 -a s
	$(EXE) -z 8721 -s 44 -a i
	$(EXE) -z 8721 -s 44 -a q
	$(EXE) -z 8721 -s 44 -a q3
	$(EXE) -z 8721 -s 44 -a qi
	$(EXE) -z 8721 -s 44 -a q3i
	$(EXE) -z 8721 -s 44 -a h
	$(EXE) -z 8721 -s 44 -a rs
	$(EXE) -z 34275 -s 43 -a s
	$(EXE) -z 34275 -s 43 -a i
	$(EXE) -z 34275 -s 43 -a q
	$(EXE) -z 34275 -s 43 -a q3
	$(EXE) -z 34275 -s 43 -a qi
	$(EXE) -z 34275 -s 43 -a q3i
	$(EXE) -z 34275 -s 43 -a h
	$(EXE) -z 34275 -s 43 -a rs
	$(EXE) -z 73735 -s 13 -a s
	$(EXE) -z 73735 -s 13 -a i
	$(EXE) -z 73735 -s 13 -a q
	$(EXE) -z 73735 -s 13 -a q3
	$(EXE) -z 73735 -s 13 -a qi
	$(EXE) -z 73735 -s 13 -a q3i
	$(EXE) -z 73735 -s 13 -a h
	$(EXE) -z 73735 -s 13 -a rs
	
$(BIN)/pa9.out: $(OBJS)
	$(CC) -o $(BIN)/pa9.out $(OBJS) $(LIBS)

$(OBJ)/evalenum.o: $(HDRS) $(SRC)/evalenum.c
	$(CC) $(CFLAGS) -o $(OBJ)/evalenum.o $(SRC)/evalenum.c

clean:
	rm -f $(EXE) $(OBJS)