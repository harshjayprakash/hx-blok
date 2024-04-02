# Compiler Options -----------------------------------------------------------------------

CC                      = clang
CC_FLAGS                = -g -Wall -Werror -std=c17
CC_LINK_FLAGS           = -mwindows -mconsole


# Libraries ------------------------------------------------------------------------------

LIBS                    = -lkernel32 -luser32 -lshell32 -lgdi32


# Includes -------------------------------------------------------------------------------

INCS                    = -iinc


# Directories ----------------------------------------------------------------------------

DIR_BIN                 = bin
DIR_BUILD               = build
DIR_INC                 = inc
DIR_SRC                 = src
DIR_TEST                = test
DIR_RES                 = res


# Object Files ---------------------------------------------------------------------------

OBJ                     = $(DIR_BUILD)/main.o


# Output ---------------------------------------------------------------------------------

EXE                     = bloq.exe


# Recipes --------------------------------------------------------------------------------

.PHONY: ALL
ALL:
	ifeq ($(OS),Windows_NT)
		INIT
		$(DIR_BIN)/$(EXE)
	endif

.PHONY: INIT
INIT:
	if not exist $(DIR_BIN) mkdir $(DIR_BIN)
	if not exist $(DIR_BUILD) mkdir $(DIR_BUILD)

$(DIR_BIN)/$(EXE): $(OBJ)
	$(CC) $(CC_FLAGS) -o $@ $^ $(LIBS) $(CC_LINK_FLAGS)

$(DIR_BUILD)/main.o: src/main.o
	$(CC) $(CC_FLAGS) -c $^ -o $@

.PHONY: CLEAN
CLEAN:
	if exist $(DIR_BIN) del /f /q $(DIR_BIN)
	if exist $(DIR_BUILD) del /f /q $(DIR_BUILD)