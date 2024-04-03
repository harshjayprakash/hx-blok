#include "program.h"
#include "macros.h"

static int sInitialised = 0;
static HINSTANCE sInstanceHandle = { 0 };
static int sShowFlag = 0;

void bloqInitProgram(void)
{
    bloqExitCondition(sInitialised);

    sInitialised = 1;
}

void bloqSaveArguments(HINSTANCE instanceHandle, int showFlag)
{
    bloqExitCondition(!sInitialised);

    sInstanceHandle = instanceHandle;
    sShowFlag = showFlag;
}

void bloqProcessArguments(void)
{
    bloqExitCondition(!sInitialised);
}

void bloqExitProgram(void)
{
    bloqExitCondition(!sInitialised);

    sInitialised = 0;
}