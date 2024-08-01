#ifndef NEON_BLOCK_H
#define NEON_BLOCK_H

#include "../../model/objects/square.h"
#include <windows.h>

void NeonInitBlock(void);

NeonSquare *NeonGetBlockReference(void);

void NeonRenderBlock(HDC inDisplayContextHandle, HBRUSH accentBrushHandle);

#endif