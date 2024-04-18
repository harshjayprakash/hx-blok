#ifndef _UNICODE
#define _UNICODE
#endif

#if _WIN32

#include <Windows.h>
#include "core/interface/program.h"

/**
 * \brief Provides an entrypoint into the application.
 * 
 * \param hInstance handle to the instance of the application.
 * \param hPrevInstance previous 16-bit instance; not used.
 * \param lpCmdLine ascii version of the command line; not used.
 * \param nShowCmd how the application is shown.
 * \return int - the exit code for the application.
 */
int __stdcall WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    (void) hPrevInstance;
    (void) lpCmdLine;

    bloqInitProgram();

    bloqSaveArguments(hInstance, nShowCmd);
    bloqProcessArguments();
    bloqStart();

    bloqExitProgram();

    return 0;
}

#else
#error "This program can only be compiled on Windows."
#endif