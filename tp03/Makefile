CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/matriz.o $(OBJ)/segtree.o
HDRS = $(INC)/matriz.hpp $(INC)/segtree.hpp
CFLAGS = -Wall -pg -c -std=c++11 -I$(INC)

EXE = $(BIN)/tp3.out

all: run

run:  $(EXE)

tests: test gprof valgrind

test: $(EXE)
	$(EXE) < ./tests/test1.txt # esperado: 1 0 | 0 0
	$(EXE) < ./tests/test2.txt # esperado: 1 0 | 0 0
	$(EXE) < ./tests/test3.txt # esperado: 7 5 | 5 7 | 5464 2989
	$(EXE) < ./tests/test4.txt # esperado: 1 1
	# $(EXE) < ./tests/genTest1.txt
	# $(EXE) < ./tests/genTest2.txt
	# $(EXE) < ./tests/genTest3.txt
	# $(EXE) < ./tests/testProp1.txt
	# $(EXE) < ./tests/testProp2.txt
	# $(EXE) < ./tests/testProp3.txt
	$(EXE) < ./tests/genTestOverflow.txt # esperado: 67294586 75620058

gprof:
	gprof $(EXE) gmon.out > ./tests/gprof_testOverflow.txt

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all -s $(EXE) < ./tests/test1.txt

valgrind_adv:
	valgrind --tool=cachegrind $(EXE) < ./tests/test1.txt
	# cg_annotate cachegrind.out.XXXX
	valgrind --tool=callgrind $(EXE) < ./tests/test1.txt
    # callgrind_annotate callgrind.out.XXXX

$(BIN)/tp3.out: $(OBJS)
	$(CC) -pg -o $(BIN)/tp3.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/matriz.o: $(HDRS) $(SRC)/matriz.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matriz.o $(SRC)/matriz.cpp 

$(OBJ)/segtree.o: $(HDRS) $(SRC)/segtree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/segtree.o $(SRC)/segtree.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out