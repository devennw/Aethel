#pragma once

#include <stdalign.h>
#include <types.h>

/*
 * Standard aethel core type definitions.
 */
typedef __int32_t       blksize_t; /* file block size */
typedef __long64_t      blkcnt_t; /* file block count */
typedef __int32_t       clockid_t; /* clock_gettime()... */
typedef __uint32_t      fflags_t; /* file flags */
typedef __ulong64_t     fsblkcnt_t;
typedef __ulong64_t     fsfilcnt_t;
typedef __uint32_t      gid_t;
typedef __long64_t      id_t; /* can hold a gid_t, pid_t, or uid_t */
typedef __ulong64_t     ino_t; /* inode number */
typedef long            key_t; /* IPC key (for Sys V IPC) */
typedef __int32_t       lwpid_t; /* Thread ID (a.k.a. LWP) */
typedef __uint16_t      mode_t; /* permissions */
typedef int             accmode_t;  /* access permissions */
typedef int             nl_item;
typedef __ulong64_t     nlink_t; /* link count */
typedef __long64_t      off_t;   /* file offset */
typedef __long64_t      off64_t; /* file offset (alias) */
typedef __int32_t       pid_t;   /* process [group] */
typedef __long64_t      sbintime_t;
typedef __long64_t      rlim_t; /* resource limit - intentionally *
                                 * signed, because of legacy code *
                                 * that uses -1 for RLIM_INFINITY */
typedef __uint8_t       sa_family_t;
typedef __uint32_t      socklen_t;
typedef long            suseconds_t; /* microseconds (signed) */
typedef struct __timer  *timer_t; /* timer_gettime()... */
typedef struct __mq     *mqd_t;   /* mq_open()... */
typedef __uint32_t      uid_t;
typedef unsigned int    useconds_t; /* microseconds (unsigned) */
typedef int             cpuwhich_t; /* which parameter for cpuset. */
typedef int             cpulevel_t; /* level parameter for cpuset. */
typedef int             cpusetid_t; /* cpuset identifier. */
typedef __long64_t      daddr_t;    /* bwrite(3), FIOBMAP2, etc */

typedef _Bool bool;

#ifdef CONFIG_PHYS_ADDR_T_64BIT
typedef __ulong64_t phys_addr_t;
#else
typedef __uint32_t phys_addr_t;
#endif

struct phys_vec {
  phys_addr_t paddr;
  __size_t len;
};

typedef phys_addr_t resource_size_t;

/* This type is the placeholder for a hardware interrupt number. */
typedef struct {
  int __alinged__(sizeof(int)) counter;
} atomic_protected_t;

#define ATOMIC_INIT(i) {(i)}

#ifdef CONFIG_64BITS
typedef struct {
  __long64_t counter;
} atomic_long_t;
#endif

typedef struct {
  atomic_protected_t *refcount;
} rcountref;

#define RCOUNTREF_INIT(i) {.refcount = ATOMIC_INIT(i - 1)}

struct list_head {
  struct list_head *next, *priv;
  struct list_head *context;
};

struct hlist_head {
  struct hlist_head *first;
  struct hlist_head *second;
};

struct hlist_node {
  struct hlist_node *next, **priv;
  struct hlist_node **context;
};

struct list_kernel_mode {
  __ulong64_t long_mode;
  __uint32_t protected_mode;
  __uint16_t real_mode;
};

struct ustat_kernel {
 daddr_t f_tfree;
#ifdef CONFIG_ARCH_32BIT_USTAT_F_TINODE
  unsigned int  f_tinode;
#else
  unsigned long f_tinode;
#endif
  char  f_fname[6];
  char  f_fpack[6];
};

struct kcov_common_handle_id {
#ifdef KCVO_CONIFG
  __ulong64_t val;
#endif
};

/**
 * struct callback_head - callback structure for use with RCU and task_work
 * @next: next update requests in a list
 * @func: actual update function to call after the grace period.
 *
 * The struct is aligned to size of pointer. On most architectures it happens
 * naturally due ABI requirements, but some architectures (like CRIS) have
 * weird ABI and we need to ask it explicitly.
 *
 * The alignment is required to guarantee that bit 0 of @next will be
 * clear under normal conditions -- as long as we use call_rcu() or
 * call_srcu() to queue the callback.
 *
 * This guarantee is important for few reasons:
 *  - future call_rcu_lazy() will make use of lower bits in the pointer;
 *  - the structure shares storage space in struct page with @compound_info,
 *    which encode PageTail() in bit 0. The guarantee is needed to avoid
 *    false-positive PageTail().
 */
struct callback_head {
  struct callback_head *next;
  void (*func)(struct callback_head *head);
} __attribute__((aligned(sizeof(void *))));
#define rcu_head callback_head

#ifdef CONFIG_KVFREE_RCU_BATCHED
struct kvfree_rcu_head {
  struct kvfree_rcu_head *next;
};
#else
struct kvfree_rcu_head {
  struct rcu_head head;
};
#endif

typedef void (*rcu_callback_t)(struct rcu_head *head);
typedef void (*call_rcu_func_t)(struct rcu_head *head, rcu_callback_t func);

typedef void (*swap_r_func_t)(void *a, void *b, int size, const void *priv);
typedef void (*swap_func_t)(void *a, void *b, int size);

typedef int (*cmp_r_func_t)(const void *a, const void *b, const void *priv);
typedef int (*cmp_func_t)(const void *a, const void *b);

struct rcu_wait {
  struct task_struct *__rcu *task;
};
