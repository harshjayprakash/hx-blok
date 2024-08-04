CC = clang
CC_FLAGS = -g -Wall -Werror -std=c17 -DUNICODE -DSTRICT
CC_LINK_FLAGS = -mwindows -mconsole

LIBRARIES = -lkernel32 -luser32 -lshell32 -lgdi32

SOURCE_DIR = source
BUILD_DIR = build
OUTPUT_DIR = bin

OBJECT_FILES = $(BUILD_DIR)/main.o \
	$(BUILD_DIR)/core.program.o \
	$(BUILD_DIR)/core.args.o \
	$(BUILD_DIR)/model.objects.square.o \
	$(BUILD_DIR)/model.objects.vector.o \
	$(BUILD_DIR)/model.utilities.position.o \
	$(BUILD_DIR)/model.utilities.size.o \
	$(BUILD_DIR)/presentation.colour.theme.o \
	$(BUILD_DIR)/presentation.components.canvas.o \
	$(BUILD_DIR)/presentation.components.panel.o \
	$(BUILD_DIR)/presentation.events.handler.o \
	$(BUILD_DIR)/presentation.graphics.renderer.o \
	$(BUILD_DIR)/presentation.window.window.o

EXECUTABLE = blok.exe

all: $(OUTPUT_DIR)/$(EXECUTABLE)

$(OUTPUT_DIR)/$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CC_FLAGS) -o $@ $^ $(LIBRARIES) $(CC_LINK_FLAGS)

$(BUILD_DIR)/main.o: $(SOURCE_DIR)/main.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/core.program.o: $(SOURCE_DIR)/core/program.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/core.args.o: $(SOURCE_DIR)/core/args.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/model.objects.square.o: $(SOURCE_DIR)/model/objects/square.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/model.objects.vector.o: $(SOURCE_DIR)/model/objects/vector.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/model.utilities.position.o: $(SOURCE_DIR)/model/utilities/position.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/model.utilities.size.o: $(SOURCE_DIR)/model/utilities/size.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.colour.theme.o: $(SOURCE_DIR)/presentation/colour/theme.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.components.canvas.o: $(SOURCE_DIR)/presentation/components/canvas.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.components.panel.o: $(SOURCE_DIR)/presentation/components/panel.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.events.handler.o: $(SOURCE_DIR)/presentation/events/handler.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.graphics.renderer.o: $(SOURCE_DIR)/presentation/graphics/renderer.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(BUILD_DIR)/presentation.window.window.o: $(SOURCE_DIR)/presentation/window/window.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

.PHONY: init
init:
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	if not exist $(OUTPUT_DIR) mkdir $(OUTPUT_DIR)

.PHONY: clean
clean:
	del /f /q $(BUILD_DIR)\*
	del /f /q $(OUTPUT_DIR)\*
