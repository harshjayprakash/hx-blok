/**
 * @file window.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_WINDOW_H
#define NEON_WINDOW_H

#include "../core/result.h"

/**
 * @brief Initialises the window.
 * 
 * @return NeonResult If the window initialisation was successful.
 */
NeonResult NeonInitWindow(void);

/**
 * @brief Frees any resources of the window.
 * 
 * @return NeonResult If the window destruction was successful.
 */
NeonResult NeonFreeWindow(void);

#endif