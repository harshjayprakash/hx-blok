#include "window.h"

static int window_action_key_down(HWND window_handle, WPARAM word_param, LPARAM long_param)
{
    switch (word_param)
    {
    case VK_UP:
        square_move(&store_instance_get()->movable_square, north);
        break;
    case VK_RIGHT:
        square_move(&store_instance_get()->movable_square, east);
        break;
    case VK_DOWN:
        square_move(&store_instance_get()->movable_square, south);
        break;
    case VK_LEFT:
        square_move(&store_instance_get()->movable_square, west);
        break;
    default:
        return -1;
    }
    InvalidateRect(window_handle, NULL, TRUE);
    return 0;
}

static int window_action_while_running(HWND window_handle, WPARAM word_param, LPARAM long_param)
{
    HDC device_context_handle = GetDC(window_handle);
    HBRUSH square_painter = CreateSolidBrush(RGB(255, 255, 255));
    RECT square_to_paint = square_winapi_rect_cast(&store_instance_get()->movable_square);
    (void)FillRect(device_context_handle, &square_to_paint, square_painter);
    (void)DeleteObject(square_painter);
    (void)ReleaseDC(window_handle, device_context_handle);
    return 0;
}

static int window_action_on_close(void)
{
    PostQuitMessage(0);
    return 0;
}

static long long window_callback(HWND window_handle, UINT message, WPARAM word_param,
                                 LPARAM long_param)
{
    switch (message)
    {
    case WM_DESTROY:
        return window_action_on_close();
    case WM_KEYDOWN:
        return window_action_key_down(window_handle, word_param, long_param);
    default:
        return DefWindowProcW(window_handle, message, word_param, long_param);
    }
}

static int window_message_loop(struct window *wnd)
{
    if (!wnd)
    {
        return BLOK_NULL_POINTER_ERROR;
    }
    while (GetMessageW(&wnd->window_message, NULL, 0, 0))
    {
        TranslateMessage(&wnd->window_message);
        DispatchMessageW(&wnd->window_message);
        window_action_while_running(wnd->window_handle, wnd->window_message.wParam,
                                    wnd->window_message.lParam);
    }
    return (int)wnd->window_message.wParam;
}

static ATOM window_register(struct window *wnd)
{
    if (!wnd)
    {
        return BLOK_NULL_POINTER_ERROR;
    }
    (void)wcsncpy(wnd->window_class_name, L"blok_window_class", CHAR_LENGTH_COUNT);
    wnd->window_class.cbSize = sizeof(WNDCLASSEXW);
    wnd->window_class.style = CS_HREDRAW | CS_VREDRAW;
    wnd->window_class.lpfnWndProc = window_callback;
    wnd->window_class.cbClsExtra = 0;
    wnd->window_class.cbWndExtra = 0;
    wnd->window_class.hInstance = program_instance_get()->instance_handle;
    wnd->window_class.hIcon = LoadIcon(wnd->window_class.hInstance, IDI_APPLICATION);
    wnd->window_class.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd->window_class.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    wnd->window_class.lpszMenuName = NULL;
    wnd->window_class.lpszClassName = wnd->window_class_name;
    wnd->window_class.hIconSm = LoadIcon(wnd->window_class.hInstance, IDI_APPLICATION);
    return RegisterClassExW(&wnd->window_class);
}

static int window_create(struct window *wnd)
{
    if (!wnd)
    {
        return BLOK_NULL_POINTER_ERROR;
    }
    wnd->window_handle = CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, wnd->window_class_name,
                                         L"The Experimental Block Project.", WS_OVERLAPPEDWINDOW,
                                         CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL,
                                         program_instance_get()->instance_handle, NULL);
    if (!wnd->window_handle)
    {
        return BLOK_WINDOW_CREATION_ERROR;
    }
    return BLOK_OPERATION_SUCCESS;
}

struct window_wrapper window_new(void)
{
    struct window_wrapper opt_window;
    opt_window.registered = false;
    opt_window.created = false;
    opt_window.present = false;
    struct window wnd;
    int result = 0;
    result = window_register(&wnd);
    if (result == BLOK_WINDOW_REGISTRATION_ERROR)
    {
        window_free(&wnd);
        return opt_window;
    }
    opt_window.registered = true;
    result = window_create(&wnd);
    if (result == BLOK_WINDOW_CREATION_ERROR)
    {
        window_free(&wnd);
        return opt_window;
    }
    opt_window.created = true;
    ShowWindow(wnd.window_handle, program_instance_get()->show_flag);
    UpdateWindow(wnd.window_handle);
    window_message_loop(&wnd);
    opt_window.present = true;
    opt_window.handle.instance = wnd;
    return opt_window;
}

void window_free(struct window *wnd)
{
    if (!wnd)
    {
        return;
    }

    (void)UnregisterClassW(wnd->window_class_name, program_instance_get()->instance_handle);

    if (wnd->window_class.hIcon)
    {
        (void)DestroyIcon(wnd->window_class.hIcon);
    }

    if (wnd->window_class.hIconSm)
    {
        (void)DestroyIcon(wnd->window_class.hIconSm);
    }

    if (wnd->window_class.hCursor)
    {
        (void)DestroyCursor(wnd->window_class.hCursor);
    }

    if (wnd->window_class.hbrBackground)
    {
        (void)DeleteObject(wnd->window_class.hbrBackground);
    }

    if (wnd->window_handle)
    {
        (void)DestroyWindow(wnd->window_handle);
    }
}
