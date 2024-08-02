#include "window.h"
#include "../colour/theme.h"
#include "../../core/program.h"
#include <windef.h>
#include <windows.h>
#include <wingdi.h>
#include "../components/block.h"
#include "../events/keyboard.h"
#include "../components/panel.h"

HWND mWindowHandle = { 0 };
MSG mMessage = { 0 };
WNDCLASSEXW mClass = { 0 };
wchar_t mClassName[] = L"_NeonWindowClass";

static long long __stdcall _NeonWindowEventHandler(
    HWND inWindowHandle, UINT inMessage, WPARAM inWordParam, LPARAM inLongParam)
{
    PAINTSTRUCT paintStructure;
    HDC displayContextHandle, OffScreenContextHandle;
    HBITMAP bitmapMemoryHandle;
    HBRUSH backgroundBrushHandle;
    HBRUSH foregroundBrushHandle;
    HBRUSH accentBrushHandle;
    HPEN foregroundPenHandle;
    RECT windowSize;

    switch (inMessage)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
            displayContextHandle = BeginPaint(inWindowHandle, &paintStructure);
            backgroundBrushHandle = CreateSolidBrush(NeonGetBackgroundColour());
            foregroundBrushHandle = CreateSolidBrush(NeonGetForegroundColour());
            accentBrushHandle = CreateSolidBrush(NeonGetAccentColour());
            foregroundPenHandle = CreatePen(PS_GEOMETRIC, 1, NeonGetForegroundColour());

            (void) GetClientRect(inWindowHandle, &windowSize);

            OffScreenContextHandle = CreateCompatibleDC(displayContextHandle);
            bitmapMemoryHandle = CreateCompatibleBitmap(displayContextHandle, windowSize.right, windowSize.bottom);
            (void) SelectObject(OffScreenContextHandle, bitmapMemoryHandle);
            (void) SetTextColor(OffScreenContextHandle, NeonGetForegroundColour());
            (void) SetBkColor(OffScreenContextHandle, NeonGetBackgroundColour());
            

            NeonRenderBlock(OffScreenContextHandle, accentBrushHandle);

            (void) SelectObject(OffScreenContextHandle, backgroundBrushHandle);
            (void) SelectObject(OffScreenContextHandle, foregroundPenHandle);
            NeonRenderPanel(OffScreenContextHandle, windowSize, backgroundBrushHandle, foregroundBrushHandle);

            (void) BitBlt(
                displayContextHandle, 0, 0, 
                windowSize.right, windowSize.bottom, 
                OffScreenContextHandle, 0, 0, SRCCOPY
            );

            (void) DeleteObject(bitmapMemoryHandle);
            (void) DeleteDC(OffScreenContextHandle);
            (void) DeleteObject(backgroundBrushHandle);
            (void) DeleteObject(foregroundBrushHandle);
            (void) DeleteObject(accentBrushHandle);
            (void) DeleteObject(foregroundPenHandle);
            (void) EndPaint(inWindowHandle, &paintStructure);
            return 0;
        case WM_KEYDOWN:
            NeonArrowsKeyboardEvent(inWordParam);
            (void) InvalidateRect(inWindowHandle, NULL, TRUE);
            return 0;
        default:
            return DefWindowProc(inWindowHandle, inMessage, inWordParam, inLongParam);
    }
}

static int _NeonWindowMessageLoop()
{
    while (GetMessageW(&mMessage, NULL, 0, 0))
    {
        (void) TranslateMessage(&mMessage);
        (void) DispatchMessage(&mMessage);
    }
    
    return (int) mMessage.wParam;
}

static int _NeonCreateWindow()
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

static int _NeonRegisterWindowClass()
{
    mClass.cbSize = sizeof(WNDCLASSEXW);
    mClass.style = CS_HREDRAW | CS_VREDRAW;
    mClass.lpfnWndProc = _NeonWindowEventHandler;
    mClass.cbClsExtra = 0;
    mClass.cbWndExtra = 0;
    mClass.hInstance = NeonGetInstanceHandle();
    mClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    mClass.hIcon = LoadIcon(NeonGetInstanceHandle(), IDI_APPLICATION);
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

void NeonInitWindow()
{
    int failed = _NeonRegisterWindowClass();
    if (failed) { NeonFreeWindow(); return; }
    
    failed = _NeonCreateWindow();
    if (failed) { NeonFreeWindow(); return; }

    NeonInitBlock();
    
    (void) ShowWindow(mWindowHandle, NeonGetShowFlag());
    (void) UpdateWindow(mWindowHandle);
    
    (void) _NeonWindowMessageLoop();
}

void NeonFreeWindow()
{
    (void) UnregisterClassW(mClassName, NeonGetInstanceHandle());
    
    if (mClass.hIcon) { (void) DestroyIcon(mClass.hIcon); }
    if (mClass.hIconSm) { (void) DestroyIcon(mClass.hIconSm); }
    if (mClass.hCursor) { (void) DestroyCursor(mClass.hCursor); }
    if (mClass.hbrBackground) { (void) DeleteObject(mClass.hbrBackground); }
    if (mWindowHandle) { (void) DestroyWindow(mWindowHandle); }
}