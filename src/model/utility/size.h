/**
 * \file size.h
 * \date 13-08-2024
 * \brief Function definitions and structure for the size object.
 *
 * This file contains the structure to model size and the required function definitions.
 */

#ifndef NEON_SIZE_H
#define NEON_SIZE_H

/**
 * \brief Models the size.
 */
typedef struct __NeonSize
{
    int width;  ///< The Width of an Object.
    int height; ///< The Height of an Object.
} NeonSize;

/**
 * \brief Creates a new size object.
 *
 * \param width The represented width.
 * \param height The represented height.
 * \return A new stack allocated size object.
 */
NeonSize NeonCreateSize(const int width, const int height);

/**
 * \brief Creates a new size object from an existing size object.
 *
 * \param size The existing size object.
 * \return A new stack allocated size object.
 */
NeonSize NeonCreateSizeFromSelf(const NeonSize size);

/**
 * \brief Sets the size.
 *
 * \param size The size instance to be updated.
 * \param width The new width.
 * \param height The new height.
 */
void NeonSetSize(NeonSize *size, const int width, const int height);

/**
 * \brief Sets the width.
 *
 * \param size The size instance to be updated.
 * \param width The new width.
 */
void NeonSetWidth(NeonSize *size, const int width);

/**
 * \brief Sets the height.
 *
 * \param size The size instance to be updated.
 * \param height The new height.
 */
void NeonSetHeight(NeonSize *size, const int height);

/**
 * @brief Copy the size instance.
 *
 * @param dest The size to be copied to.
 * @param src The size to be copied from.
 */
void NeonCopySize(NeonSize *dest, const NeonSize src);

#endif