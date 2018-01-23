# Modified by Hunter Damron - 2018

# Make a compiler variable
CC = g++

# Make a compiler flags variable for C++ 11 standard
FLAGS = -std=c++11
# Add the "all warnings" flag to variable
FLAGS += -Wall

# 04app rule
#	Dependencies: 04args.o
#   Compiler: CC
#   Language version: FLAGS
#   Output file name: left side reference, $@
#   Input file(s): right side reference, $^
04app: 04args.o
	$(CC) $(FLAGS) -o $@ $^

# 04args.o rule (does not link)
#   Dependencies: 04args.cc
#   Compiler: CC
#   Language version: FLAGS
#   Input file name: right side reference, $^
04args.o: 04args.cc
	$(CC) $(FLAGS) -c $^

# 05app rule
#	Dependencies: 05text_file.o
#   Compiler: CC
#   Language version: FLAGS
#   Output file: left side reference, $@
#   Input file(s): right side reference, $^
05app : 05text_file.o
	$(CC) $(FLAGS) -o $@ $^

# 05text_file.o rule (does not link)
#   Dependencies: 05text_file.cc
#   Compiler: CC
#   Language version: FLAGS
#   Input file: right side reference, $^
05text_file.o : 05text_file.cc
	$(CC) $(FLAGS) -c $^

# Create a rule to clean up object and executable files.
# Dependencies: none
#   Command: @rm (to make rm silent)
#   Files: 04app, 04args.o, 05app, 05app.o
clean:
	@rm 04app 04args.o 05app 05text_file.o
