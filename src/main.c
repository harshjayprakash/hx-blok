#include <Windows.h>
#include "core/program.h"
#include "presentation/window.h"

int APIENTRY WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    blokProgramInitialise(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
    struct WindowWrapper windowWrapper = blokWindowNew();
    blokWindowFree(&windowWrapper.optionalInstance.actualInstance);
    blokProgramFree();
}
