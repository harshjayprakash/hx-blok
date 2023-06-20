CC = gcc
CC_FLAGS = -g -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast \
-Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef \
-Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter \
-Wfloat-equal -pedantic -ansi

LIBRARIES = -lgdi32

SOURCE_DIRECTORY = src
BUILD_DIRECTORY = build
OUTPUT_DIRECTORY = bin

OBJECT_FILES = $(BUILD_DIRECTORY)/main.o $(BUILD_DIRECTORY)//program.o

EXECUTABLE = blok

all: $(OUTPUT_DIRECTORY)/$(EXECUTABLE)

$(OUTPUT_DIRECTORY)/$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CC_FLAGS) -o $@ $^

$(BUILD_DIRECTORY)/main.o: src/main.c
	$(CC) $(CC_FLAGS) -c $^ -o $(BUILD_DIRECTORY)/$@

$(BUILD_DIRECTORY)/program.o: src/core/program.c
	$(CC) $(CC_FLAGS) -c $^ -o $(BUILD_DIRECTORY)/$@