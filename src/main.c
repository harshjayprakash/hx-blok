#include <Windows.h>
#include "core/args.h"
#include "core/program.h"
#include "core/result.h"
#include "ui/window.h"

int APIENTRY WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    struct TArgs args = (struct TArgs) { 
        .instanceHandle = hInstance,
        .previousInstanceHandle = hPrevInstance,
        .commandLine = lpCmdLine,
        .showFlag = nShowCmd
    };

    blokProgramInit(&args);
    blokProgramProcessArguments(&args);
    blokStoreInit();
    struct TWindow wnd = blokWindowNew();
    blokWindowFree(&wnd);
    blokStoreFree();
    blokProgramFree();

    return (int) BLOK_SUCCESS;
}