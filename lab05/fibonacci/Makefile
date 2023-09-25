#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: 
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#               : make mem - gera arquivos de registro de acesso
#               : make prof - faz medidas de tempo de desempenho
#               : make gprof - ilustra uso do gprof para depuração
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
# LIBS = -lm
LIBS = -lstdc++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/fatorial.o $(OBJ)/fibonacci.o $(OBJ)/time_count.o $(OBJ)/memlog.o
HDRS = $(INC)/fatorial.hpp $(INC)/fibonacci.hpp $(INC)/time_count.hpp $(INC)/memlog.h
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN)/main

all: run

run:  $(EXE)
	$(EXE) -t 5
	$(EXE) -b 5

gprof: $(EXE)
	$(EXE) -t 20
	gprof $(EXE) gmon.out > gprof_report_fatorial.txt

	$(EXE) -b 20
	gprof $(EXE) gmon.out > gprof_report_fibonacci.txt

exp:  $(EXE)
	$(EXE) -t 20
	$(EXE) -b 20

mem: $(EXE)
	$(EXE) -s -p /tmp/fatoriallog.out -l -x 4 -y 5
	$(EXE) -m -p /tmp/fibonaccilog.out -l -x 5 -y 5
	$(EXE) -t -p /tmp/transplog.out -l -x 5 -y 4
	$(EXE) -c /tmp/out.txt -p /tmp/transplog.out -l -x 5 -y 4

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/fatorial.o: $(HDRS) $(SRC)/fatorial.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fatorial.o $(SRC)/fatorial.cpp 

$(OBJ)/fibonacci.o: $(HDRS) $(SRC)/fibonacci.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fibonacci.o $(SRC)/fibonacci.cpp 

$(OBJ)/time_count.o: $(HDRS) $(SRC)/time_count.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/time_count.o $(SRC)/time_count.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out