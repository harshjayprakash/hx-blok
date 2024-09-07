/**
 * \file panel.h
 * \date 07-09-2024
 * \brief Function prototypes for the panel component.
 *
 * This file contains the function prototypes for initialising, rendering, managing the
 * panel component
 */

#ifndef NEON_PANEL_H
#define NEON_PANEL_H

#define STRICT 1
#include <Windows.h>

/**
 * \brief Initialise the panel component.
 */
void NeonInitPanelComponent(void);

/**
 * \brief Render the panel component.
 *
 * \param displayContext The display context handle.
 */
void NeonRenderPanelComponent(HDC displayContext);

/**
 * \brief Update the coordinates text based on block position.
 */
void NeonUpdateCoordinatesText(void);

/**
 * \brief Update the panel size based on window size.
 */
void NeonUpdatePanelSize(void);

/**
 * \brief Update the vector's memory bar.
 */
void NeonUpdateVectorMemoryBar(void);

/**
 * \brief Checks if position is within the panel component area.
 *
 * \param x The x position.
 * \param y The y position.
 * \return If the position was within the area.
 *
 * \retval 0: Outside Area.
 * \retval 1: Inside Area.
 */
int NeonIsInPanelArea(const int x, const int y);

/**
 * \brief Check if position is within Clear Button area.
 *
 * \param x The x position clicked.
 * \param y The y position clicked.
 * \return If the position was within the area.
 *
 * \retval 0: Outside Area.
 * \retval 1: Inside Area.
 */
int NeonIsInClearButtonArea(const int x, const int y);

/**
 * \brief Checks if position is within the lock toggle button area.
 *
 * \param x The x position.
 * \param y The y position.
 * \return If the position was within the area.
 *
 * \retval 0: Outside Area.
 * \retval 1: Inside Area.
 */
int NeonIsInLockToggleArea(const int x, const int y);

/**
 * \brief Checks if position is within the generate button area.
 *
 * \param x The x position.
 * \param y The y position.
 * \return If the position was within the area.
 *
 * \retval 0: Outside Area.
 * \retval 1: Inside Area.
 */
int NeonIsInGenerateButtonArea(const int x, const int y);

/**
 * \brief Invalidates the coordinate text area.
 */
void NeonInvalidateCoordinateTextArea(void);

/**
 * \brief Invalidates the clear all button area.
 */
void NeonInvalidateClearAllButtonArea(void);

/**
 * \brief Invalidates the locked toggle button area.
 */
void NeonInvalidateLockedToggleArea(void);

/**
 * \brief Invalidates the progress bar area.
 */
void NeonInvalidateProgressBarArea(void);

/**
 * \brief Invalidates the random button area.
 */
void NeonInvalidateRandomButtonArea(void);

/**
 * \brief Handles the locked toggle button click operation.
 */
void NeonHandleLockToggleButtonClick(void);

/**
 * \brief Frees any resources used by the panel component.
 */
void NeonFreePanelComponent(void);

#endif