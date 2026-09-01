#ifndef _TYPES_H
#define _TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* 
 * type data boolean 
 */

#ifndef BOOLEAN
#define BOOLEAN

typedef _Bool bool;

#define true 1
#define false 0

#define NULL ((void*) 0 )

#endif // BOOLEAN

/* 
 * type data
 */
typedef uint8_t uchar_t;
typedef uint16_t ushort_t;
typedef uint32_t ulong_t;
typedef uint64_t ulonglong_t;

typedef int8_t  schar_t;
typedef int16_t sshort_t;
typedef int32_t long_t;
typedef int64_t longlong_t;

typedef schar_t       sint_least8_t;
typedef sshort_t      sint_least16_t;
typedef long_t        long_least32_t;
typedef longlong_t    longlong_least64_t;
typedef longlong_t    longlong_max_t;
typedef uchar_t       uchar_least8_t;
typedef ushort_t      ushort_least16_t;
typedef ulong_t       ulong_least32_t;
typedef ulonglong_t   ulonglong_least64_t;
typedef ulonglong_t   ulonglong_max_t;

/* 
 * type data for memory pointer (64-bit) 
 */

#ifdef __SIZEOF_POINTER__ == 8
  typedef longlong_t    longlongptr_t;
  typedef ulonglong_t   ulonglongptr_t;
#elif __SIZEOF_POINTER__ == 4
  typedef long_t      longptr_t;
  typedef longlong_t  longlongptr_t;
  typedef ulong_t     ulongptr_t;
  typedef ulonglong_t ulonglongptr_t;
#else
# error unsupported pointer size
#endif // __SIZEOF_POINTER__

#ifdef __PTRADDR_TYPE__
typedef __PTRADDR_TYPE__  __ptraddr_t;
#else
typedef size_t        __ptraddr_t;
#endif

typedef __ptraddr_t   __vm_offset_t;
typedef size_t        __vm_size_t;

/*
 * standard type definition 
 */
typedef long_t          blksize_t;
typedef longlong_t      blkcnt_t;
typedef long_t          clockid_t;
typedef ulong_t         flags_t;
typedef ulonglong_t     fsblknct_t;
typedef ulonglong_t     fsfilcnt_t;
typedef ulong_t         gid_t;
typedef longlong_t      id_t;
typedef ulonglong_t     ino_t;
typedef long            key_t;
typedef long_t          lwpid_t;
typedef ulong_t         mode_t;
typedef int             accmode_t;
typedef int             nl_item;
typedef ulonglong_t     nlink_t;
typedef longlong_t      off_t;
typedef longlong_t      off_long_t;
typedef long_t          pid_t;
typedef longlong_t      sbintime_t;
typedef longlong_t      rlim_t;
typedef void            *handle_t;

typedef uchar_t         sa_family_t;
typedef ulong_t         socklen_t;
typedef long            suseconds_t;
typedef struct __timer  *timer_t;
typedef struct __mq     *mqd_t;
typedef ulong_t         uid_t;
typedef ulong_t         useseconds_t;
typedef int             cpuwitch_t;
typedef int             cpulevel_t;
typedef int             cpusetid_t;
typedef longlong_t      daddr_t;

/*
 * Unusual type definitions.
 */

typedef struct {
	long long __max_align1
	    __attribute__((__aligned__(__alignof__(long long))));
#ifndef _STANDALONE
	long double __max_align2
	    __attribute__((__aligned__(__alignof__(long double))));
#endif
	void *__max_align3 __attribute__((__aligned__(__alignof__(void *))));
} __max_align_t;

#endif // _TYPES_H
