/**
 * @file theme.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_THEME_H
#define NEON_THEME_H

#define STRICT 1
#include <Windows.h>

#include "../../core/result.h"

/**
 * @brief A enumeration to describe the theming of the program.
 */
typedef enum __NeonTheme
{
    /**
     * @brief Unset theme.
     */
    NeonUnsetTheme = 0x000001,
    /**
     * @brief Light mode.
     */
    NeonLightTheme = 0x000002,
    /**
     * @brief Dark mode.
     */
    NeonDarkTheme = 0x000003
} NeonTheme;

/**
 * @brief Update the assigned to colours to the corresponding theme.
 */
void NeonUpdateColours(void);

/**
 * @brief Set the theme of the program.
 */
void NeonSetTheme(const NeonTheme theme);

/**
 * @brief Gets the background colour based on the set theme.
 * 
 * @return unsigned long The background colour.
 */
unsigned long NeonGetBackgroundColour(void);

/**
 * @brief Gets the foreground colour based on the set theme.
 * 
 * @return unsigned long The foreground colour.
 */
unsigned long NeonGetForegroundColour(void);

/**
 * @brief Gets the account colour based on the set theme.
 * 
 * @return unsigned long The accent colour.
 */
unsigned long NeonGetAccentColour(void);


#endif