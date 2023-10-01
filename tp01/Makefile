
CC = gcc
# LIBS = -lm
LIBS = -lstdc++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/avexp.o $(OBJ)/satisf.o
HDRS = $(INC)/avexp.hpp $(INC)/satisf.hpp
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN)/main

all: run

run:  $(EXE)
	$(EXE) -a "teste" 12
	$(EXE) -s "teste" 10

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/avexp.o: $(HDRS) $(SRC)/avexp.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/avexp.o $(SRC)/avexp.cpp 

$(OBJ)/satisf.o: $(HDRS) $(SRC)/satisf.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/satisf.o $(SRC)/satisf.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out