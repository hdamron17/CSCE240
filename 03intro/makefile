# Modified by Hunter Damron - 2018

CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g         # allow debugging

CAL = $(CC) $(FLAGS) -o  # compile, assemble, link
CA = $(CC) $(FLAGS) -c  # compile, assemble, do not link

01app : 01arrays.o
	$(CAL) $@ $^
01arrays.o : 01arrays.cc
	$(CA) $^

02app : 02dyna_arrays.o
	$(CAL) $@ $^
02dyna_arrays.o : 02dyna_arrays.cc
	$(CA) $^

03app : 03multi_arrays.o
	$(CAL) $@ $^
03multi_arrays.o : 03multi_arrays.cc
	$(CA) $^

04app : 04undef_ind.o
	$(CAL) $@ $^
04undef_ind.o : 04undef_ind.cc
	$(CA) $^

05app : 05func.o
	$(CAL) $@ $^
05func.o : 05func.cc
	$(CA) $^

all : 01app 02app 03app 04app 05app
	@echo All apps made

clean:
	rm 01arrays.o 01app 02dyna_arrays.o 02app 03multi_arrays.o \
      03app 04undef_ind.o 04app 05func.o 05app
