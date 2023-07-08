#ifndef BLOK_CASTS_H
#define BLOK_CASTS_H

#include <Windows.h>

#include "../core/macros.h"
#include "../model/square.h"

RECT blokCastSquareToWinApiRect(struct Square *square);

#endif