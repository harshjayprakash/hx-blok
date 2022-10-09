C := gcc
CFLAGS := -Wall -Werror -g -static
CFLAGSR := -Wall -Werror -O3

INPUT_FILES := src/main.c src/app.c src/window.c src/window_events.c src/block.c src/grid.c
LIBS := -lgdi32
OUTPUT_FILE := bin/blok

ALL: DEBUG

DEBUG:
	$(C) $(CFLAGS) $(INPUT_FILES) -o $(OUTPUT_FILE) $(LIBS)

RELEASE:
	$(C) $(CFLAGSR) $(INPUT_FILES) -o $(OUTPUT_FILE) $(LIBS)