#include <Windows.h>

#include "core/program.h"
#include "core/debug.h"
#include "presentation/window.h"
#include "logic/store.h"

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
