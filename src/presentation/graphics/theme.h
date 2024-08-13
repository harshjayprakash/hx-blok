/**
 * \file theme.h
 * \date 13-08-2024
 * \brief Function definitions and enumeration for theming.
 * 
 * This file contains an enumeration to denote the current theme and function defintions 
 * to set and get the colours within the theme.
 */

#ifndef NEON_THEME_H
#define NEON_THEME_H

#define STRICT 1
#include <Windows.h>

#include "../../core/result.h"

/**
 * \brief The chosen theme.
 */
typedef enum __NeonTheme
{
    NeonUnsetTheme = 0x000001,   ///< Unset Theme
    NeonLightTheme = 0x000002,   ///< Light Mode
    NeonDarkTheme = 0x000003     ///< Dark Mode
} NeonTheme;

/**
 * \brief Update the colours based on the chosen theme.
 *
 * \warning This function must be called to initialise the colours.
 */
void NeonUpdateColours(void);

/**
 * \brief Set the theme.
 * 
 * \param theme The theme.
 */
void NeonSetTheme(const NeonTheme theme);

/**
 * \brief Gets the background colour.
 * 
 * \return The background colour.
 */
unsigned long NeonGetBackgroundColour(void);

/**
 * \brief Gets the foreground colour.
 * 
 * \return The foreground colour.
 */
unsigned long NeonGetForegroundColour(void);

/**
 * \brief Gets the accent colour.
 * 
 * \return The accent colour.
 */
unsigned long NeonGetAccentColour(void);


#endif