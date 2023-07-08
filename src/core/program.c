#include "program.h"

static struct Program singletonInstance = { };
static int initialised = 0;

static void blokProgramProcessArguments()
{
}

void blokProgramInitialise(
    HINSTANCE _instanceHandle, HINSTANCE _previousInstanceHandle, 
    LPSTR _commandLineArguments, int _showFlag)
{
    BLOK_EXIT_IF(initialised);

    singletonInstance.instanceHandle = _instanceHandle;
    singletonInstance.previousInstanceHandle = _previousInstanceHandle;
    singletonInstance.commandLineArguments = _commandLineArguments;
    singletonInstance.showFlag = _showFlag;

    blokProgramProcessArguments();

    initialised = 1;
}

struct Program *blokProgramInstanceGet(void)
{
    return &singletonInstance;
}

void blokProgramFree(void)
{
    
}
