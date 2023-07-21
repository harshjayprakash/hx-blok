/**
 * @file theme.h
 * @version 0.6.1
 * @date 18-07-2023
 * 
 * @brief Theme management.
 * 
 * This header file contains the functions required for theme management.
 */

#ifndef BLOK_THEME_H
#define BLOK_THEME_H

#include <Windows.h>

/**
 * @brief Describes the theme of the program.
 * 
 * This will determine the colours painted with the window.
 */
enum Theme
{
    /**
     * @brief Represents default theme, being unset.
     * 
     * By default with this option, the program will start in a light theme.
     */
    Unset,

    /**
     * @brief Represents light mode.
     */
    ThemeLight,

    /**
     * @brief Represents dark mode.
     */
    ThemeDark
};

/**
 * @brief Sets the theme.
 * 
 * The theme determines the colour used in the program's graphical user interface.
 * 
 * @param _theme the theme to be set.
 * 
 * @note This can only be set before the window is created. This function will not have
 *       any functionality after this. The colours of the rendered square may change
 *       however the window's background colour will not.
 */
void blokThemeSet(enum Theme _theme);

/**
 * @brief Gets the currently set theme.
 * 
 * @return The current theme.
 */
enum Theme blokThemeGet(void);

/**
 * @brief Gets the background colour.
 * 
 * The background colour depends on the theme set.
 * 
 * @return THe background colour.
 */
unsigned long blokColourBackgroundGet(void);

/**
 * @brief Gets the foreground colour.
 * 
 * The foreground colour depends on the theme set.
 * 
 * @return The foreground colour.
 */
unsigned long blokColourForegroundGet(void);

/**
 * @brief Gets the mark colour.
 * 
 * The mark colour depends on the theme set.
 * 
 * @return The colour for the mark.
 */
unsigned long blokColourMarkGet(void);

#endif
