/**
 * \file window.c
 * \date 13-08-2024
 * \brief Function implementation for the Window.
 *
 * This file contains the implementation for the graphical window.
 */

#define STRICT 1
#include "window.h"
#include "../core/log.h"
#include "../core/program.h"
#include "../core/result.h"
#include "components/canvas.h"
#include "components/panel.h"
#include "events/handler.h"
#include "graphics/drawing.h"
#include "graphics/theme.h"
#include "objects/block.h"

#include <Windows.h>
#include <wchar.h>
#include <wingdi.h>

static HWND mWindow = {0};
static MSG mMessage = {0};
static WNDCLASSEXW mClass = {0};
static wchar_t mName[] = L"__NeonBlockWindowClass";
static wchar_t mCaption[] = L"Blok";
static RECT mWindowArea = {0};
static int mWindowHeight = 0;
static int mWindowWidth = 0;
static int mRunning = 0;

static long long __NeonProcedure(HWND windowHandle, UINT message, WPARAM wordParam,
                                LPARAM longParam)
{
    PAINTSTRUCT paint;
    HDC displayContext;

    switch (message)
    {
    case WM_CREATE:
        (void)GetClientRect(windowHandle, &mWindowArea);
        return 0;
    case WM_DESTROY:
        mRunning = 0;
        PostQuitMessage(0);
        return 0;
    case WM_PAINT: {
        displayContext = BeginPaint(mWindow, &paint);
        HDC bufferedContext = CreateCompatibleDC(displayContext);
        HBITMAP bitmapMemory =
            CreateCompatibleBitmap(displayContext, mWindowWidth, mWindowHeight);
        (void)SelectObject(bufferedContext, bitmapMemory);
        (void)FillRect(bufferedContext, &mWindowArea, NeonGetBackgroundBrush());
        NeonHandleWindowPaintEvent(bufferedContext);
        (void)BitBlt(displayContext, 0, 0, mWindowWidth, mWindowHeight, bufferedContext,
                     0, 0, SRCCOPY);
        (void)DeleteObject(bitmapMemory);
        (void)DeleteObject(bufferedContext);
        (void)EndPaint(windowHandle, &paint);
        return 0;
    }
    case WM_SIZE:
        (void)GetClientRect(windowHandle, &mWindowArea);
        mWindowWidth = mWindowArea.right;
        mWindowHeight = mWindowArea.bottom;
        NeonSetBlockBoundary(NeonCreateSize(mWindowWidth, mWindowHeight));
        NeonUpdatePanelSize();
        return 0;
    case WM_LBUTTONDOWN:
        NeonHandleWindowLeftMouseDown(longParam);
        return 0;
    case WM_KEYDOWN:
        NeonHandleWindowKeyDownEvent(wordParam);
        return 0;
    default:
        return DefWindowProcW(windowHandle, message, wordParam, longParam);
    }
}

static int __NeonMessageLoop(void)
{
    while (GetMessageW(&mMessage, NULL, 0, 0)) 
    {
        (void)TranslateMessage(&mMessage);
        (void)DispatchMessageW(&mMessage);
    }

    return (int)mMessage.wParam;
}

static NeonResult __NeonCreateWindow(void)
{
    mWindow = CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, mName, mCaption,
                              WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
                              NULL, NULL, NeonGetHandle(), NULL);

    if (!mWindow)
    {
        return NeonLogAndReturn(NeonError,
                                NeonCreateResult(NeonFail, L"Window Creation Failed."));
    }

    return NeonLogAndReturn(NeonInformation,
                            NeonCreateResult(NeonSuccess, L"Created Window."));
}

static NeonResult __NeonRegisterWindow(void)
{
    mClass.cbSize = sizeof(WNDCLASSEXW);
    mClass.style = CS_HREDRAW | CS_VREDRAW;
    mClass.lpfnWndProc = __NeonProcedure;
    mClass.cbClsExtra = 0;
    mClass.cbWndExtra = 0;
    mClass.hInstance = NeonGetHandle();
    mClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
    mClass.hIcon = LoadIconW(NeonGetHandle(), IDI_APPLICATION);
    mClass.hIconSm = LoadIconW(NeonGetHandle(), IDI_APPLICATION);
    mClass.hbrBackground = CreateSolidBrush(NeonGetBackgroundColour());
    mClass.lpszMenuName = NULL;
    mClass.lpszClassName = mName;

    int success = RegisterClassExW(&mClass);

    if (!success)
    {
        return NeonLogAndReturn(NeonError,
                                NeonCreateResult(NeonFail, L"Failed to Register Class."));
    }

    return NeonLogAndReturn(NeonInformation,
                            NeonCreateResult(NeonSuccess, L"Registered Window."));
}

NeonResult NeonInitWindow(void)
{
    NeonResult registerResult = __NeonRegisterWindow();
    if (registerResult.code == NeonFail)
    {
        (void)NeonFreeWindow();
        return NeonLogAndReturn(
            NeonError, NeonCreateResult(NeonFail, L"Window Initialisation Failed."));
    }

    NeonResult createResult = __NeonCreateWindow();
    if (createResult.code == NeonFail)
    {
        (void)NeonFreeWindow();
        return NeonLogAndReturn(
            NeonError, NeonCreateResult(NeonFail, L"Window Initialisation Failed."));
    }

    mRunning = 1;

    NeonInitPanelComponent();
    NeonInitCanvasComponent();

    (void)ShowWindow(mWindow, NeonGetShowFlag());
    (void)UpdateWindow(mWindow);
    (void)__NeonMessageLoop();

    return NeonCreateResult(NeonSuccess, L"Window Initialised.");
}

RECT NeonGetWindowArea(void)
{
    return mWindowArea;
}

HWND NeonGetWindowHandle(void)
{
    return mWindow;
}

NeonResult NeonFreeWindow(void)
{
    NeonFreePanelComponent();
    NeonFreeCanvasComponent();

    (void)UnregisterClassW(mName, NeonGetHandle());

    if (mClass.hIcon)
    {
        (void)DestroyIcon(mClass.hIcon);
    }

    if (mClass.hIconSm)
    {
        (void)DestroyIcon(mClass.hIconSm);
    }

    if (mClass.hCursor)
    {
        (void)DestroyCursor(mClass.hCursor);
    }

    if (mClass.hbrBackground)
    {
        (void)DeleteObject(mClass.hbrBackground);
    }

    if (mWindow)
    {
        (void)DestroyWindow(mWindow);
    }

    return NeonLogAndReturn(
        NeonInformation, NeonCreateResult(NeonSuccess, L"Cleaned Up Window Resources."));
}