#ifndef BLOK_PROGRAM_H
#define BLOK_PROGRAM_H

#include <Windows.h>

struct Program
{
    HINSTANCE instanceHandle;
    HINSTANCE previousInstanceHandle;
    LPSTR commandLineArguments;
    int showFlag;
};

void blokProgramInitialise(
    HINSTANCE _instanceHandle, HINSTANCE _previousInstanceHandle,
    LPSTR _commandLineArguments, int _showFlag);

struct Program *blokProgramInstanceGet(void);

void blokProgramFree(void);

#endif
