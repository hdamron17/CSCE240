CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings
FLAGS += -g         # debugging

DS = / # directory separator for *nix

INCLUDE = include
SOURCE = src
BINARY = bin
BUILD = build
TEST = test
LIBRARY = lib
LIBBUILD = $(LIBRARY)/$(BUILD)

THIS=05hw
ZIP=hdamron-05hw.zip

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

I = -I $(INCLUDE) -I $(LIBRARY)/$(INCLUDE)  #  Paths which should be
                                                #  included into search path for
                                                #  #include preprocessor macro
                                                #  during compilation

test_mobile_robot : $(BUILD)/test_mobile_robot.o \
                    $(BUILD)/quad_rotor_translation.o \
                    $(BUILD)/tracked_translation.o \
                    $(BUILD)/mobile_robot.o
	$(LINK) $(BINARY)/$@ $^ $(LIBRARY)/$(BUILD)/point.o \
      $(LIBRARY)/$(BUILD)/vector.o $(LIBRARY)/$(BUILD)/util.o

library :
	make -C $(LIBRARY) library

clean_library:
	make -C $(LIBRARY) clean

COMPILE = $(CC) $(FLAGS) $(I) -c  # compilation to intermediary .o files

$(BUILD)/test_mobile_robot.o : $(TEST)/test_mobile_robot.cc \
                               $(BUILD)/quad_rotor_translation.o \
                               $(BUILD)/tracked_translation.o \
                               $(BUILD)/mobile_robot.o
	$(COMPILE) $< -o $@

$(BUILD)/mobile_robot.o : $(SOURCE)/mobile_robot.cc $(INCLUDE)/mobile_robot.h \
                          $(BUILD)/quad_rotor_translation.o \
                          $(BUILD)/tracked_translation.o
	$(COMPILE) $< -o $@

$(BUILD)/tracked_translation.o : $(SOURCE)/tracked_translation.cc \
                                 $(INCLUDE)/tracked_translation.h \
                                 $(INCLUDE)/translation.h
	$(COMPILE) $< -o $@

$(BUILD)/quad_rotor_translation.o : $(SOURCE)/quad_rotor_translation.cc \
                                    $(INCLUDE)/quad_rotor_translation.h \
                                    $(INCLUDE)/translation.h
	$(COMPILE) $< -o $@

compress: clean
	cd ..; zip -r $(THIS)/$(ZIP) $(THIS)

clean: clean_library
	@rm -f $(BUILD)/* $(LIBRARY)/$(BUILD)/* $(ZIP)
