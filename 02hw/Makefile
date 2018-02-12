# Hunter Damron - 2018
# Compiles complex number library and unittests

USER=hdamron
COMP_DIR=hw/02
FILE=complex

CC=g++
FLAGS=-std=c++11 -Wall


$(FILE).o: $(FILE).cc $(FILE).h
	$(CC) $(FLAGS) -o $@ -c $(FILE).cc

test_$(FILE): test_$(FILE).cc $(FILE).o
	$(CC) $(FLAGS) -o $@ $^

compress:
	mkdir -p $(USER)/$(COMP_DIR)
	cp $(FILE).h $(FILE).cc $(USER)/$(COMP_DIR)
	zip -r $(USER).zip $(USER)
	rm -rf $(USER)

clean:
	rm -f $(FILE).o test_$(FILE)
