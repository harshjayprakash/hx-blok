#include "program.h"

static struct TProgram programInst;

static int initialised = 0;

enum TResult blokProgramInit(struct TArgs *pArgs)
{
    if (initialised)
    {
        return BLOK_UNNESSECARY_INIT;
    }
    
    if (!pArgs)
    {
        return BLOK_NULLPTR_ERROR;
    }

    programInst.pArgs = pArgs;

    initialised = 1;

    return BLOK_SUCCESS;
}

struct TProgram *blokProgramInstanceGet(void)
{
    return &programInst;
}

void blokProgramFree(void)
{

}