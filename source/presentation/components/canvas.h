#ifndef NEON_CANVAS_H
#define NEON_CANVAS_H

#include "../../model/objects/square.h"
#include <windows.h>

void NeonInitCanvas(void);

NeonSquare *NeonGetBlockReference(void);

void NeonRenderCanvas(HDC displayContext);

#endif