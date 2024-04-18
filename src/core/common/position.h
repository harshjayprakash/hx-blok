#ifndef BLOQ_POSITION_H
#define BLOQ_POSITION_H

/**
 * \brief A structure denoting position.
 */
typedef struct bloqPosition 
{
    /**
     * \brief Represents the x coordinate.
     */
    int x;

    /**
     * \brief Represents the y coordinate.
     */
    int y;
} TPosition;

/**
 * \brief Returns a new position object.
 * 
 * \param x the x position.
 * \param y the y position.
 * \return TPosition - Stack alloc position object.
 */
TPosition bloqNewPosition(const int x, const int y);

/**
 * \brief Sets the x coordinate of the given position.
 * 
 * \param pos the position object to be updated.
 * \param x the new x coordinate.
 */
void bloqSetPositionX(TPosition *pos, const int x);

/**
 * \brief Sets the y coordinate of the given position.
 * 
 * \param pos the position object to be updated.
 * \param y the new y coordinate.
 */
void bloqSetPositionY(TPosition *pos, const int y);

/**
 * \brief Sets both coorindates of the position.
 * 
 * \param pos the position object to be updated.
 * \param x the new x coordinate.
 * \param y the new y coordinate.
 */
void bloqSetPosition(TPosition *pos, const int x, const int y);

/**
 * \brief Provides a method for copying the TPosition object.
 * 
 * \param src the object to copy from.
 * \param dest the object to copy to.
 */
void bloqCopyPosition(TPosition *src, TPosition *dest);

#endif