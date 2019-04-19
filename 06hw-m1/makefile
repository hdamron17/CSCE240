CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

INCLUDE = include
SOURCE = src
BINARY = bin
BUILD = build
TEST = test
LIBRARY = lib

THIS=06hw-m1
ZIP=hdamron-$(THIS).zip

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

I = -I $(INCLUDE) -I $(LIBRARY)/$(INCLUDE)  #  Paths which should be included
                                            #  into search path for #include
                                            #  preprocessor macro.
COMPILE = $(CC) $(FLAGS) $(I) -c  # compilation to intermediary .o files

test_weather_station : $(BUILD)/test_weather_station.o \
                       $(BUILD)/weather_station.o \
                       $(BUILD)/observable.o
	$(LINK) $(BINARY)/$@ $^ $(LIBRARY)/$(BUILD)/sensor_net.o

library :
	make -C $(LIBRARY) library

clean_library:
	make -C $(LIBRARY) clean

$(BUILD)/test_weather_station.o : $(TEST)/test_weather_station.cc \
                                  $(BUILD)/weather_station.o
	$(COMPILE) $< -o $@

$(BUILD)/weather_station.o : $(SOURCE)/weather_station.cc \
                             $(INCLUDE)/weather_station.h
	$(COMPILE) $< -o $@

$(BUILD)/observable.o : $(SOURCE)/observable.cc $(INCLUDE)/observable.h \
                        $(INCLUDE)/observer.h
	$(COMPILE) $< -o $@

compress: clean
	cd ..; zip -r $(THIS)/$(ZIP) $(THIS)

clean: clean_library
	rm -f $(BINARY)/* $(BUILD)/* $(ZIP)
