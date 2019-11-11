# Version 1.0

PROGRAM_NAME := cp_naumov
INCLUDE := include
SOURCE := src
CC := g++
CFLAGS :=-c -Wall -Wextra -Werror -Wno-missing-field-initializers -Wold-style-cast
OBJECTS := $(notdir $(patsubst %.cpp, %.o, $(wildcard $(addsuffix /*.cpp, $(SOURCE)))))

.PHONY: all, clean

all: $(PROGRAM_NAME)
	
$(PROGRAM_NAME): $(OBJECTS)
	mkdir -p bin
	$(CC) $(addprefix obj/, $(OBJECTS)) -o $(addprefix bin/, $(PROGRAM_NAME))

%.o: $(addprefix $(SOURCE)/, %.cpp)
	mkdir -p obj
	$(CC) $< $(CFLAGS) $(addprefix -I, $(INCLUDE)) -o $(addprefix obj/, $@)

clean :
	rm -rv obj
	rm -rv bin

include $(wildcard $(addsuffix /*.d, $(SOURCE)))
