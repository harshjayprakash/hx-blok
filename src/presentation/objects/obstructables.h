#ifndef NEON_WALLS_H
#define NEON_WALLS_H

#define STRICT 1
#include <Windows.h>

void NeonInitObstructables(void);

void NeonRenderObstructables(HDC displayContext);

void NeonFreeObstructables(void);

#endif