CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g         # debug

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

I = -I include -I lib/include  # places which should be included into search
                               #   path for #include preprocessor macro during
                               #   compilation

COMPILE = $(CC) $(FLAGS) $(I) -c  # compilation to intermediary .o files

INCLUDE = include
SOURCE = src
BINARY = bin
BUILD = build
TEST = test
LIBRARY = lib

THIS=04hw
ZIP=hdamron-04hw.zip

tests: test_tracked test_quad_rotor

test : tests
	./$(BINARY)/test_tracked
	./$(BINARY)/test_quad_rotor

test_tracked : $(BUILD)/test_tracked.o $(BUILD)/tracked.o \
               $(BUILD)/mobile_robot.o $(BUILD)/my_utils.o \
               $(BUILD)/my_utils.o \
               $(LIBRARY)/$(BUILD)/point.o $(LIBRARY)/$(BUILD)/vector.o \
               $(LIBRARY)/$(BUILD)/util.o
	$(LINK) $(BINARY)/$@ $^

test_quad_rotor : $(BUILD)/test_quad_rotor.o $(BUILD)/quad_rotor.o \
               $(BUILD)/mobile_robot.o \
               $(BUILD)/my_utils.o \
               $(LIBRARY)/$(BUILD)/point.o $(LIBRARY)/$(BUILD)/vector.o \
               $(LIBRARY)/$(BUILD)/util.o
	$(LINK) $(BINARY)/$@ $^

library :
	make -C $(LIBRARY) library

clean_library:
	make -C $(LIBRARY) clean

$(BUILD)/test_tracked.o : $(TEST)/test_tracked.cc \
                          $(BUILD)/tracked.o $(BUILD)/mobile_robot.o
	$(COMPILE) $< -o $@

$(BUILD)/test_quad_rotor.o : $(TEST)/test_quad_rotor.cc \
                          $(BUILD)/quad_rotor.o $(BUILD)/mobile_robot.o
	$(COMPILE) $< -o $@

$(BUILD)/tracked.o : $(SOURCE)/tracked.cc $(INCLUDE)/tracked.h
	$(COMPILE) $< -o $@

$(BUILD)/quad_rotor.o : $(SOURCE)/quad_rotor.cc $(INCLUDE)/quad_rotor.h
	$(COMPILE) $< -o $@

$(BUILD)/mobile_robot.o : $(SOURCE)/mobile_robot.cc $(INCLUDE)/mobile_robot.h
	$(COMPILE) $< -o $@

$(BUILD)/my_utils.o : $(SOURCE)/my_utils.cc $(INCLUDE)/my_utils.h
	$(COMPILE) $< -o $@

clean:
	@rm -f $(BUILD)/* $(BINARY)/*

compress: clean clean_library
	cd ..; zip -r $(THIS)/$(ZIP) $(THIS)

lint:
	cpplint $(SOURCE)/* $(INCLUDE)/* $(TEST)/*
