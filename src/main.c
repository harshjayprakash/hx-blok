#include <Windows.h>

int APIENTRY WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    blokProgramInitialise(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
    blokProgramFree();
}
