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

## What's new in this version (0.7)

### Visual

* Light mode mark colour changed to aqua.

### Internal

* Improved doxygen documentation.
* Continued vector implementation.
* Collusion system with marks.
* Boundary system has been added.
* Safety checks _(not 100% fool-proof)_

## What is currently being worked on

* Doxygen Documentation
* Vector Module.

## Limitations and Known Issues

* Regions cannot be unmarked.
* Vector can store duplicate mark regions.
* The Square can be covering the last marked region without indication.
* GDI32 Graphics can flicker.

## Compilation and Execuation

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
