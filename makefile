CC = gcc
CC_FLAGS = -g -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast \
-Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef \
-Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter \
-Wfloat-equal -pedantic -ansi -std=c99

LIBRARIES = -lgdi32

SOURCE_DIRECTORY = src
BUILD_DIRECTORY = build
OUTPUT_DIRECTORY = bin

OBJECT_FILES = $(BUILD_DIRECTORY)/main.o $(BUILD_DIRECTORY)/program.o \
	$(BUILD_DIRECTORY)/window.o $(BUILD_DIRECTORY)/square.o \
	$(BUILD_DIRECTORY)/store.o

EXECUTABLE = blok

all: $(OUTPUT_DIRECTORY)/$(EXECUTABLE)

$(OUTPUT_DIRECTORY)/$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CC_FLAGS) -o $@ $^ $(LIBRARIES)

$(BUILD_DIRECTORY)/main.o: src/main.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/program.o: src/core/program.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/square.o: src/model/square.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/window.o: src/presentation/window.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/store.o: src/service/store.c
	$(CC) $(CC_FLAGS) -c $^ -o $@
