# The Blok Experiment

> An exploration of the Windows API and the principles of lower level development.

When the application has been lauched, there will be a graphical window, displaying a
square that can be move around with arrows keys. The position coordinates relative to the
window displayed in the bottom left.

The cursor can be used to mark regions within the window. This is displayed in a colourful
colour.

![Main Window of Application](./window-light-dark.png)

## Program Structure

| Folder | Description |
|--------|-------------|
| core   | global macros and storage for the program's entrypoint arguments.  |
| model  | contains structures and enumerations to model objects. |
| logic | a translation layer that handles logic and storage for the presentation |
| presentation | handles the graphical user interface |

## What's new in this version (0.6)

### Visual

* Light and Dark mode, specified by Command Line Arguments.
* Changed colours

### Internal

* More organised code.
* Typdefs are now standard structs.
* Improved doxygen documentation.
* Block object renamed to Square.
* Debugging Mechanisms macros have a global switch.
* Grid is now a Vector.
* Now using wide character versions of functions.
* More safety checks _(not 100% fool-proof)_

### Removed

* Ability to unmark regions.
* 'on marked location' display.

## What is currently being worked on

* Doxygen Documenetion
* Vector library

## Limitations and Known Issues

* Vector cannot be resized.
* Regions cannot be marked after the Vector is full.
* Vector can store duplicate mark regions.
* The Square can moved out of the window region.
* The default Vector size is 10.
* GDI32 Graphics can flicker.

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
