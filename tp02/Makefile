CC = gcc
LIBS = -lstdc++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/sort.o $(OBJ)/grafo.o
HDRS = $(INC)/sort.hpp $(INC)/vetor.hpp $(INC)/item.hpp $(INC)/grafo.hpp
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN)/tp2.out

all: run

run:  $(EXE)

test: $(EXE)
	$(EXE) < test0.txt # esperado: 
	$(EXE) < test1.txt # esperado: 1 0 4 5 1 3 2
	$(EXE) < test2.txt # esperado: 0
	$(EXE) < test3.txt # esperado: 1 0 2 1 4 3
	$(EXE) < test4.txt # esperado: 0
	
$(BIN)/tp2.out: $(OBJS)
	$(CC) -pg -o $(BIN)/tp2.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/sort.o: $(HDRS) $(SRC)/sort.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/sort.o $(SRC)/sort.cpp 

$(OBJ)/grafo.o: $(HDRS) $(SRC)/grafo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/grafo.o $(SRC)/grafo.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out