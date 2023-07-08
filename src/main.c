#include <Windows.h>
#include "core/program.h"
#include "presentation/window.h"
#include "logic/store.h"

int APIENTRY WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    blokProgramInitialise(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
    blokStoreInitialise();
    struct WindowWrapper windowWrapper = blokWindowNew();

    blokWindowFree(&windowWrapper.optionalInstance.actualInstance);
    blokStoreFree();
    blokProgramFree();
}
