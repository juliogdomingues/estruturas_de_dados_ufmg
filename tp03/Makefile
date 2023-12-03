CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/segtree.o
HDRS = $(INC)/segtree.hpp
CFLAGS = -Wall -pg -c -std=c++11 -I$(INC)

EXE = $(BIN)/tp3.out

all: run

run:  $(EXE)

test: $(EXE)
	# $(EXE) < test0.txt # esperado: 
	$(EXE) < test1.txt # esperado: 1 0 | 0 0
	$(EXE) < test2.txt # esperado: 1 0 | 0 0
	$(EXE) < test3.txt # esperado: 7 5 | 5 7 | 5464 2989
	$(EXE) < test4.txt # esperado: 1 1
	$(EXE) < genTest1.txt
	$(EXE) < genTest2.txt
	$(EXE) < genTest3.txt
	
$(BIN)/tp3.out: $(OBJS)
	$(CC) -pg -o $(BIN)/tp3.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/segtree.o: $(HDRS) $(SRC)/segtree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/segtree.o $(SRC)/segtree.cpp 

# $(OBJ)/grafo.o: $(HDRS) $(SRC)/grafo.cpp
# 	$(CC) $(CFLAGS) -o $(OBJ)/grafo.o $(SRC)/grafo.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out