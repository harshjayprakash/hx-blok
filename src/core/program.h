#ifndef BLOK_CORE_PROGRAM_H
#define BLOK_CORE_PROGRAM_H

#include <Windows.h>
#include "result.h"
#include "args.h"

struct TProgram
{
    struct TArgs *pArgs;
};

enum TResult blokProgramInit(struct TArgs *pArgs);

struct TProgram *blokProgramInstanceGet(void);

void blokProgramFree(void);

#endif