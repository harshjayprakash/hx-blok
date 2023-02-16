#include <stdio.h>
#include <windows.h>

#include "globals.h"
#include "app.h"
#include "block.h"
#include "grid.h"
#include "window.h"

/**
 * The entrypoint to the application. 
 * @param hInst: Handle to the instance of the application. Windows uses this 
 *      to identify the program executable when loaded in memory
 * @param hPrevInst: Used for 16-bit version of Windows. Not used in this
 *      application.
 * @param lpCmdline: Any command line arguments specified when running the
 *      program.
 * @param nShow: A flag used to specify how the application should be displayed.
*/
int __stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdline, INT nShow)
{
    Application app;
    Application_Init(&app, hInst, hPrevInst, lpCmdline, nShow);
    Block_Init(&g_user, 0, 0, 15, 15, RGB(255, 32, 100));

    Grid_Init(&g_map, 2048, 2048);
    Window wnd;
    Window_Init(&wnd, &app);

    Window_Del(&wnd);
    Grid_Del(&g_map);
    Block_Del(&g_user);
    Application_Del(&app);
    return 0;
}