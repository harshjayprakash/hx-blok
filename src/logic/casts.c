#include "casts.h"

RECT blokCastSquareToWinApiRect(struct Square *square)
{
    BLOK_NON_VOID_EXIT_IF(!square, ((RECT){ 0, 0, 15, 15 }));

    return (RECT) { 
        square->positionX, square->positionY, 
        (square->positionX + square->width), (square->positionY + square->height) };
}