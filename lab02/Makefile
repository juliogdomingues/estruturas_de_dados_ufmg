
CC = gcc
# LIBS = -lm
LIBS = -lstdc++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/fatorial.o $(OBJ)/fibonacci.o $(OBJ)/time_count.o 
HDRS = $(INC)/fatorial.hpp $(INC)/fibonacci.hpp $(INC)/time_count.hpp
CFLAGS = -Wall -pg -c -I$(INC)

EXE = $(BIN)/main

all: run

run:  $(EXE)
	$(EXE) -t -n 5
	$(EXE) -b -n 5

gprof: $(EXE)
	$(EXE) -t -n 20
	gprof $(EXE) gmon.out > gprof_report_fatorial.txt

	$(EXE) -b -n 20
	gprof $(EXE) gmon.out > gprof_report_fibonacci.txt

exp:  $(EXE)
	$(EXE) -t -n 20
	$(EXE) -b -n 20

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