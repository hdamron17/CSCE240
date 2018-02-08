# Hunter Damron - 2018
# Compiles complex number library and unittests

USER=hdamron
COMP_DIR=$(USER)/hw/02
FILE=complex

CC=g++
FLAGS=-std=c++11 -Wall


$(FILE).o: $(FILE).cc
	$(CC) $(FLAGS) -o $@ -c $^

test_$(FILE): test_$(FILE).cc $(FILE).o
	$(CC) $(FLAGS) -o $@ $^

compress: clean
	mkdir -p $(COMP_DIR)
	cp $(FILE).h $(FILE).cc $(COMP_DIR)
	zip $(USER)
	rmdir $(USER)

clean:
	rm -f $(FILE).o test_$(FILE)
