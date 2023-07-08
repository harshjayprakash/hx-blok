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

#endif
