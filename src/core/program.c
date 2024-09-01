/**
 * \file program.c
 * \date 13-08-2024
 * \brief Implementation of the program module.
 *
 * This file contains the function implementation of the program "singleton", storing
 * global values.
 */

#include "program.h"
#include "../presentation/graphics/drawing.h"

#include "../presentation/window.h"
#include "log.h"
#include "result.h"

static HINSTANCE mInstanceHandle = {0};
static int mShowflag = 0;
static int mInitialised = 0;

NeonResult NeonInit(HINSTANCE instanceHandle, int showFlags)
{
    if (mInitialised)
    {
        return NeonLogAndReturn(
            NeonWarning, NeonCreateResult(NeonCannotReInit,
                                          L"Cannot Re-Initialise Program: Skipping."));
    }

    mInstanceHandle = instanceHandle;
    mShowflag = showFlags;
    mInitialised = 1;

    return NeonCreateResult(NeonSuccess, L"Program Initialised.");
}

int NeonIsInit(void)
{
    return mInitialised;
}

NeonResult NeonStart(void)
{
    NeonInitDrawingTools();
    NeonInitWindow();
    NeonFreeWindow();
    NeonFreeDrawingTools();
    return NeonLogAndReturn(
        NeonInformation,
        NeonCreateResult(NeonSuccess, L"Quit Message Recieved: Closing."));
}

HINSTANCE NeonGetHandle(void)
{
    return mInstanceHandle;
}

int NeonGetShowFlag(void)
{
    return mShowflag;
}

NeonResult NeonFree(void)
{
    return NeonLogAndReturn(
        NeonInformation, NeonCreateResult(NeonSuccess, L"Cleaned Up Program Resources."));
}