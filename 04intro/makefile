CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

01app: 01order.o
	$(CC) $(FLAGS) -o $@ $^

01order.o: 01order.cc
	$(CC) $(FLAGS) -c $^

02app : 02separate.o
	$(CC) $(FLAGS) -o $@ $^

02separate.o : 02separate.cc 02separate.h
	$(CC) $(FLAGS) -c $<  # notice the new placeholder 

03app : 03call_by.o
	$(CC) $(FLAGS) -o $@ $^

03call_by.o : 03call_by.cc 03call_by.h
	$(CC) $(FLAGS) -c $<

04app : 04overload.o
	$(CC) $(FLAGS) -o $@ $^

04overload.o : 04overload.cc 04overload.h
	$(CC) $(FLAGS) -c $<

05app : 05default.o
	$(CC) $(FLAGS) -o $@ $^

05default.o : 05default.cc 05default.h
	$(CC) $(FLAGS) -c $<

all : 02app 03app 04app 05app 01app

clean:
	rm 0[1-5]app 0[1-5]*.o 
