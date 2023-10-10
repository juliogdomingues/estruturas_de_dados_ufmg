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
OBJS = $(OBJ)/main.o $(OBJ)/graph.o $(OBJ)/listaadj.o 
HDRS = $(INC)/graph.hpp $(INC)/listaadj.hpp
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/pa6.out

all: $(EXE)

test: $(EXE)
	$(EXE) -d < test.txt
	$(EXE) -n < test.txt
	$(EXE) -k < test.txt
	
$(BIN)/pa6.out: $(OBJS)
	$(CC) -pg -o $(BIN)/pa6.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp 

$(OBJ)/listaadj.o: $(HDRS) $(SRC)/listaadj.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/listaadj.o $(SRC)/listaadj.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
