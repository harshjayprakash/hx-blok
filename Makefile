# Compiler Options -----------------------------------------------------------------------

CC                      = clang
CC_FLAGS                = -g -Wall -Werror -std=c17
CC_LINK_FLAGS           = -mwindows -mconsole


# Libraries ------------------------------------------------------------------------------

LIBS                    = -Lkernel32 -Luser32 -Lshell32 -Lgdi32


# Includes -------------------------------------------------------------------------------

HDR_FILES               = -Iinc


# Directories ----------------------------------------------------------------------------

DIR_BIN                 = bin
DIR_BUILD               = build
DIR_INC                 = inc
DIR_SRC                 = src
DIR_TEST                = test
DIR_RES                 = res


# Object Files ---------------------------------------------------------------------------

OBJ_FILES               = $(DIR_BUILD)/main.o \
							$(DIR_BUILD)/core.interface.program.o \
							$(DIR_BUILD)/core.common.globals.o \
							$(DIR_BUILD)/core.common.position.o \
							$(DIR_BUILD)/core.common.size.o \
							$(DIR_BUILD)/model.entity.square.o \
							$(DIR_BUILD)/logic.state.state-manager.o \
							$(DIR_BUILD)/presentation.window.pane.o


# Output ---------------------------------------------------------------------------------

OUT_FILE                = bloq.exe


# Recipes --------------------------------------------------------------------------------

.PHONY: init
init:
	if not exist $(DIR_BIN) mkdir $(DIR_BIN)
	if not exist $(DIR_BUILD) mkdir $(DIR_BUILD)


.PHONY: build
build: $(DIR_BIN)/$(OUT_FILE)


$(DIR_BIN)/$(OUT_FILE): $(OBJ_FILES)
	$(CC) $(CC_FLAGS) -o $@ $^ $(LIBS) $(CC_LINK_FLAGS)

$(DIR_BUILD)/main.o: src/main.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(DIR_BUILD)/core.common.globals.o: src/core/common/globals.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(DIR_BUILD)/core.common.position.o: src/core/common/position.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(DIR_BUILD)/core.common.size.o: src/core/common/size.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(DIR_BUILD)/core.interface.program.o: src/core/interface/program.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(DIR_BUILD)/model.entity.square.o: src/model/entity/square.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(DIR_BUILD)/logic.state.state-manager.o: src/logic/state/state-manager.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(DIR_BUILD)/presentation.window.pane.o: src/presentation/window/pane.c
	$(CC) $(CC_FLAGS) -c $^ -o $@


.PHONY: clean
clean:
	if exist $(DIR_BIN) del /f /q $(DIR_BIN)
	if exist $(DIR_BUILD) del /f /q $(DIR_BUILD)
