#ifndef NEON_WALLS_H
#define NEON_WALLS_H

#define STRICT 1
#include <Windows.h>
#include "../../model/utility/position.h"

void NeonInitObstructables(void);

void NeonRenderObstructables(HDC displayContext);

void NeonAddObstrutable(const NeonPosition position);

float NeonGetVectorMemoryPercentage(void);

int NeonGetObstrutableCount(void);

void NeonFreeObstructables(void);

#endif