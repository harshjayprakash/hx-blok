#include "casts.h"

RECT blokCastSquareToWinApiRect(struct TSquare *sq)
{
    if (!sq)
    {
        return (RECT) { 
            0, 0, 15, 15 
        };
    }

    return (RECT) { 
        sq->pos.x, 
        sq->pos.y, 
        (sq->pos.x + sq->size.width), 
        (sq->pos.y + sq->size.height) 
    };
}