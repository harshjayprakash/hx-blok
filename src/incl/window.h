#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <tchar.h>
#include <wingdi.h>

#include "app.h"
#include "window_events.h"

typedef struct Window
{
    Application* xApp;
    HWND hWnd;
    TCHAR clsName[260];
    WNDCLASSEX wcex;
} Window;

int Window_Init(Window* self, Application* app);
int Window_Del(Window* self);
int Window_Register(Window* self);
int Window_Create(Window* self);
void Window_Show(Window* self);
void Window_Update(Window* self);
int Window_MessageLoop(Window* self);
LONG_PTR __stdcall Window_Callback(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


#endif