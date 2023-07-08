#include "window.h"

static long long blokWindowCallbackProcedure(
    HWND windowHandle, UINT message, WPARAM wordParam, LPARAM longParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return BLOK_SUCCESSFUL_OPERATION;
    default:
        return DefWindowProcW(windowHandle, message, wordParam, longParam);
    }
}

static int blokWindowMessageLoop(struct Window *window)
{
    BLOK_NON_VOID_EXIT_IF(!window, BLOK_ERROR_NULL_POINTER);

    while (GetMessageW(&window->windowMessage, NULL, 0, 0))
    {
        (void)TranslateMessage(&window->windowMessage);
        (void)DispatchMessageW(&window->windowMessage);
    }

    return (int)window->windowMessage.wParam;
}
static unsigned short blokWindowRegister(struct Window *window)
{
    BLOK_NON_VOID_EXIT_IF(!window, BLOK_ERROR_NULL_POINTER);

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
    BLOK_NON_VOID_EXIT_IF(!window, BLOK_ERROR_NULL_POINTER);

    window->windowHandle = CreateWindowExW(
        WS_EX_OVERLAPPEDWINDOW, window->windowClassName, 
        L"The Experimental Block Project", WS_OVERLAPPEDWINDOW, 
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, 
        blokProgramInstanceGet()->instanceHandle, NULL);
    
    BLOK_NON_VOID_EXIT_IF(!window->windowHandle, BLOK_ERROR_WINDOW_CREATION);

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
    optionalWindow.optionalInstance.actualInstance = window;

    return optionalWindow;
}

void blokWindowFree(struct Window *window)
{
    BLOK_EXIT_IF(!window);

    (void)UnregisterClassW(
        window->windowClassName, blokProgramInstanceGet()->instanceHandle);

    BLOK_FREE_IF_NOT_NULL(window->nativeWindowClass.hIcon, (void)DestroyIcon);
    BLOK_FREE_IF_NOT_NULL(window->nativeWindowClass.hIconSm, (void)DestroyIcon);
    BLOK_FREE_IF_NOT_NULL(window->nativeWindowClass.hCursor, (void)DestroyCursor);
    BLOK_FREE_IF_NOT_NULL(window->nativeWindowClass.hbrBackground, (void)DeleteObject);
    BLOK_FREE_IF_NOT_NULL(window->windowHandle, (void)DestroyWindow);
}
