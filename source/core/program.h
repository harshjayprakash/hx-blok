#ifndef NEON_PROGRAM_H
#define NEON_PROGRAM_H

#include <windows.h>

void NeonInit(HINSTANCE instanceHandle, int showFlags);
HINSTANCE NeonGetInstanceHandle(void);
int NeonGetShowFlag(void);
int NeonIsInitialised(void);
void NeonStart(void);
void NeonFree(void);

#endif