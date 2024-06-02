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

OBJ_FILES               = $(DIR_BUILD)/main.o


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


.PHONY: clean
clean:
	if exist $(DIR_BIN) del /f /q $(DIR_BIN)
	if exist $(DIR_BUILD) del /f /q $(DIR_BUILD)
