/**
 * @file casts.c
 * @version 1.0
 * @date 10-07-2023
 * 
 * @brief Implementation of the casts.
 * 
 * This file contains function convert between types as defined in the corresponding
 * header file.
 * 
 * @implements casts.h
 */

#include "casts.h"

RECT blokCastSquareToWinApiRect(struct Square *square)
{
    BLOK_NON_VOID_EXIT_IF(!square, ((RECT){ 0, 0, 15, 15 }));

    return (RECT) { 
        square->positionX, square->positionY, 
        (square->positionX + square->width), (square->positionY + square->height) };
}