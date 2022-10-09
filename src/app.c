#include "incl/app.h"

void Application_Init(
    Application* self, HINSTANCE _hInst, HINSTANCE _hPrevInst,
    LPSTR _lpCmdline, INT _nShow)
{
    self->hInst = _hInst;
    self->hPrevInst = _hPrevInst;
    self->lpCmdline = _lpCmdline;
    self->nShow = _nShow;
}

void Application_Del(Application* self)
{
    
}