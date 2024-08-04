#include "args.h"
#include "program.h"
#include "../presentation/colour/theme.h"

#include <windows.h>

void NeonProcessArguments(void)
{
    if (!NeonIsInitialised()) { return; }
    
    int argumentCount = 0;
    LPWSTR *arguments = CommandLineToArgvW(GetCommandLineW(), &argumentCount);
    
    if (!arguments) { return; }
    
    for (int index = 0; index < argumentCount; index++)
    {
        if (wcsncmp(arguments[index], L"--dark-mode", 12*sizeof(unsigned short)) == 0)
        {
            NeonSetTheme(NeonDarkTheme);
        }
        if (wcsncmp(arguments[index], L"--light-mode", 13*sizeof(unsigned short)) == 0)
        {
            NeonSetTheme(NeonLightTheme);
        }
    }
    
    (void) LocalFree(arguments);
}