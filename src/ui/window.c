#include "window.h"
#include <stdio.h>

static int blokWindowEventLeftMouseDown(HWND windowHandle, WPARAM wordParam, LPARAM longParam)
{
    struct TSquare sq = blokStoreGet()->movableSquare;
    int posx = (LOWORD(longParam) / sq.size.width) * sq.size.width;
    int posy = (HIWORD(longParam) / sq.size.height) * sq.size.height;

    struct TPosition pos = blokPositionNew(posx, posy);

    if (blokVectorExists(&blokStoreGet()->markedRegions, pos) == BLOK_OBJ_EXISTS)
    {
        return BLOK_SUCCESS;
    }

    (void) blokVectorPush(&blokStoreGet()->markedRegions, pos);
    (void) InvalidateRect(windowHandle, NULL, TRUE);

    return BLOK_SUCCESS;
}

static enum TResult blokWindowEventKeyPressed(
    HWND windowHandle, WPARAM wordParam, LPARAM longParam)
{
    enum TCompass directionToMove;

    switch (wordParam)
    {
    case VK_UP:
        directionToMove = BLOK_DIRECTION_NORTH;
        break;
    case VK_RIGHT:
        directionToMove = BLOK_DIRECTION_EAST;
        break;
    case VK_DOWN:
        directionToMove = BLOK_DIRECTION_SOUTH;
        break;
    case VK_LEFT:
        directionToMove = BLOK_DIRECTION_WEST;
        break;
    default:
        return BLOK_FAILURE;
    }

    blokSquareCopy(
        &(blokStoreGet()->movableSquare),
        &(blokStoreGet()->projectedSquare)); 

    blokSquareMove(&blokStoreGet()->projectedSquare, directionToMove);

    struct TPosition position = { 
        blokStoreGet()->projectedSquare.pos.x,
        blokStoreGet()->projectedSquare.pos.y };

    if ((blokVectorExists(
            &(blokStoreGet()->markedRegions), 
            position)) == BLOK_OBJ_EXISTS)
    {
        return BLOK_SUCCESS;
    }

    blokSquareCopy(
        &(blokStoreGet()->projectedSquare), 
        &(blokStoreGet()->movableSquare));
    
    (void) InvalidateRect(windowHandle, NULL, TRUE);

    return BLOK_SUCCESS;
}

static long long blokWindowEventOnResize(
    HWND windowHandle, WPARAM wordParam, LPARAM longParam)
{
    RECT windowSize = { };

    (void) GetClientRect(windowHandle, &windowSize);

    blokSquareBoundarySet(
        &(blokStoreGet()->movableSquare), 
        blokDimensionNew(
            windowSize.right - blokStoreGet()->movableSquare.size.width, 
            windowSize.bottom - blokStoreGet()->movableSquare.size.height));

    blokSquareCopy(
        &(blokStoreGet()->movableSquare),
        &(blokStoreGet()->projectedSquare)); 

    return DefWindowProcW(windowHandle, WM_SIZE, wordParam, longParam);
}

static int blokWindowWhileRunning(HWND windowHandle)
{
    HDC deviceContextHandle = GetDC(windowHandle);
    HBRUSH foregroundBrushHandle = CreateSolidBrush(blokColourForegroundGet());
    HBRUSH markBrushHandle = CreateSolidBrush(blokColourMarkGet());
    RECT windowSize = { };
    RECT squareToPaint = blokCastSquareToWinApiRect(
        &(blokStoreGet()->movableSquare));
    wchar_t squareCoordinate[260];
    struct TVector *marks = &(blokStoreGet()->markedRegions);

    (void) _snwprintf_s(
        squareCoordinate, 260, 260, 
        L"( X: %d, Y: %d )", 
        blokStoreGet()->movableSquare.pos.x, 
        blokStoreGet()->movableSquare.pos.y);
    (void) GetClientRect(windowHandle, &windowSize);

    (void) SelectObject(deviceContextHandle, markBrushHandle);
    for (int i = 0; i < marks->max; i++)
    {
        struct TPosition *region = ((*marks).arr + i);
        
        if (region->x == -1 && region->y == -1)
        {
            continue;
        }

        RECT markToPaint = { 
            region->x, region->y, 
            (region->x + blokStoreGet()->movableSquare.size.width), 
            (region->y + blokStoreGet()->movableSquare.size.height) };
        (void)FillRect(deviceContextHandle, &markToPaint, markBrushHandle);
    }

    (void) SelectObject(deviceContextHandle, foregroundBrushHandle);
    (void) FillRect(deviceContextHandle, &squareToPaint, foregroundBrushHandle);
    (void) SetTextColor(deviceContextHandle, blokColourForegroundGet());
    (void) SetBkColor(deviceContextHandle, blokColourBackgroundGet());
    (void) TextOutW(
        deviceContextHandle, 10, (windowSize.bottom - windowSize.top) - 25, 
        squareCoordinate, (int) wcslen(squareCoordinate));

    (void) DeleteObject(foregroundBrushHandle);
    (void) DeleteObject(markBrushHandle);
    (void) ReleaseDC(windowHandle, deviceContextHandle);

    return BLOK_SUCCESS;
}


static long long blokWindowCallback(
    HWND windowHandle, UINT message, WPARAM wordParam, LPARAM longParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return (unsigned long long) BLOK_SUCCESS;
    case WM_KEYDOWN:
        return blokWindowEventKeyPressed(windowHandle, wordParam, longParam);
    case WM_LBUTTONDOWN:
        return blokWindowEventLeftMouseDown(windowHandle, wordParam, longParam);
    case WM_SIZE:
        return blokWindowEventOnResize(windowHandle, wordParam, longParam);
    default:
        return DefWindowProcW(windowHandle, message, wordParam, longParam);
    }
}

static int blokWindowMessageLoop(struct TNativeWindow *ntwnd)
{
    if (!ntwnd)
    {
        return BLOK_NULLPTR_ERROR;
    }

    while (GetMessageW(&ntwnd->message, NULL, 0, 0))
    {
        (void) TranslateMessage(&ntwnd->message);
        (void) DispatchMessageW(&ntwnd->message);
        (void) blokWindowWhileRunning(ntwnd->handle);
    }

    return (int) ntwnd->message.wParam;
}

static enum TResult blokWindowCreate(struct TNativeWindow* ntwnd)
{
    if (!ntwnd)
    {
        return BLOK_NULLPTR_ERROR;
    }

    ntwnd->handle = CreateWindowExW(
        WS_EX_OVERLAPPEDWINDOW,
        ntwnd->name,
        L"The Experimental Block Project",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL,
        blokProgramInstanceGet()->pArgs->instanceHandle,
        NULL
    );

    if (!ntwnd->handle)
    {
        return BLOK_WND_CREATION_ERROR;
    }

    return BLOK_SUCCESS;
}

static enum TResult blokWindowRegister(struct TNativeWindow* ntwnd)
{
    if (!ntwnd)
    {
        return BLOK_NULLPTR_ERROR;
    }

    (void) wcsncpy_s(ntwnd->name, 260, L"blokWindowClass", 260);

    ntwnd->clazz = (WNDCLASSEXW) {
        .cbSize = sizeof(WNDCLASSEXW),
        .style = CS_HREDRAW | CS_VREDRAW,
        .lpfnWndProc = blokWindowCallback,
        .cbClsExtra = 0,
        .cbWndExtra = 0,
        .hInstance = blokProgramInstanceGet()->pArgs->instanceHandle,
        .hIcon = LoadIcon(
            blokProgramInstanceGet()->pArgs->instanceHandle, IDI_APPLICATION),
        .hCursor = LoadCursor(NULL, IDC_ARROW),
        .hbrBackground = CreateSolidBrush(blokColourBackgroundGet()),
        .lpszMenuName = NULL,
        .lpszClassName = ntwnd->name,
        .hIconSm = LoadIcon(
            blokProgramInstanceGet()->pArgs->instanceHandle, IDI_APPLICATION)
    };

    int success = RegisterClassExW(&ntwnd->clazz);

    if (!success)
    {
        return BLOK_WND_REGISTRATION_ERROR;
    }

    return BLOK_SUCCESS;
}

struct TWindow blokWindowNew(void)
{
    struct TWindow wnd = {
        .registered = 0,
        .created = 0,
        .present = 0,
        .inst = { }
    };

    int result = 0;

    result = blokWindowRegister(&wnd.inst);
    if (result == BLOK_WND_REGISTRATION_ERROR)
    {
        blokWindowFree(&wnd);
        return wnd;
    }
    wnd.registered = 1;

    result = blokWindowCreate(&wnd.inst);
    if (result == BLOK_WND_CREATION_ERROR)
    {
        blokWindowFree(&wnd);
        return wnd;
    }
    wnd.created = 1;

    ShowWindow(wnd.inst.handle, blokProgramInstanceGet()->pArgs->showFlag);
    UpdateWindow(wnd.inst.handle);

    blokWindowMessageLoop(&wnd.inst);
    wnd.present = 1;

    return wnd;
}

void blokWindowFree(struct TWindow *wnd)
{
    if (!wnd)
    {
        return;
    }

    (void) UnregisterClassW(
        wnd->inst.name, blokProgramInstanceGet()->pArgs->instanceHandle);
    
    if (wnd->inst.clazz.hIcon)
    {
        (void) DestroyIcon(wnd->inst.clazz.hIcon);
    }

    if (wnd->inst.clazz.hIconSm)
    {
        (void) DestroyIcon(wnd->inst.clazz.hIconSm);
    }

    if (wnd->inst.clazz.hCursor)
    {
        (void) DestroyCursor(wnd->inst.clazz.hCursor);
    }

    if (wnd->inst.clazz.hbrBackground)
    {
        (void) DeleteObject(wnd->inst.clazz.hbrBackground);
    }

    if (wnd->inst.handle)
    {
        (void) DestroyWindow(wnd->inst.handle);
    }
}