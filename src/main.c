#ifndef _UNICODE
#define _UNICODE
#endif

#if _WIN32

#include <Windows.h>
#include "core/interface/program.h"
int __stdcall WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nShowCmd)
{
    bloqDiscard(hPrevInstance);
    bloqDiscard(lpCmdLine);

    bloqInitProgram();
    bloqSaveArguments(hInstance, nShowCmd);
    bloqProcessArguments();
    bloqExitProgram();

    return 0;
}

#else
#error "This program can only be compiled on Windows."
#endif