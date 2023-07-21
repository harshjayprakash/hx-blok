CC = clang
CC_FLAGS = -g -Wall -Werror -std=c17
CC_LINK_FLAGS = -mwindows -mconsole

LIBRARIES = -lkernel32 -luser32 -lshell32 -lgdi32

SOURCE_DIRECTORY = src
BUILD_DIRECTORY = build
OUTPUT_DIRECTORY = bin

OBJECT_FILES = $(BUILD_DIRECTORY)/main.o \
	$(BUILD_DIRECTORY)/program.o \
	$(BUILD_DIRECTORY)/window.o \
	$(BUILD_DIRECTORY)/square.o \
	$(BUILD_DIRECTORY)/store.o \
	$(BUILD_DIRECTORY)/theme.o \
	$(BUILD_DIRECTORY)/casts.o \
	$(BUILD_DIRECTORY)/debug.o \
	$(BUILD_DIRECTORY)/mark.o \
	$(BUILD_DIRECTORY)/vector.o

EXECUTABLE = blok.exe

all: $(OUTPUT_DIRECTORY)/$(EXECUTABLE)

$(OUTPUT_DIRECTORY)/$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CC_FLAGS) -o $@ $^ $(LIBRARIES) $(CC_LINK_FLAGS)

$(BUILD_DIRECTORY)/main.o: src/main.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/program.o: src/core/program.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/debug.o: src/core/debug.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/window.o: src/presentation/window.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/square.o: src/model/square.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/mark.o: src/model/mark.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/vector.o: src/model/vector.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/store.o: src/logic/store.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/theme.o: src/logic/theme.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIRECTORY)/casts.o: src/logic/casts.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

.PHONY: clean
clean:
	del /f /q $(BUILD_DIRECTORY)\*
	del /f /q $(OUTPUT_DIRECTORY)\*