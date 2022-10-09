#ifndef APP_H
#define APP_H

#include <windows.h>

typedef struct Application
{
    HINSTANCE hInst;
    HINSTANCE hPrevInst;
    LPSTR lpCmdline;
    INT nShow;
} Application;

void Application_Init(
    Application* self, HINSTANCE hInst, HINSTANCE hPrevInst,
    LPSTR lpCmdline, INT nShow);
void Application_Del(Application* self);

#endif // APP_H