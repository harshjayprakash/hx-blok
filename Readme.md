# The Experimental Block Project

![Banner](./doc/banner.png)

> [!NOTE]
> As this is an experiment without a clear roadmap, this program will likely always be in
> the developing stage. There will not be a deployed executable file.

## Usage

## Compilation and Execution

This program uses the make build system. Note, this uses the clang compiler, you can
switch it to the GCC compiler, if you wish by changing the CC variable in the makefile.
You can run the following:

```sh
# Creating the folders build and bin for the compilation process.
mingw32-make init

# Building and linking the program.
mingw32-make build

# Running the program.
./bin/neon-blok
```

## What's New (Version 24.10)

- Logging
- Re-implementated Result System
- Vector Size Indicator
- Changed Style of Movable Block
- Switched Colour Scheme

## Code Standard

The codename for this project is "Neon", so structures, enumerations and functions are
prefixed with this. These are in PascalCase, while variables are in camelCase.

## Known Issues and Limitations

- Some functionality from the previous version is missing.

## Find an issue

If you find an issue, feel free to report it under the issues tab of this repository.
