#include "program.h"
#include "args.h"
#include "../presentation/colour/theme.h"
#include "../presentation/window/window.h"

static HINSTANCE instanceHandle = { 0 };
static int showFlag = 0;
static int initialised = 0;

void NeonInit(HINSTANCE inInstanceHandle, int inShowFlag)
{
    initialised = 1;

    instanceHandle = inInstanceHandle;
    showFlag = inShowFlag;
}

HINSTANCE NeonGetInstanceHandle(void)
{
    return instanceHandle;
}

int NeonGetShowFlag(void)
{
    return initialised;
}

int NeonIsInitialised(void)
{
    return initialised;
}

void NeonStart(void)
{
    NeonProcessArguments();
    NeonUpdateColours();

    NeonInitWindow();
    NeonFreeWindow();
}

void NeonFree(void)
{
    initialised = 0;
}