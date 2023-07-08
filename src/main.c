#include <Windows.h>
#include "core/program.h"

int APIENTRY WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    blokProgramInitialise(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
    blokProgramFree();
}
