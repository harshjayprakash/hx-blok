#include "window.h"
#include "../colour/theme.h"
#include "../../core/program.h"
#include <windef.h>
#include <windows.h>
#include <wingdi.h>
#include "../components/canvas.h"
#include "../components/panel.h"
#include "../events/handler.h"

static HWND mWindowHandle = { 0 };
static MSG mMessage = { 0 };
static WNDCLASSEXW mClass = { 0 };
static wchar_t mClassName[] = L"_NeonWindowClass";
static RECT mWindowArea = { 0 };

static long long __stdcall _NeonWindowEventHandler(
    HWND inWindowHandle, UINT inMessage, WPARAM inWordParam, LPARAM inLongParam)
{
    PAINTSTRUCT paintStructure;
    HDC displayContext;

    switch (inMessage)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
            displayContext = BeginPaint(inWindowHandle, &paintStructure);
            NeonHandlePaintEvent(inWindowHandle, displayContext);
            (void) EndPaint(inWindowHandle, &paintStructure);
            return 0;
        case WM_SIZE:
            (void) GetClientRect(inWindowHandle, &mWindowArea);
            return 0;
        case WM_LBUTTONDOWN:
            NeonHandleLeftMouseButton(inLongParam);
            (void) InvalidateRect(inWindowHandle, NULL, TRUE);
            return 0;
        case WM_KEYDOWN:
            NeonHandleKeyDownEvent(inWordParam);
            (void) InvalidateRect(inWindowHandle, NULL, TRUE);
            return 0;
        default:
            return DefWindowProc(inWindowHandle, inMessage, inWordParam, inLongParam);
    }
}

static int _NeonWindowMessageLoop(void)
{
    while (GetMessageW(&mMessage, NULL, 0, 0))
    {
        (void) TranslateMessage(&mMessage);
        (void) DispatchMessage(&mMessage);
    }
    
    return (int) mMessage.wParam;
}

static int _NeonCreateWindow(void)
{
    mWindowHandle = CreateWindowExW(
        WS_EX_OVERLAPPEDWINDOW,
        mClassName,
        L"The Experimental Block Project (Neon) v24.10 - Technical Preview",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL,
        NeonGetInstanceHandle(),
        NULL
    );
    
    if (!mWindowHandle)
    {
        return 1;
    }
    
    return 0;
}

static int _NeonRegisterWindowClass(void)
{
    mClass.cbSize = sizeof(WNDCLASSEXW);
    mClass.style = CS_HREDRAW | CS_VREDRAW;
    mClass.lpfnWndProc = _NeonWindowEventHandler;
    mClass.cbClsExtra = 0;
    mClass.cbWndExtra = 0;
    mClass.hInstance = NeonGetInstanceHandle();
    mClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    mClass.hIcon = LoadIcon(NeonGetInstanceHandle(), IDI_APPLICATION);
    // mClass.hIcon = (HICON) LoadImageW(
    //     NULL, L"program_icon.ico",
    //     IMAGE_ICON, 0, 0,
    //     LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED
    // );
    mClass.hIconSm = LoadIcon(NeonGetInstanceHandle(), IDI_APPLICATION);
    mClass.hbrBackground = CreateSolidBrush(NeonGetBackgroundColour());
    mClass.lpszMenuName = NULL;
    mClass.lpszClassName = mClassName;
    
    int registrationSucessful = RegisterClassExW(&mClass);
    
    if (!registrationSucessful)
    {
        return 1;
    }
    
    return 0;
}

void NeonInitWindow(void)
{
    int failed = _NeonRegisterWindowClass();
    if (failed) { NeonFreeWindow(); return; }
    
    failed = _NeonCreateWindow();
    if (failed) { NeonFreeWindow(); return; }

    NeonInitCanvas();
    
    (void) ShowWindow(mWindowHandle, NeonGetShowFlag());
    (void) UpdateWindow(mWindowHandle);
    
    (void) _NeonWindowMessageLoop();
}

void NeonFreeWindow(void)
{
    (void) UnregisterClassW(mClassName, NeonGetInstanceHandle());
    
    if (mClass.hIcon) { (void) DestroyIcon(mClass.hIcon); }
    if (mClass.hIconSm) { (void) DestroyIcon(mClass.hIconSm); }
    if (mClass.hCursor) { (void) DestroyCursor(mClass.hCursor); }
    if (mClass.hbrBackground) { (void) DeleteObject(mClass.hbrBackground); }
    if (mWindowHandle) { (void) DestroyWindow(mWindowHandle); }

    NeonFreeCanvas();
}

RECT NeonGetWindowArea(void)
{
    return mWindowArea;
}