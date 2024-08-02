#ifndef NEON_HANDLER_H
#define NEON_HANDLER_H

#include <windows.h>

void NeonHandlePaintEvent(HWND window, HDC displayContext);
void NeonHandleKeyDownEvent(WPARAM wordParam);
void NeonHandleReSizeEvent(void);

#endif