#ifndef NEON_CANVAS_H
#define NEON_CANVAS_H

#include "../../model/objects/square.h"
#include "../../model/objects/vector.h"
#include <windows.h>

void NeonInitCanvas(void);

NeonSquare *NeonGetBlockReference(void);

NeonVector *NeonGetVectorReference(void);

void NeonRenderCanvas(HDC displayContext);

void NeonFreeCanvas(void);

#endif