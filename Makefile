CC = clang
CC_FLAGS = -g -Wall -Werror -std=c17 -DUNICODE
CC_LINK_FLAGS = -mwindows -mconsole

LIBRARIES = -lkernel32 -luser32 -lshell32 -lgdi32

SOURCE_DIR = src
BUILD_DIR = build
OUTPUT_DIR = bin

OBJECT_FILES = $(BUILD_DIR)/main.o \
	$(BUILD_DIR)/core.program.o \
	$(BUILD_DIR)/core.result.o \
	$(BUILD_DIR)/core.log.o

EXECUTABLE = neon-blok.exe

build: $(OUTPUT_DIR)/$(EXECUTABLE)

$(OUTPUT_DIR)/$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CC_FLAGS) -o $@ $^ $(LIBRARIES) $(CC_LINK_FLAGS)

$(BUILD_DIR)/main.o: $(SOURCE_DIR)/main.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/core.log.o: $(SOURCE_DIR)/core/log.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/core.program.o: $(SOURCE_DIR)/core/program.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/core.result.o: $(SOURCE_DIR)/core/result.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

.PHONY: init
init:
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	if not exist $(OUTPUT_DIR) mkdir $(OUTPUT_DIR)

.PHONY: clean
clean:
	del /f /q $(BUILD_DIR)\*
	del /f /q $(OUTPUT_DIR)\*
