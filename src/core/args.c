/**
 * \file args.c
 * \date 18-08-2024
 * \brief
 *
 */

#include "args.h"
#include "../presentation/graphics/theme.h"
#include "log.h"
#include "program.h"
#include "result.h"
#include <wchar.h>

static int mBlockScale = 15;

NeonResult NeonProcessArguments(void)
{
    if (!NeonIsInit())
    {
        return NeonLogAndReturn(
            NeonError,
            NeonCreateResult(NeonNotInit, L"Argument Processing Failed: Program Not Initialised."));
    }

    int argumentCount = 0;
    LPWSTR *arguments = CommandLineToArgvW(GetCommandLineW(), &argumentCount);

    if (!arguments)
    {
        return NeonLogAndReturn(
            NeonError, NeonCreateResult(NeonNotInit, L"Arguments Processing Failed: Cannot Get."));
    }

    int scaleMode = 0;

    for (int index = 0; index < argumentCount; index++)
    {

        if (wcsncmp(arguments[index], L"--dark-mode", 12 * sizeof(unsigned short)) == 0)
        {
            NeonLog(NeonInformation,
                    NeonCreateResult(NeonNone, L"Theme Changed to Dark Mode."));
            NeonSetTheme(NeonDarkTheme);
        }
        if (wcsncmp(arguments[index], L"--light-mode", 13 * sizeof(unsigned short)) == 0)
        {
            NeonLog(NeonInformation,
                    NeonCreateResult(NeonNone, L"Theme Changed to Light Mode."));
            NeonSetTheme(NeonLightTheme);
        }
        if (wcsncmp(arguments[index], L"--scale", 13 * sizeof(unsigned short)))
        {
            scaleMode = 1;
            NeonLog(NeonInformation, NeonCreateResult(NeonNone, L"Updating Block Scale."));
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

    return NeonCreateResult(NeonSuccess, L"Arguments Processed.");
}

int NeonGetBlockScale(void)
{
    return mBlockScale;
}