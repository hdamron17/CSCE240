CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o

COMPILE = $(CC) $(FLAGS) -c

01app : 01main.o
	$(LINK) $@ $^

02app : 01main.o dollar2.o
	$(LINK) $@ $^

03app : 01main.o dollar3.o
	$(LINK) $@ $^

01main.o : 01main.cc 01main.h
	$(COMPILE) $<

dollar.o : dollar.cc dollar.h
	$(COMPILE) $<

dollar2.o : dollar2.cc dollar2.h
	$(COMPILE) $<

dollar3.o : dollar3.cc dollar3.h
	$(COMPILE) $<

dollars: dollar.o dollar2.o dollar3.o
    
clean:
	@rm 0[1-5]app *.o 
