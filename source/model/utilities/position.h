#ifndef NEON_POSITION_H
#define NEON_POSITION_H

typedef struct _NeonPosition
{
    int x;
    int y;
} NeonPosition;

NeonPosition NeonNewPosition(const int x, const int y);

NeonPosition NeonNewPositionFromSelf(const NeonPosition pos);

void NeonSetPosition(NeonPosition *pos, const int x, const int y);

void NeonSetPositionX(NeonPosition *pos, const int x);

void NeonSetPositionY(NeonPosition *pos, const int y);

void NeonCopyPosition(NeonPosition *dest, const NeonPosition src);

#endif