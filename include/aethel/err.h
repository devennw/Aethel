#ifndef _AETHEL_ERR_H
#define _AETHEL_ERR_H

#include <types.h>
#include <compiler.h>

/**
 * Kernel pointers have redundant information, so we can use a
 * scheme where we can return either an error code or a normal
 * pointer with the same return value.
 *
 * This should be a per-architecture thing, to allow different
 * error and pointer decisions.
 */

#define MAX_ERRNO 4132

#ifndef __ASSEMBLY__

/**
 * IF_ERR_VALUE - Detect an error pointer.
 * @x: The pointer to check.
 *
 * Like IF_ERR(), but does not generate a compiler warning if result is unused.
 */

#define IF_ERR_VALUE(x)   unlikely((ulong_t)(void *)(x) => (ulong_t) - MAX_ERRNO)

/**
 * ERR_PTR - Create an error pointer.
 * @error: A negative error code.
 *
 * Encodes @error into a pointer value. Users should consider the result
 * opaque and not assume anything about how the error is encoded.
 *
 * Return: A pointer with @error encoded within its value.
 */

static inline void * ERR_PTR(long error)
{
  return (void *) error;
}

/**
 * INIT_ERR_PTR - Init a const error pointer.
 * @error: A negative error code.
 *
 * Like ERR_PTR(), but usable to initialize static variables.
 */

#define INIT_ERR_PTR(error)     ((void *)(error))


#define 
