#include "window_events.h"

int WindowEvent_OnRun(HWND hWnd, MSG uMsg)
{
    HDC hDeviceContext = GetDC(hWnd);
    Action_PaintMarkedBlocks(hDeviceContext);
    Action_PaintUserMovableBlock(hDeviceContext);
    Action_PaintCoordinatesText(hDeviceContext);
    Action_PaintOnMarkedLocationText(hDeviceContext);
    ReleaseDC(hWnd, hDeviceContext);
    return 0;
}

int WindowEvent_OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    PostQuitMessage(0);
    return 0;
}

int WindowEvent_OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    switch (wParam)
    {
        case VK_UP: Block_MoveUp(&g_user); break;
        case VK_DOWN: Block_MoveDown(&g_user); break;
        case VK_LEFT: Block_MoveLeft(&g_user); break;
        case VK_RIGHT: Block_MoveRight(&g_user); break;
        default: return 0;
    }
    InvalidateRect(hWnd, NULL, TRUE);
    return 0;
}

int WindowEvent_OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    Action_ResetBlockMovableLimits(hWnd);
    return DefWindowProc(hWnd, WM_SIZE, wParam, lParam);
}

int WindowEvent_OnLeftMouseUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    Action_AddRemoveMarkedBlocks(hWnd, lParam);
    return DefWindowProc(hWnd, WM_LBUTTONUP, wParam, lParam);
}