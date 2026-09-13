#ifndef _AETHEL__TYPES_H_
#define _AETHEL__TYPES_H_

#pragma once

typedef unsigned long long __ulong64_t;
typedef unsigned long __ulong32_t;
typedef unsigned int __uint32_t;
typedef unsigned short __uint16_t;
typedef unsigned char __uint8_t;

typedef signed long long __long64_t;
typedef signed long __long32_t;
typedef signed int __int32_t;
typedef signed short __int16_t;
typedef signed char __int8_t;

typedef __int8_t      __int_least8_t;
typedef __int16_t     __int_least16_t;
typedef __int32_t     __int_least32_t;
typedef __long64_t    __int_least64_t;
typedef __long64_t    __intmax_t;
typedef __uint8_t     __uint_least8_t;
typedef __uint16_t    __uint_least16_t;
typedef __uint32_t    __uint_least32_t;
typedef __ulong64_t   __uint_least64_t;
typedef __ulong64_t   __uintmax_t;


#elif __SIZEOF_POINTER__ == 8
typedef __long64_t __intptr_t;
typedef __ulong64_t __uintptr_t;

#elif __SIZEOF_POINTER__ == 4
typedef __int32_t __intptr_t;
typedef __uint32_t __uintptr_t;

#else
#error unsupported pointer size
#endif

#if __SIZEOF_SIZE_T__ == 8
typedef __ulong64_t    __size_t;     /* sizeof() */
typedef __long64_t     __ssize_t;    /* byte count or error */
#elif __SIZEOF_SIZE_T__ == 4
typedef __uint32_t     __size_t;    /* sizeof() */
typedef __int32_t      __ssize_t;   /* byte count or error */
#else
#error unsupported size_t size
#endif

#if __SIZEOF_PTRDIFF_T__ == 8
typedef __long64_t  __ptrdiff_t;    /* ptr1 - ptr2 */
#elif __SIZEOF_PTRDIFF_T__ == 4
typedef __int32_t   __ptrdiff_t;      /* ptr1 - ptr2 */
#else
#error unsupported ptrdiff_t size
#endif

#ifdef __PTRADDR_TYPE__
typedef __PTRADDR_TYPE__  __ptraddr_t;
#else
typedef __size_t    __ptraddr_t;
#endif


#endif // _AETHEL__TYPES_H_
