#include "window.h"

static int blokWindowActionLeftMouseDown(
    HWND windowHandle, WPARAM wordParam, LPARAM longParam)
{
    struct Square square = blokStoreInstanceGet()->movableSquare;
    int positionX = (LOWORD(longParam) / square.width ) * square.width;
    int positionY = (HIWORD(longParam) / square.height ) * square.height;

    printf("(%d, %d)\n", positionX, positionY);

    blokVectorPush(
        &(blokStoreInstanceGet()->markedRegions), blokMarkNew(positionX, positionY));

    (void)InvalidateRect(windowHandle, NULL, TRUE);

    return BLOK_SUCCESSFUL_OPERATION;
}

static int blokWindowActionKeyPressed(
    HWND windowHandle, WPARAM wordParam, LPARAM longParam)
{
    switch (wordParam)
    {
    case VK_UP:
        blokSquareMove(&(blokStoreInstanceGet()->movableSquare), DirectionNorth);
        break;
    case VK_RIGHT:
        blokSquareMove(&(blokStoreInstanceGet()->movableSquare), DirectionEast);
        break;
    case VK_DOWN:
        blokSquareMove(&(blokStoreInstanceGet()->movableSquare), DirectionSouth);
        break;
    case VK_LEFT:
        blokSquareMove(&(blokStoreInstanceGet()->movableSquare), DirectionWest);
        break;
    default:
        return (-1);
    }
    
    (void)InvalidateRect(windowHandle, NULL, TRUE);

    return BLOK_SUCCESSFUL_OPERATION;
}

static int blokWindowWhileRunning(HWND windowHandle)
{
    HDC deviceContextHandle = GetDC(windowHandle);
    HBRUSH foregroundBrushHandle = CreateSolidBrush(blokColourForegroundGet());
    HBRUSH markBrushHandle = CreateSolidBrush(blokColourMarkGet());
    RECT windowSize = { };
    RECT squareToPaint = blokCastSquareToWinApiRect(
        &(blokStoreInstanceGet()->movableSquare));
    wchar_t squareCoordinate[BLOK_MAX_CHAR_LENGTH];
    struct Vector *marks = &(blokStoreInstanceGet()->markedRegions);

    (void)_snwprintf_s(
        squareCoordinate, BLOK_MAX_CHAR_LENGTH, BLOK_MAX_CHAR_LENGTH, 
        L"( X: %d, Y: %d )", 
        blokStoreInstanceGet()->movableSquare.positionX, 
        blokStoreInstanceGet()->movableSquare.positionY);
    (void)GetClientRect(windowHandle, &windowSize);

    (void)SelectObject(deviceContextHandle, markBrushHandle);
    for (int i = 0; i < marks->max; i++)
    {
        struct Mark *region = ((*marks).arr + i);
        
        if (region->positionX == -1 && region->positionY == -1)
        {
            continue;
        }

        RECT markToPaint = { 
            region->positionX, region->positionY, 
            (region->positionX + blokStoreInstanceGet()->movableSquare.width), 
            (region->positionY + blokStoreInstanceGet()->movableSquare.height) };
        (void)FillRect(deviceContextHandle, &markToPaint, markBrushHandle);
    }

    (void)SelectObject(deviceContextHandle, foregroundBrushHandle);
    (void)FillRect(deviceContextHandle, &squareToPaint, foregroundBrushHandle);
    (void)SetTextColor(deviceContextHandle, blokColourForegroundGet());
    (void)SetBkColor(deviceContextHandle, blokColourBackgroundGet());
    (void)TextOutW(
        deviceContextHandle, 10, (windowSize.bottom - windowSize.top) - 25, 
        squareCoordinate, (int)wcslen(squareCoordinate));

    (void)DeleteObject(foregroundBrushHandle);
    (void)DeleteObject(markBrushHandle);
    (void)ReleaseDC(windowHandle, deviceContextHandle);

    return BLOK_SUCCESSFUL_OPERATION;
}

static long long blokWindowCallbackProcedure(
    HWND windowHandle, UINT message, WPARAM wordParam, LPARAM longParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return BLOK_SUCCESSFUL_OPERATION;
    case WM_KEYDOWN:
        return blokWindowActionKeyPressed(windowHandle, wordParam, longParam);
    case WM_LBUTTONDOWN:
        return blokWindowActionLeftMouseDown(windowHandle, wordParam, longParam);
    default:
        return DefWindowProcW(windowHandle, message, wordParam, longParam);
    }
}

static int blokWindowMessageLoop(struct Window *window)
{
    if (!window)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    while (GetMessageW(&window->windowMessage, NULL, 0, 0))
    {
        (void)TranslateMessage(&window->windowMessage);
        (void)DispatchMessageW(&window->windowMessage);
        (void)blokWindowWhileRunning(window->windowHandle);
    }

    return (int)window->windowMessage.wParam;
}

static unsigned short blokWindowRegister(struct Window *window)
{
    if (!window)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    (void)wcsncpy_s(
        window->windowClassName, BLOK_MAX_CHAR_LENGTH, 
        L"blokWindowClass", BLOK_MAX_CHAR_LENGTH);

    window->nativeWindowClass.cbSize = sizeof(WNDCLASSEXW);
    window->nativeWindowClass.style = CS_HREDRAW | CS_VREDRAW;
    window->nativeWindowClass.lpfnWndProc = blokWindowCallbackProcedure;
    window->nativeWindowClass.cbClsExtra = 0;
    window->nativeWindowClass.cbWndExtra = 0;
    window->nativeWindowClass.hInstance = blokProgramInstanceGet()->instanceHandle;
    window->nativeWindowClass.hIcon = LoadIcon(
        window->nativeWindowClass.hInstance, IDI_APPLICATION);
    window->nativeWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    window->nativeWindowClass.hbrBackground = CreateSolidBrush(blokColourBackgroundGet());
    window->nativeWindowClass.lpszMenuName = NULL;
    window->nativeWindowClass.lpszClassName = window->windowClassName;
    window->nativeWindowClass.hIconSm = LoadIcon(
        window->nativeWindowClass.hInstance, IDI_APPLICATION);
    
    return RegisterClassExW(&window->nativeWindowClass);
}

static int blokWindowCreate(struct Window *window)
{
    if (!window)
    {
        return BLOK_ERROR_NULL_POINTER;
    }

    window->windowHandle = CreateWindowExW(
        WS_EX_OVERLAPPEDWINDOW, window->windowClassName, 
        L"The Experimental Block Project", WS_OVERLAPPEDWINDOW, 
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, 
        blokProgramInstanceGet()->instanceHandle, NULL);
    
    if (!window->windowHandle)
    {
        return BLOK_ERROR_WINDOW_CREATION;
    }

    return BLOK_SUCCESSFUL_OPERATION;
}

struct WindowWrapper blokWindowNew(void)
{
    struct WindowWrapper optionalWindow = { 0, 0, 0, { } };
    struct Window window;
    int result = 0;

    result = blokWindowRegister(&window);
    if (result == BLOK_ERROR_WINDOW_REGISTRATION)
    {
        blokWindowFree(&window);
        return optionalWindow;
    }
    optionalWindow.registered = 1;

    result = blokWindowCreate(&window);
    if (result == BLOK_ERROR_WINDOW_CREATION)
    {
        blokWindowFree(&window);
        return optionalWindow;
    }
    optionalWindow.created = 1;

    ShowWindow(window.windowHandle, blokProgramInstanceGet()->showFlag);
    UpdateWindow(window.windowHandle);

    blokWindowMessageLoop(&window);
    optionalWindow.present = 1;
    optionalWindow.instance = window;

    return optionalWindow;
}

void blokWindowFree(struct Window *window)
{
    if (!window)
    {
        return;
    }

    (void)UnregisterClassW(
        window->windowClassName, blokProgramInstanceGet()->instanceHandle);

    BLOK_FREE_IF_NOT_NULL(window->nativeWindowClass.hIcon, (void)DestroyIcon);
    BLOK_FREE_IF_NOT_NULL(window->nativeWindowClass.hIconSm, (void)DestroyIcon);
    BLOK_FREE_IF_NOT_NULL(window->nativeWindowClass.hCursor, (void)DestroyCursor);
    BLOK_FREE_IF_NOT_NULL(window->nativeWindowClass.hbrBackground, (void)DeleteObject);
    BLOK_FREE_IF_NOT_NULL(window->windowHandle, (void)DestroyWindow);
}
