#ifndef BLOCK_H
#define BLOCK_H

#include <windows.h>

/**
 * Stores the information of the block that the user will interact with.
*/
typedef struct Block
{
    int x;
    int y;
    int width;
    int height;
    int nMovfX;
    int nMovfY;
    int limitX;
    int limitY;
    COLORREF colour;
} Block;

/**
 * Constructor for the Block structure, based on the values given by the user.
 * @param x: The starting x coordinate of the block relative to the window.
 * @param y: The starting y coorindate of the block relative to the window.
 * @param width: The width of the block (in pixels).
 * @param height: The height of the block (in pixels).
 * @param colour: The colour of the block.
*/
void Block_Init(Block* self, int x, int y, int width, int height, COLORREF colour);

/**
 * Destructor for the Block structure. Frees up any memory allocated within the
 * structure.
*/
void Block_Del(Block* self);

/**
 * Sets the colour of the block the user interacts with.
 * @param colour: The colour to the set the block.
*/
void Block_SetColour(Block* self, COLORREF colour);

/**
 * Sets the move rate when pressing the arrow keys. By default it is the the
 * width and height of the block.
 * @param rateX: The rate of the block's movement in the x axis (in pixels).
 * @param rateY: The rate of the block's movement in the y axis (in pixels).
*/
void Block_SetMoveRate(Block* self, int rateX, int rateY);

/**
 * Sets the current position of the block.
 * @param x: The x coordinate relative to the window (in pixels).
 * @param y: The y coordinate relative to the window (in pixels).
*/
void Block_SetPosition(Block* self, int x, int y);

/**
 * Sets the size of the block.
 * @param width: The width of the block (in pixels).
 * @param height: The height of the block (in pixels).
*/
void Block_SetSize(Block* self, int width, int height);

/**
 * Sets the limit of the how far the block can be moved. The default is the
 * height and width multiplied by 10.
 * @param x: The limit in the x direction (in pixels).
 * @param y: The limit in the y direction (in pixels).
*/
void Block_SetLimits(Block* self, int x, int y);

/**
 * Converts the coordinates, height and width to the native RECT structure found
 * within the used within the WinGDI drawing library.
*/
RECT Block_ConvertToRect(Block* self);

/**
 * Moves the block up by the rates set.
*/
void Block_MoveUp(Block* self);

/**
 * Moves the block down by the rates set.
*/
void Block_MoveDown(Block* self);

/**
 * Moves the block to the left by the rates set.
*/
void Block_MoveLeft(Block* self);

/**
 * Moves the block to the right by the rates set.
*/
void Block_MoveRight(Block* self);

#endif // BLOCK_H