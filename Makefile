CC = clang
CC_FLAGS = -g -Wall -Werror -std=c17 -DUNICODE -DSTRICT
CC_LINK_FLAGS = -mwindows -mconsole

LIBRARIES = -lkernel32 -luser32 -lshell32 -lgdi32

SOURCE_DIR = source
BUILD_DIR = build
OUTPUT_DIR = bin

OBJECT_FILES = $(BUILD_DIR)/main.o

EXECUTABLE = blok.exe

all: $(OUTPUT_DIR)/$(EXECUTABLE)

$(OUTPUT_DIR)/$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CC_FLAGS) -o $@ $^ $(LIBRARIES) $(CC_LINK_FLAGS)

$(BUILD_DIR)/main.o: $(SOURCE_DIR)/main.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

.PHONY: init
init:
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	if not exist $(OUTPUT_DIR) mkdir $(OUTPUT_DIR)

.PHONY: clean
clean:
	del /f /q $(BUILD_DIR)\*
	del /f /q $(OUTPUT_DIR)\*
