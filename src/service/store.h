#ifndef BLOK_STORE_H
#define BLOK_STORE_H

#include <windows.h>

#include "../model/square.h"

struct square *global_square_get(void);

RECT global_square_get_winapi_rect();

#endif
