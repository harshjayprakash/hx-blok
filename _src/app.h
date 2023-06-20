#ifndef APP_H
#define APP_H

#include <windows.h>

/**
 * Stores application entrypoint parameters for future reference throughout
 * the program.
*/
typedef struct Application
{
    HINSTANCE hInst;
    HINSTANCE hPrevInst;
    LPSTR lpCmdline;
    INT nShow;
} Application;

/**
 * A function that takes in the entrypoint parameters and assigns them to the
 * structure.
 * @param hInst: Handle to the instance of the application. Windows uses this 
 *      to identify the program executable when loaded in memory
 * @param hPrevInst: Used for 16-bit version of Windows. Not used in this
 *      application.
 * @param lpCmdline: Any command line arguments specified when running the
 *      program.
 * @param nShow: A flag used to specify how the application should be displayed.
*/
void Application_Init(Application* self, HINSTANCE hInst, HINSTANCE hPrevInst,
        LPSTR lpCmdline, INT nShow);

/**
 * A function that frees up any resources allocated to any variables in the
 * structure.
*/
void Application_Del(Application* self);

#endif // APP_H