# Version 1.1

PROGRAM_NAME := cp_naumov_andrei
INCLUDE := include C:\SFML-2.5.1\include
LIBS_PATH := C:\SFML-2.5.1\lib
LIBS := sfml-graphics sfml-window sfml-system sfml-audio

SOURCE := src
CC := g++
CFLAGS :=-c -std=c++14 -Wall -Wextra -Werror -Wno-missing-field-initializers -Wold-style-cast
OBJECTS := $(notdir $(patsubst %.cpp, %.o, $(wildcard $(addsuffix /*.cpp, $(SOURCE)))))

.PHONY: all, clean

all: $(PROGRAM_NAME)
	
$(PROGRAM_NAME): $(OBJECTS)
	mkdir -p bin
	$(CC) $(addprefix obj/, $(OBJECTS)) -o $(addprefix bin/, $(PROGRAM_NAME)) $(addprefix -L, $(LIBS_PATH)) $(addprefix -l, $(LIBS))

%.o: $(addprefix $(SOURCE)/, %.cpp)
	mkdir -p obj
	$(CC) $< $(CFLAGS) $(addprefix -I, $(INCLUDE)) -o $(addprefix obj/, $@)

clean :
	rm -rv obj
	rm -rv bin

include $(wildcard $(addsuffix /*.d, $(SOURCE)))
