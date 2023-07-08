#include "debug.h"

static FILE *consoleIn;
static FILE *consoleOut;
static FILE *consoleErr;

void blokDebugConsoleOpen()
{
    consoleIn = stdin;
    consoleOut = stdout;
    consoleErr = stderr;
    AllocConsole();
    AttachConsole(GetCurrentProcessId());
    freopen_s(&consoleIn, "CONIN$", "r", stdin);
    freopen_s(&consoleOut, "CONOUT$", "w", stdout);
    freopen_s(&consoleErr, "CONOUT$", "w", stderr);
    SetConsoleTitleW(L"The Blok Experiment Console");
    printf("======= THE BLOCK EXPERIMENT DEBUGGING MECHANISM =======\n");
}

void blokDebugConsoleClose()
{
    fclose(consoleIn);
    fclose(consoleOut);
    fclose(consoleErr);
    FreeConsole();
}

void blokDebugConsoleLog(const char *message)
{
    printf("%s\n", message);
}
