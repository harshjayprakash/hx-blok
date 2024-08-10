/**
 * @file program.c
 * @date 2024-08-09
 * @brief
 */

#include "program.h"
#include "result.h"
#include "log.h"
#include "../presentation/graphics/theme.h"
#include "../presentation/window.h"
#include "../presentation/graphics/drawing.h"
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>

static HINSTANCE mInstanceHandle = { 0 };
static int mShowflag = 0;
static int mInitialised = 0;

NeonResult NeonInit(HINSTANCE instanceHandle, int showFlags)
{
    if (mInitialised)
    {
        return NeonLogAndReturn(NeonWarning, NeonCreateResult(NeonCannotReInit, L"Cannot re-initalise program."));
    }

    mInstanceHandle = instanceHandle;
    mShowflag = showFlags;
    mInitialised = 1;

    return NeonCreateResult(NeonSuccess, L"Program initialised successfully.");
}

NeonResult NeonProcessArguments(void)
{
    if (!mInitialised)
    {
        return NeonLogAndReturn(NeonError, NeonCreateResult(NeonNotInit, L"Program has not not initialised."));
    }

    int argumentCount = 0;
    LPWSTR *arguments = CommandLineToArgvW(GetCommandLineW(), &argumentCount);

    if (!arguments)
    {
        return NeonLogAndReturn(NeonError, NeonCreateResult(NeonNotInit, L"Failed to get arguments."));
    }

    for (int index = 0; index < argumentCount; index++)
    {

        if (wcsncmp(arguments[index], L"--dark-mode", 12*sizeof(unsigned short)) == 0)
        {
            NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Changing program theme to dark mode."));
            NeonSetTheme(NeonDarkTheme);
        }
        if (wcsncmp(arguments[index], L"--light-mode", 13*sizeof(unsigned short)) == 0)
        {
            NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Changing program theme to light mode."));
            NeonSetTheme(NeonLightTheme);
        }
    }

    NeonUpdateColours();

    (void) LocalFree(arguments);

    return NeonCreateResult(NeonSuccess, L"Processed arguments successfully.");
}

NeonResult NeonStart(void)
{
    NeonInitDrawingTools();
    NeonInitWindow();
    NeonFreeWindow();
    NeonFreeDrawingTools();
    return NeonLogAndReturn(NeonInformation, NeonCreateResult(NeonSuccess, L"Quit message recieved."));
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
    return NeonLogAndReturn(NeonInformation, NeonCreateResult(NeonSuccess, L"No resources to free."));
}