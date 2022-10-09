#include <stdio.h>
#include <windows.h>

#include "incl/app.h"
#include "incl/window.h"
#include "incl/block.h"
#include "incl/grid.h"
#include "incl/global.h"

extern Block g_plyr;
extern Grid g_map;

int __stdcall WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdline, INT nShow)
{
    Application app;
    Application_Init(&app, hInst, hPrevInst, lpCmdline, nShow);

    Block_Init(&g_plyr, 0, 0, 15, 15, RGB(255, 32, 100));
    Grid_Init(&g_map, 2048, 2048);

    Window wnd;
    Window_Init(&wnd, &app);

    Window_Del(&wnd);
    Grid_Del(&g_map);
    Block_Del(&g_plyr);
    Application_Del(&app);

    return 0;
}