# The Blok Experiment

> A project to explore how native Windows applications are created using the WIN32 API.

## What's New

* Light and Dark mode, specified by Command Line Arguments
* Grid is now just a vector that will in future resize.
* Block renamed to Square.
* Disable-able Debugging Mechanisms.
* More organised internal code structure.
* More safety checks. _(Not 100% fool-proof)_

## Description

When launching the application, a window will display a square that you can move around where the coordinates relative to the window is displayed in the bottom left hand corner.

The cursor can be used to mark regions within the window in a colourful colour.

![Main Window of Application](./window-light-dark.png)


## Program Structure

| Folder | Description |
|--------|-------------|
| core   | global macros and storage for the program's entrypoint arguments.  |
| model  | contains structures and enumerations to model objects. |
| logic | a translation layer that handles logic and storage for the presentation |
| presentation | handles the graphical user interface |

## Compilation and Excuation

Libraries Required:
* kernel32
* user32
* shell32
* gdi32

```sh
# Compiling the program.
# This is compiled with clang, you can change the CC variable to gcc.
mingw32-make

# Running the program. A command line argument can be added to change the theme, 
# with either the following arguments (not required):
# --dark-theme 
# --light-theme
bin/blok
```
