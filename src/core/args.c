/**
 * \file args.c
 * \date 18-08-2024
 * \brief 
 * 
 */

#include "args.h"
#include "../presentation/graphics/theme.h"
#include <wchar.h>
#include "program.h"
#include "result.h"
#include "log.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// static int mOverrideDefaults = 0;
static int mBlockScale = 15;

NeonResult NeonProcessArguments(void)
{
    if (!NeonIsInit())
    {
        return NeonLogAndReturn(
            NeonError,
            NeonCreateResult(NeonNotInit, L"Program has not not initialised."));
    }

    int argumentCount = 0;
    LPWSTR *arguments = CommandLineToArgvW(GetCommandLineW(), &argumentCount);

    if (!arguments)
    {
        return NeonLogAndReturn(
            NeonError, NeonCreateResult(NeonNotInit, L"Failed to get arguments."));
    }

    int scaleMode = 0;

    for (int index = 0; index < argumentCount; index++)
    {

        if (wcsncmp(arguments[index], L"--dark-mode", 12 * sizeof(unsigned short)) == 0)
        {
            NeonLog(NeonInformation,
                    NeonCreateResult(NeonNone, L"Changing program theme to dark mode."));
            NeonSetTheme(NeonDarkTheme);
        }
        if (wcsncmp(arguments[index], L"--light-mode", 13 * sizeof(unsigned short)) == 0)
        {
            NeonLog(NeonInformation,
                    NeonCreateResult(NeonNone, L"Changing program theme to light mode."));
            NeonSetTheme(NeonLightTheme);
        }

        if (wcsncmp(arguments[index], L"--scale", 13 * sizeof(unsigned short)))
        {
            scaleMode = 1;
        }
        if (scaleMode)
        {
            int value = _wtoi(arguments[index]);
            if (value == 0)
            {
                scaleMode = 0;
                continue;
            }
            mBlockScale = value;
            scaleMode = 0;
        }
    }

    NeonUpdateColours();

    (void)LocalFree(arguments);

    return NeonCreateResult(NeonSuccess, L"Processed arguments successfully.");
}

int NeonGetBlockScale(void)
{
    return mBlockScale;
}