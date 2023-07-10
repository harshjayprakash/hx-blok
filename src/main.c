/**
 * @file main.c
 * @version 1.0
 * @date 10-07-2023
 * 
 * @brief Entrypoint for the program.
 * 
 * This file contains WinMain which serves as a starting point for the compiled executable
 * It initialises thw window and any globals needed for the program to run.
 */
#include <Windows.h>

#include "core/program.h"
#include "core/debug.h"
#include "presentation/window.h"
#include "logic/store.h"

/**
 * @brief Entrypoint for the program.
 * 
 * Responsible for starting up the program, initialising any globally stored data and 
 * creation of the window. After this, cleaning up resources when terminating.
 * 
 * @param hInstance The handle to the current instance of the program.
 * @param hPrevInstance Always NULL in this program.
 * @param lpCmdLine A pointer to a null terminated string that specifies the command line
 *                  for the program, excluding the program name.
 * @param nCmdShow Controls how the window is to be shown.
 * 
 * @details The program is started by
 *          1. Starting the console for debugging, if emabled.
 *          2. Stores the parameters in the program store.
 *          3. The global store's values are initialised
 *          4. An instance of the main window is created, including creation and startup.
 *          
 *          After the window has been close, the resources allocated will be cleaned up
 *          by using the corresponding free functions.
 * 
 * @note This is the standard ASCII WinMain entrypoint due to Mingw GCC not supporting
 *       the unicode version of wWinMain.
 */
int APIENTRY WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    BLOK_DEBUG_CONSOLE_OPEN();

    blokProgramInitialise(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
    blokStoreInitialise();
    struct WindowWrapper windowWrapper = blokWindowNew();

    blokWindowFree(&windowWrapper.optionalInstance.actualInstance);
    blokStoreFree();
    blokProgramFree();
    
    BLOK_DEBUG_CONSOLE_CLOSE();
}
