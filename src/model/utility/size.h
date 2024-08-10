/**
 * @file size.h
 * @date 2024-08-10
 * @brief
 */

#ifndef NEON_SIZE_H
#define NEON_SIZE_H

/**
 * @brief A object to represent size.
 */
typedef struct __NeonSize
{
    /**
     * @brief The represented width.
     */
    int width;
    /**
     * @brief The represented height.
     */
    int height;
} NeonSize;

/**
 * @brief Create a new size object.
 * 
 * @param width The width.
 * @param height The height.
 * @return NeonSize A stack allocated size object.
 */
NeonSize NeonCreateSize(const int width, const int height);

/**
 * @brief Create a new size object from another instance.
 * 
 * @param size The size object to copy.
 * @return NeonSize A new stack allocated instance of the size object.
 */
NeonSize NeonCreateSizeFromSelf(const NeonSize size);

#endif