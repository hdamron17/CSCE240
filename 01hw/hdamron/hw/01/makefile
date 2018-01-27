# Created by Hunter Damron - Copyright 2018

# Use g++ for C++ compiler
CC=g++

# Use C++ 11 standard
FLAGS=-std=c++11

# Use all warnings
FLAGS+=-Wall

# Username to use for zip archive
UNAME=hdamron

# Executable name
EXE=01hw

# Creates executable 01hw
$(EXE): main.o
	$(CC) $(FLAGS) -o $@ $^

# Compiles but does not link main.o
main.o: main.cc
	$(CC) $(FLAGS) -c $^

compress:
	zip $(UNAME) main.cc makefile

clean:
	@rm -f $(EXE) main.o $(UNAME).zip
