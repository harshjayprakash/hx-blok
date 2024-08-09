/**
 * @file program.c
 * @date 2024-08-09
 * @brief
 */

#include "program.h"
#include "result.h"
#include "log.h"

static HINSTANCE mInstanceHandle = { 0 };
static int mShowflag = 0;
static int mInitialised = 0;

NeonResult NeonInit(HINSTANCE instanceHandle, int showFlags)
{
    if (mInitialised)
    {
        return NeonLogAndReturn(NeonWarning, NeonNewResult(NeonCannotReInit, L"Cannot re-initalise program."));
    }

    mInstanceHandle = instanceHandle;
    mShowflag = showFlags;
    mInitialised = 1;

    return NeonNewResult(NeonSuccess, L"Program initialised successfully.");
}

NeonResult NeonProcessArguments(void)
{
    if (!mInitialised)
    {
        return NeonLogAndReturn(NeonError, NeonNewResult(NeonNotInit, L"Program has not not initialised."));
    }

    int argumentCount = 0;
    LPWSTR *arguments = CommandLineToArgvW(GetCommandLineW(), &argumentCount);

    if (!arguments)
    {
        return NeonLogAndReturn(NeonError, NeonNewResult(NeonNotInit, L"Failed to get arguments."));
    }

    (void) LocalFree(arguments);

    return NeonNewResult(NeonSuccess, L"Processed arguments successfully.");
}

NeonResult NeonStart(void)
{
    return NeonLogAndReturn(NeonUnknown, NeonNewResult(NeonNotImpl, L"Start: Not Implementated."));
}

NeonResult NeonFree(void)
{
    return NeonLogAndReturn(NeonInformation, NeonNewResult(NeonSuccess, L"No resources to free."));
}