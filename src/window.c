#include "incl/window.h"

int Window_Init(Window* self, Application* app)
{
    self->xApp = app;
    if (Window_Register(self))
    {
        if (!Window_Create(self))
        {
            Window_Show(self);
            Window_Update(self);
            Window_MessageLoop(self);
        }
    }
    return 0;
}

int Window_Del(Window* self)
{
    UnregisterClass(self->clsName, self->xApp->hInst);
    if (self->wcex.hIcon != NULL) { DestroyIcon(self->wcex.hIcon); }
    if (self->wcex.hIconSm != NULL) { DestroyIcon(self->wcex.hIconSm); }
    if (self->wcex.hCursor != NULL) { DestroyCursor(self->wcex.hCursor); }
    if (self->wcex.hbrBackground != NULL) { DeleteObject(self->wcex.hbrBackground); }
    if (self->hWnd != NULL) { DestroyWindow(self->hWnd); }
    return 0;
}

int Window_Register(Window* self)
{
    _tcsncpy(self->clsName, _T("BlokWindowClass"), 260);

    self->wcex.cbSize = sizeof(WNDCLASSEX);
    self->wcex.style = CS_HREDRAW | CS_VREDRAW;
    self->wcex.lpfnWndProc = Window_Callback;
    self->wcex.cbClsExtra = 0;
    self->wcex.cbWndExtra = 0;
    self->wcex.hInstance = self->xApp->hInst;
    self->wcex.hIcon = LoadIcon(self->wcex.hInstance, IDI_APPLICATION);
    self->wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    self->wcex.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    self->wcex.lpszMenuName = NULL;
    self->wcex.lpszClassName = self->clsName;
    self->wcex.hIconSm = LoadIcon(self->wcex.hInstance, IDI_APPLICATION);

    return RegisterClassEx(&self->wcex);
}

int Window_Create(Window* self)
{
    self->hWnd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        self->clsName,
        _T("Main Window"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL,
        NULL,
        self->xApp->hInst,
        NULL
    );

    if (!self->hWnd)
        return 1;
    return 0;
}


void Window_Show(Window* self)
{
    ShowWindow(self->hWnd, self->xApp->nShow);
}

void Window_Update(Window* self)
{
    UpdateWindow(self->hWnd);
}

int Window_MessageLoop(Window* self)
{
    MSG uMsg;
    while (GetMessage(&uMsg, NULL, 0, 0))
    {
        TranslateMessage(&uMsg);
        DispatchMessage(&uMsg);
        Window_OnRun(self->hWnd, uMsg);
    }
    return (int) uMsg.wParam;
}

LONG_PTR __stdcall Window_Callback(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY: return Window_OnDestroy(hWnd, wParam, lParam);
    case WM_PAINT: return Window_OnPaint(hWnd, wParam, lParam);
    case WM_KEYDOWN: return Window_OnKeyDown(hWnd, wParam, lParam);
    case WM_SIZE: return Window_OnSize(hWnd, wParam, lParam);
    case WM_LBUTTONUP: return Window_OnLeftMouseUp(hWnd, wParam, lParam);
    case WM_ERASEBKGND: return Window_OnEraseBackground(hWnd, wParam, lParam);
    case WM_TIMER: return Window_OnTimerTick(hWnd, wParam, lParam);
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}