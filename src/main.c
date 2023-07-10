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
 * @details The following tasks are executed:
 *          - Starts a console to view debugging information
 *          - Initialises the program handles store
 *          - Initialises the program's standard globals store.
 *          - Creates, initialises and runs the main window.
 *          - Then cleans up any resources used when the window is terminated.
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
