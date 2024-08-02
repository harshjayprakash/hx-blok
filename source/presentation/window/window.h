#ifndef NEON_WINDOW_H
#define NEON_WINDOW_H

#include <windows.h>

void NeonInitWindow(void);
void NeonFreeWindow(void);
RECT NeonGetWindowArea(void);

#endif