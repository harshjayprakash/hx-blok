#include "window.h"

static int window_action_while_running(HWND window_handle, WPARAM word_param,
                                       LPARAM long_param) {
    HDC device_context_handle = GetDC(window_handle);
    HBRUSH square_painter = CreateSolidBrush(RGB(255, 255, 255));

    RECT square_to_paint = global_square_get_winapi_rect();
    FillRect(device_context_handle, &square_to_paint, square_painter);

    (void)DeleteObject(square_painter);
    (void)ReleaseDC(window_handle, device_context_handle);
    return 0;
}

static int window_action_on_close(void) {
    PostQuitMessage(0);
    return 0;
}

        return window_action_on_close();
    }
}

static int window_message_loop(struct window *wnd) {
        return -1;
    
    while (GetMessageW(&wnd->window_message, NULL, 0, 0))
    {
        TranslateMessage(&wnd->window_message);
        DispatchMessageW(&wnd->window_message);
        window_action_while_running(
            wnd->window_handle, wnd->window_message.wParam, wnd->window_message.lParam);
    }
    return (int) wnd->window_message.wParam;
}

static ATOM window_register(struct window *wnd) {
        return -1;
    
    (void) wcsncpy(wnd->window_class_name, L"blok_window_class", CHAR_LENGTH_COUNT);

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

static int window_create(struct window *wnd) {
    if (wnd == NULL)
        return -1;
    
    wnd->window_handle = CreateWindowExW(
        WS_EX_OVERLAPPEDWINDOW,
        wnd->window_class_name,
        L"The Experimental Block Project.",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL,
        NULL,
        program_instance_get()->instance_handle,
        NULL
    );

    if (!wnd->window_handle)
        return 1;
    
    return 0;
}

struct window_wrapper window_new(void) {
    struct window_wrapper opt_window;
    opt_window.registered = false;
    opt_window.created = false;
    opt_window.present = false;
    struct window wnd;
    int result = 0;

    result = window_register(&wnd);
    if (result == 0) {
        window_free(&wnd);
        return opt_window;
    }
    opt_window.registered = true;

    result = window_create(&wnd);
    if (result == 1) {
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

void window_free(struct window *wnd) {
    if (wnd == NULL)
        return;
    
    (void) UnregisterClassW(wnd->window_class_name, program_instance_get()->instance_handle);
    
    if (wnd->window_class.hIcon)
        (void) DestroyIcon(wnd->window_class.hIcon);

    if (wnd->window_class.hIconSm)
        (void) DestroyIcon(wnd->window_class.hIconSm);
    
    if (wnd->window_class.hCursor)
        (void) DestroyCursor(wnd->window_class.hCursor);
    
    if (wnd->window_class.hbrBackground)
        (void) DeleteObject(wnd->window_class.hbrBackground);
    
    if (wnd->window_handle)
        (void) DestroyWindow(wnd->window_handle);
}