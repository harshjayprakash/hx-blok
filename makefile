CC = gcc
CC_FLAGS = -g -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast \
-Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef \
-Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter \
-Wfloat-equal -pedantic -ansi

LIBRARIES = -lgdi32

SOURCE_DIRECTORY = src
BUILD_DIRECTORY = build
OUTPUT_DIRECTORY = bin

SOURCE_FILES = src/main.c
OBJECT_FILES = build/main.o

EXECUTABLE = blok

all: $(OUTPUT_DIRECTORY)/$(EXECUTABLE)

$(OUTPUT_DIRECTORY)/$(EXECUTABLE): $(OBJECT_FILES)
	@echo Linking ...
	$(CC) $(CC_FLAGS) -o $@ $^

$(BUILD_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.c
	@echo Compiling ... $^
	$(CC) $(CC_FLAGS) -c $^ -o $@