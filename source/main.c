#include "core/program.h"
#include "core/result.h"
#include <windows.h>

int APIENTRY WinMain(
    HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    (void) hPrevInstance;
    (void) lpCmdLine;

    NeonInit(hInstance, nShowCmd);
    NeonStart();
    NeonFree();

    return (int) NeonSuccess;
}