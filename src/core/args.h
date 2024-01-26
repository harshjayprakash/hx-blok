#ifndef BLOK_CORE_ARGS_H
#define BLOK_CORE_ARGS_H

#include <Windows.h>
#include "result.h"
#include "../logic/theme.h"

struct TArgs
{
    HINSTANCE instanceHandle;
    HINSTANCE previousInstanceHandle;
    LPSTR commandLine;
    int showFlag;
};

enum TResult blokProgramProcessArguments(struct TArgs *args);

#endif