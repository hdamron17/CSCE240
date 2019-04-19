CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o
COMPILE = $(CC) $(FLAGS) -c

INCLUDE = include
SOURCE = src
BINARY = bin
BUILD = build
TEST = test
LIBRARY = lib

THIS=03hw
ZIP=hdamron-03hw.zip

test_tracked : $(BUILD)/test_tracked.o $(BUILD)/tracked.o \
               $(BUILD)/mobile_robot.o \
               $(LIBRARY)/$(BUILD)/point.o $(LIBRARY)/$(BUILD)/vector.o \
               $(LIBRARY)/$(BUILD)/util.o
	make -s library
	$(LINK) $(BINARY)/$@ $^

test_mobile_robot : $(BUILD)/test_mobile_robot.o $(BUILD)/mobile_robot.o
	make -s library
	$(LINK) $(BINARY)/$@ $^

library :
	make -C $(LIBRARY) library

clean_library :
	make -C $(LIBRARY) clean

$(BUILD)/test_tracked.o : $(TEST)/test_tracked.cc \
                          $(BUILD)/tracked.o $(BUILD)/mobile_robot.o
	$(COMPILE) $< -o $@

$(BUILD)/tracked.o : $(SOURCE)/tracked.cc $(INCLUDE)/tracked.h
	$(COMPILE) $< -o $@

$(BUILD)/test_mobile_robot.o : $(TEST)/test_mobile_robot.cc \
                               $(BUILD)/mobile_robot.o
	$(COMPILE) $< -o $@

$(BUILD)/mobile_robot.o : $(SOURCE)/mobile_robot.cc $(INCLUDE)/mobile_robot.h
	$(COMPILE) $< -o $@

clean:
	@rm -f bin/* build/* .DS_Store $(ZIP)

compress: clean clean_library
	cd ..; zip -r $(THIS)/$(ZIP) $(THIS)
