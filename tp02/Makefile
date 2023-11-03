CC = gcc
LIBS = -lstdc++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/avexp.o $(OBJ)/satisf.o $(OBJ)/pilha.o $(OBJ)/arvore.o
HDRS = $(INC)/pilha.hpp $(INC)/arvore.hpp $(INC)/avexp.hpp $(INC)/satisf.hpp
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN)/tp1.out

all: run

tests: test_av test_satisf

run:  $(EXE)

test_av:  $(EXE)
	$(EXE) -a "0 | 1" 01
	$(EXE) -a "0 | 1 & 2" 010
	$(EXE) -a "~ ( 0 | 1 ) & 2" 101
	$(EXE) -a "0 | 1 & ~ 2 | ~ ( 0 & ( 1 & 2 | 3 ) | 1 ) & 2" 0110
	$(EXE) -a "0 | 1 & ~ 2 | ~ ( 0 & ( 1 & 2 | 3 ) | 1 ) & 2" 1000

test_satisf:  $(EXE)
	$(EXE) -s "0 | 1 & 2" 0e0	
	$(EXE) -s "0 | 1 & 2" e00
	$(EXE) -s "0 | 1 & 2" e11
	$(EXE) -s "0 | 1" ea
	$(EXE) -s "0 | ~ ~ 1" ea
	$(EXE) -s "( ( 0 & 1 ) & ( 2 & 3 ) & ( 4 & 5 ) & ( 6 & 7 ) & ( 8 & 9 ) )" e1e1e1e1e1

$(BIN)/tp1.out: $(OBJS)
	$(CC) -pg -o $(BIN)/tp1.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp 

$(OBJ)/avexp.o: $(HDRS) $(SRC)/avexp.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/avexp.o $(SRC)/avexp.cpp 

$(OBJ)/satisf.o: $(HDRS) $(SRC)/satisf.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/satisf.o $(SRC)/satisf.cpp 

$(OBJ)/arvore.o: $(HDRS) $(SRC)/arvore.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/arvore.o $(SRC)/arvore.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out