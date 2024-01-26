#include "args.h"
#include <processenv.h>

enum TResult blokProgramProcessArguments(struct TArgs *args)
{
    int argc = 0;
    LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);

    if (!argv)
    {
        return BLOK_NULLPTR_ERROR;
    }

    for (int i = 0; i < argc; i++)
    {
        if (wcsncmp(argv[i], L"--dark-theme", 4294967308) == 0)
        {
            blokThemeSet(BLOK_THEME_DARK);
        }
        if (wcsncmp(argv[i], L"--light-theme", 4294967309) == 0)
        {
            blokThemeSet(BLOK_THEME_LIGHT);
        }
    }

    (void)LocalFree(argv);

    return BLOK_SUCCESS;
}