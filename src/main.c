/**
 * @file main.c
 * @date 2024-08-09
 * @brief Provides an entrypoint into the program.
 */

#define STRICT 1
#include <Windows.h>
#include "core/result.h"
#include "core/log.h"
#include "core/program.h"

/**
 * @brief Provides an entrypoint for the Windows program.
 * 
 * @param hInstance Handle to the current instance of the program.
 * @param hPrevInstance Handle to the previous instance of the program.
 * @param lpCmdLine Command line for the program.
 * @param nShowCmd Controls how the window will be displayed.
 * @return int Returns the exit value.
 */
int __stdcall WinMain(
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, 
    int nShowCmd)
{
    (void) hPrevInstance;
    (void) lpCmdLine;

    NeonInitLogger(NeonConsole);

    (void) NeonInit(hInstance, nShowCmd);
    (void) NeonProcessArguments();
    (void) NeonStart();
    (void) NeonFree();

    NeonFreeLogger();

    return (int) NeonSuccess;
}