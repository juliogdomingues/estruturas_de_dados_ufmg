#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2021-10-18 - arquivo criado
#		: 2021-10-21 - estrutura de diretórios
#               : 2021-11-15 - Versao 1.1 memlog
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#               : make mem - gera arquivos de registro de acesso
#               : make prof - faz medidas de tempo de desempenho
#               : make gprof - ilustra uso do gprof para depuração
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lstdc++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/unionFind.o
HDRS = $(INC)/unionFind.hpp $(INC)/heap.hpp
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/pa8.out

all: $(EXE)

test: $(EXE)
	$(EXE) -d < test.txt
	
$(BIN)/pa8.out: $(OBJS)
	$(CC) -pg -o $(BIN)/pa8.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/heap.o $(SRC)/heap.cpp 

$(OBJ)/unionFind.o: $(HDRS) $(SRC)/unionFind.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/unionFind.o $(SRC)/unionFind.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out