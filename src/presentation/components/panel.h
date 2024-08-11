/**
 * @file panel.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_PANEL_H
#define NEON_PANEL_H

#define STRICT 1
#include <Windows.h>

void NeonInitPanelComponent(void);

void NeonRenderPanelComponent(HDC displayContext);

void NeonFreePanelComponent(void);

#endif