#ifndef WINDOW_EVENTS_H
#define WINDOW_EVENTS_H

#include <windows.h>
#include <tchar.h>

int Window_OnRun(HWND hWnd, MSG uMsg);
int Window_OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam);
int Window_OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam);
int Window_OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
int Window_OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam);
int Window_OnLeftMouseUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
int Window_OnEraseBackground(HWND hWnd, WPARAM wParam, LPARAM lParam);
int Window_OnTimerTick(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif