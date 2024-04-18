#include "pane.h"
#include "../../core/interface/program.h"
#include <Windows.h>
#include <errhandlingapi.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <windef.h>
#include <wingdi.h>

static long long bloqPaneCallback(
    HWND windowHandle, UINT message, WPARAM wordParam, LPARAM longParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        {
            PAINTSTRUCT paintStruct;
            HDC hdc = BeginPaint(windowHandle, &paintStruct);

            wchar_t coordinateText[50] = L"X: -, Y: -";
            wchar_t clearButton[16] = L"[ Reset Walls ]";
            wchar_t resetBloq[17] = L"[ Reset Square ]";
            wchar_t lockState[40] = L"[ State: Unlocked ]";

            RECT windowSize = { 0 };
            GetClientRect(windowHandle, &windowSize);

            windowSize.top = (windowSize.bottom - 40);
            windowSize.bottom = (windowSize.top + 5);
            
            SetBkColor(hdc, RGB(0, 0, 0));
            SetTextColor(hdc, RGB(255, 255, 255));
            Rectangle(hdc, windowSize.left, windowSize.top, windowSize.right, windowSize.bottom);

            TextOutW(hdc, windowSize.left + 10, windowSize.bottom + 10, coordinateText, 50);

            TextOutW(hdc, windowSize.left + 300, windowSize.bottom + 10, clearButton, 16);
            TextOutW(hdc, windowSize.left + 450, windowSize.bottom + 10, resetBloq, 17);

            TextOutW(hdc, windowSize.left + 600, windowSize.bottom + 10, lockState, 40);

            EndPaint(windowHandle, &paintStruct);
        }
        return 0;
    default:
        return DefWindowProcW(windowHandle, message, wordParam, longParam);
    }
}

static void bloqMessageLoop(TPane *pane)
{
    if (!pane) { return; }

    while (GetMessageW(&pane->message, NULL, 0, 0))
    {
        (void) TranslateMessage(&pane->message);
        (void) DispatchMessageW(&pane->message);
    }
}

static void bloqCreatePane(TPane *pane)
{
    if (!pane) { return; }

    pane->handle = CreateWindowExW(
        WS_EX_OVERLAPPEDWINDOW,
        pane->name,
        L"The Experimental Block Project 2408.1",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL,
        bloqGetInstanceHandle(),
        NULL
    );

    if (!pane->handle) { pane->initError = 0x00000100; }
}

static void bloqRegisterPane(TPane *pane)
{
    if (!pane) { return; }

    (void) wcsncpy_s(
        pane->name, bloqMaxStringLength, 
        L"bloqPane", bloqMaxStringLength
    );

    pane->klass = (WNDCLASSEXW) {
        .cbSize = sizeof(WNDCLASSEX),
        .style = CS_HREDRAW | CS_VREDRAW,
        .lpfnWndProc = bloqPaneCallback,
        .cbClsExtra = 0,
        .cbWndExtra = 0,
        .hInstance = bloqGetInstanceHandle(),
        .hIcon = LoadIcon(bloqGetInstanceHandle(), IDI_APPLICATION),
        .hCursor = LoadCursor(NULL, IDC_ARROW),
        .hbrBackground = CreateSolidBrush(RGB(0, 0, 0)),
        .lpszMenuName = NULL,
        .lpszClassName = pane->name,
        .hIconSm = LoadIcon(bloqGetInstanceHandle(), IDI_APPLICATION)
    };

    int result = RegisterClassExW(&pane->klass);
    if (!result) { pane->initError = 0x0000010; }
}

TPane bloqInitPane(void)
{
    TPane pane = { 0 };

    pane.name = calloc(bloqMaxStringLength, sizeof(wchar_t));
    if (!pane.name) { goto bloqPaneErrorCleanUp; }

    bloqRegisterPane(&pane);
    if (pane.initError) { goto bloqPaneErrorCleanUp; }

    bloqCreatePane(&pane);
    if (pane.initError) { goto bloqPaneErrorCleanUp; }

    ShowWindow(pane.handle, bloqGetShowFlag());
    UpdateWindow(pane.handle);

    bloqMessageLoop(&pane);

    return pane;

bloqPaneErrorCleanUp:

    bloqFreePane(&pane);
    return (TPane) { 0 };
}

void bloqFreePane(TPane *pane)
{
    if (!pane) { return; }

    (void) UnregisterClassW(pane->name, bloqGetInstanceHandle());

    if (pane->name) { free(pane->name); }

    (void) DestroyIcon(pane->klass.hIcon);
    (void) DestroyIcon(pane->klass.hIconSm);
    (void) DestroyCursor(pane->klass.hCursor);
    (void) DeleteObject(pane->klass.hbrBackground);
    (void) DestroyWindow(pane->handle);
}