#include "incl/window_events.h"
#include "incl/block.h"
#include "incl/global.h"

#if (DEBUGGING_MECHANISM || EXPERIMENTAL)
#include <stdio.h>
#endif

extern Block g_plyr;
extern Block g_sdwcpy;
extern Grid g_map;

int Window_OnRun(HWND hWnd, MSG uMsg)
{
    RECT rectPxl = Block_ConvertToRect(&g_plyr);
    HDC hDevContext = GetDC(hWnd);
    TCHAR coordDisplay[25];
    TCHAR coordMarked[50];
    HBRUSH plyrhBrush = CreateSolidBrush(g_plyr.colour);
    int coordDecteced = 0;
    HBRUSH blokhBrush = CreateSolidBrush(RGB(255, 255, 255));

    // ! Application will redraw the (0, 0) grid sq after clicking on another area and refreshing.

    for (int i = 0; i < g_map.idxr + 1; i++)
    {
        GridPoint gp = g_map.map[i];
        RECT rct = { gp.posX, gp.posY, gp.posX+15, gp.posY+15 };
        FillRect(hDevContext, &rct, blokhBrush);
        if (gp.posX == g_plyr.x && gp.posY == g_plyr.y)
        {
            _tcsncpy(coordMarked, "ON MARKED LOCATION", 50);
            coordDecteced = 1;
        }
    }

    SelectObject(hDevContext, plyrhBrush);
    FillRect(hDevContext, &rectPxl, plyrhBrush);

    _sntprintf(coordDisplay, 25, "( X: %d, Y: %d )", g_plyr.x, g_plyr.y);
    SetTextColor(hDevContext, RGB(255, 255, 255));
    SetBkColor(hDevContext, RGB(10, 10, 10));
    TextOut(hDevContext, 10, g_plyr.limitY - 25, coordDisplay, strlen(coordDisplay));

    if (coordDecteced)
    {
        SelectObject(hDevContext, blokhBrush);
        SetTextColor(hDevContext, RGB(255, 255, 255));
        SetBkColor(hDevContext, RGB(10, 10, 10));
        TextOut(hDevContext, 10, g_plyr.limitY - 45, coordMarked, strlen(coordMarked));
    }

    DeleteObject(blokhBrush);
    DeleteObject(plyrhBrush);

    ReleaseDC(hWnd, hDevContext);

    return 0;
}

int Window_OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    PostQuitMessage(0);
    return 0;
}

int Window_OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hWnd, WM_PAINT, wParam, lParam);
}

int Window_OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
#if (EXPERIMENTAL && BETA_COLLUSIONS)
    // TODO: [IDEA] Maybe stop the blok from colliding when toggled?
    if (g_plyr.fcollusions)
    {
        g_sdwcpy = g_plyr;
        switch (wParam)
        {
            case VK_UP: Block_MoveUp(&g_sdwcpy); break;
            case VK_DOWN: Block_MoveDown(&g_sdwcpy); break;
            case VK_LEFT: Block_MoveLeft(&g_sdwcpy); break;
            case VK_RIGHT: Block_MoveRight(&g_sdwcpy); break;
            default: return 0;
        }
        int coordDectected = 0;
        for (int i = 0; i < g_map.idxr + 1; i++)
        {
            GridPoint gp = g_map.map[i];
            if (gp.posX == g_plyr.x && gp.posY == g_plyr.y)
                coordDectected = 1;
        }
        if (!coordDectected)
            return 0;
    }
#endif
    switch (wParam)
    {
        case VK_UP: Block_MoveUp(&g_plyr); break;
        case VK_DOWN: Block_MoveDown(&g_plyr); break;
        case VK_LEFT: Block_MoveLeft(&g_plyr); break;
        case VK_RIGHT: Block_MoveRight(&g_plyr); break;
#if (EXPERIMENTAL && BETA_COLLUSIONS)
        case VK_SPACE: { g_plyr.fcollusions = (g_plyr.fcollusions) ? 0 : 1; } break;
#endif
        default: return 0;
    }
    InvalidateRect(hWnd, NULL, TRUE);
    return 0;
}

int Window_OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    RECT sz;
    GetClientRect(hWnd, &sz);
    Block_SetLimits(&g_plyr, (sz.right - sz.left), (sz.bottom - sz.top));
    return DefWindowProc(hWnd, WM_SIZE, wParam, lParam);
}

int Window_OnLeftMouseUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    int x = (LOWORD(lParam) / 15) * 15;
    int y = (HIWORD(lParam) / 15) * 15;
#if DEBUGGING_MECHANISM
    printf("x:%d y:%d\n", x, y);
#endif
    int coordMarked = 0;
    for (int i = 0; i < g_map.idxr + 1; i++)
    {
        GridPoint gp = g_map.map[i];
        if (gp.posX == x && gp.posY == y)
            coordMarked = 1;
    }
    if (!coordMarked)
        Grid_AddBlock(&g_map, x, y);
    else
    {
#if (EXPERIMENTAL && BETA_BLOK_REMOVAL)
        // ! Some blocks remove themseleves.
        Grid_RemoveBlock(&g_map, x, y);
        // ! Causes Window To Flicker, The Repainting can clearly be seen.
        //// InvalidateRect(hWnd, NULL, TRUE);
        //// UpdateWindow(hWnd);
        RECT rct = { x, y, x+15, y+15 };
        InvalidateRect(hWnd, &rct, TRUE);
#endif
    }

    return DefWindowProc(hWnd, WM_LBUTTONUP, wParam, lParam);
}

int Window_OnEraseBackground(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hWnd, WM_ERASEBKGND, wParam, lParam);
}

int Window_OnTimerTick(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    // ! Timer may flicker window repainting more.
    return DefWindowProc(hWnd, WM_TIMER, wParam, lParam);
}