#ifndef BLOK_MARK_H
#define BLOK_MARK_H

/**
 * @brief Represents the state the mark can be in.
 */
enum mark_status
{
    /**
     * @brief Indicates a mark that is not visible.
     */
    mark_invisible = 0,

    /**
     * @brief Indicates a mark that is visible.
     *
     */
    mark_visible = 1,
};

/**
 * @brief Represents a mark's position and visibility.
 */
struct mark
{
    /**
     * @brief Stores the x coordinate of the mark.
     */
    int x;

    /**
     * @brief Stores the y coordinate of the mark.
     */
    int y;

    /**
     * @brief Stores whether the mark should be illumated.
     */
    enum mark_status illumated;
};

/**
 * @brief Creates a mark structural object.
 * @return a new stack allocated instance of the mark structure.
 */
struct mark mark_new(int x, int y);

#endif
