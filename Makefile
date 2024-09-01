CC = clang
CC_FLAGS = -g -Wall -Werror -std=c17 -DUNICODE
CC_LINK_FLAGS = -mwindows -mconsole

LIBRARIES = -lkernel32 -luser32 -lshell32 -lgdi32

SOURCE_DIR = src
BUILD_DIR = build
OUTPUT_DIR = bin

OBJECT_FILES = $(BUILD_DIR)/main.o \
	$(BUILD_DIR)/core.args.o \
	$(BUILD_DIR)/core.log.o \
	$(BUILD_DIR)/core.program.o \
	$(BUILD_DIR)/core.result.o \
	$(BUILD_DIR)/model.object.square.o \
	$(BUILD_DIR)/model.utility.position.o \
	$(BUILD_DIR)/model.utility.size.o \
	$(BUILD_DIR)/model.utility.vector.o \
	$(BUILD_DIR)/presentation.components.canvas.o \
	$(BUILD_DIR)/presentation.components.panel.o \
	$(BUILD_DIR)/presentation.events.handler.o \
	$(BUILD_DIR)/presentation.graphics.drawing.o \
	$(BUILD_DIR)/presentation.graphics.theme.o \
	$(BUILD_DIR)/presentation.objects.block.o \
	$(BUILD_DIR)/presentation.objects.obstructables.o \
	$(BUILD_DIR)/presentation.window.o

EXECUTABLE = neon-blok.exe

build: $(OUTPUT_DIR)/$(EXECUTABLE)

$(OUTPUT_DIR)/$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CC_FLAGS) -o $@ $^ $(LIBRARIES) $(CC_LINK_FLAGS)

$(BUILD_DIR)/main.o: $(SOURCE_DIR)/main.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/core.args.o: $(SOURCE_DIR)/core/args.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/core.log.o: $(SOURCE_DIR)/core/log.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/core.program.o: $(SOURCE_DIR)/core/program.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/core.result.o: $(SOURCE_DIR)/core/result.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/model.object.square.o: $(SOURCE_DIR)/model/object/square.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/model.utility.position.o: $(SOURCE_DIR)/model/utility/position.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/model.utility.size.o: $(SOURCE_DIR)/model/utility/size.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/model.utility.vector.o: $(SOURCE_DIR)/model/utility/vector.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.components.canvas.o: $(SOURCE_DIR)/presentation/components/canvas.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.components.panel.o: $(SOURCE_DIR)/presentation/components/panel.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.events.handler.o: $(SOURCE_DIR)/presentation/events/handler.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.graphics.drawing.o: $(SOURCE_DIR)/presentation/graphics/drawing.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.graphics.theme.o: $(SOURCE_DIR)/presentation/graphics/theme.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.objects.block.o: $(SOURCE_DIR)/presentation/objects/block.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.objects.obstructables.o: $(SOURCE_DIR)/presentation/objects/obstructables.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.window.o: $(SOURCE_DIR)/presentation/window.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

.PHONY: init
init:
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	if not exist $(OUTPUT_DIR) mkdir $(OUTPUT_DIR)

.PHONY: clean
clean:
	del /f /q $(BUILD_DIR)\*
	del /f /q $(OUTPUT_DIR)\*
