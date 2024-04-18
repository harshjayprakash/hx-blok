#include "program.h"
#include "../../presentation/window/pane.h"
#include <Windows.h>
#include <stdio.h>

static int sInitialised = 0;
static HINSTANCE sInstanceHandle = { 0 };
static int sShowFlag = 0;

void bloqInitProgram(void)
{
    if (sInitialised) { return; }

    sInitialised = 1;
}

void bloqSaveArguments(HINSTANCE instanceHandle, int showFlag)
{
    if (!sInitialised) { return; }

    sInstanceHandle = instanceHandle;
    sShowFlag = showFlag;
}

void bloqProcessArguments(void)
{
    if (!sInitialised) { return; }
}

void bloqStart(void)
{
    if (!sInitialised) { return; }

    TPane pane = bloqInitPane();
    bloqFreePane(&pane);
}

HINSTANCE bloqGetInstanceHandle(void)
{
    if (!sInitialised) { return NULL; }

    return sInstanceHandle;
}

int bloqGetShowFlag(void)
{
    return sShowFlag;
}

void bloqExitProgram(void)
{
    if (!sInitialised) { return; }

    sInitialised = 0;
}