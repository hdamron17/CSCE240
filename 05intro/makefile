CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o

COMPILE = $(CC) $(FLAGS) -c

01app : 01main.o
	$(LINK) $@ $^

01main.o : 01main.cc 01main.h
	$(COMPILE) $<

02app : 02main.o dollar.o
	$(LINK) $@ $^

02main.o : 02main.cc 02main.h
	$(COMPILE) $<

dollar.o : dollar.cc dollar.h
	$(COMPILE) $<

dollar2.o : dollar2.cc dollar2.h
	$(COMPILE) $<
    
clean:
	@rm 0[1-5]app *.o 
