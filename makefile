CC = gcc
CC_FLAGS = -g -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
			-Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations \
			-Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual \
			-Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel \
			-Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -DUNICODE -D_UNICODE

LIBRARIES = -lgdi32

SOURCE_DIRECTORY = src
BUILD_DIRECTORY = build
OUTPUT_DIRECTORY = bin

BINARY = blok

all: compile link

main.o: $(SOURCE_DIRECTORY)/main.cpp:
	$(CC) $(CC_FLAGS) -c $^ -o $(BUILD_DIRECTORY)/$@

link:
	$(CC) $(CC_FLAGS) -o $(OUTPUT_DIRECTORY)/$(BINARY) $(BUILD_DIRECTORY)/*.o $(LIBRARIES)