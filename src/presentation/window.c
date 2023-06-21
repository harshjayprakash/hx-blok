#include "window.h"

static int window_action_while_running(HWND window_handle, WPARAM word_param, LPARAM long_param)
{
}
static int window_action_on_close(HWND window_handle, WPARAM word_param, LPARAM long_param)
{
}

static long long window_callback(
    HWND window_handle, 
    UINT message, 
    WPARAM word_param, 
    LPARAM long_param)
{
}

static int window_message_loop(window *wnd)
{
}

static ATOM window_register(window *wnd)
{
}

static int window_create(window *wnd)
{
}

optional_window window_new(void)
{
}

void window_free(window *wnd)
{

}