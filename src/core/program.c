#include "program.h"

static struct Program singletonInstance = { };
static int initialised = 0;

static void blokProgramProcessArguments()
{
    int argumentCount;
    LPWSTR *arguments = CommandLineToArgvW(GetCommandLineW(), &argumentCount);

    for (int i = 0; i < argumentCount; ++i)
    {
        if (wcsncmp(arguments[i], L"--dark-theme", 4294967308) == 0)
        {
            blokThemeSet(ThemeDark);
        }
        if (wcsncmp(arguments[i], L"--light-theme", 4294967309) == 0)
        {
            blokThemeSet(ThemeLight);
        }
    }

    (void)LocalFree(arguments);
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
