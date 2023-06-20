#include "actions.h"

void Action_PaintMarkedBlocks(HDC hDeviceContext)
{
    HBRUSH hMarkedBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hDeviceContext, hMarkedBrush);
    for (int i = 0; i < g_map.indexer + 1; i++)
    {
        Coord crd = { g_map.map[i].x, g_map.map[i].y };
        RECT rcMarked = { crd.x, crd.y, crd.x+15, crd.y+15 };
        FillRect(hDeviceContext, &rcMarked, hMarkedBrush);
    }
    DeleteObject(hMarkedBrush);
}

void Action_PaintUserMovableBlock(HDC hDeviceContext)
{
    RECT rcBlock = Block_ConvertToRect(&g_user);
    HBRUSH hBlockBrush = CreateSolidBrush(g_user.colour);
    SelectObject(hDeviceContext, hBlockBrush);
    FillRect(hDeviceContext, &rcBlock, hBlockBrush);
    DeleteObject(hBlockBrush);
}

void Action_PaintCoordinatesText(HDC hDeviceContext)
{
    TCHAR coordDisplay[25];
    _sntprintf(coordDisplay, 25, "( X: %d, Y: %d )", g_user.x, g_user.y);
    SetTextColor(hDeviceContext, RGB(255, 255, 255));
    SetBkColor(hDeviceContext, RGB(10, 10, 10));
    TextOut(hDeviceContext, 10, g_user.limitY - 25, coordDisplay, strlen(coordDisplay));
}

void Action_PaintOnMarkedLocationText(HDC hDeviceContext)
{
    TCHAR markedDisplay[25] = _T("ON MARKED LOCATION");
    if (Grid_FindMark(&g_map, g_user.x, g_user.y) < 0) { return; }
    SetTextColor(hDeviceContext, RGB(255, 255, 255));
    SetBkColor(hDeviceContext, RGB(10, 10, 10));
    TextOut(hDeviceContext, 10, g_user.limitY - 45, markedDisplay, strlen(markedDisplay));
}

void Action_ResetBlockMovableLimits(HWND hWnd)
{
    RECT wndsize;
    GetClientRect(hWnd, &wndsize);
    Block_SetLimits(&g_user, (wndsize.right - wndsize.left), (wndsize.bottom - wndsize.top));
}

void Action_AddRemoveMarkedBlocks(HWND hWnd, LPARAM lParam)
{
    int x = (LOWORD(lParam) / 15) * 15;
    int y = (HIWORD(lParam) / 15) * 15;
    if (Grid_FindMark(&g_map, x, y) == -3)
    {
        Grid_AddMark(&g_map, x, y);
    }
    else
    {
        Grid_RemoveMark(&g_map, x, y);
        RECT rect = { x, y, x+15, y+15 };
        InvalidateRect(hWnd, &rect, TRUE);
    }
}