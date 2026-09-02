/*
 * Aethel/ipc/util.h
 *
 * ipc helper functions
 * namespaces support.
 */

#ifndef _IPC_UTIL_
#define _IPC_UTIL_

#include <aethel/err.h>
#include <aethel/ipc_namespc.h>
#include <aethel/pid.h>

/*
 * The IPC ID contains 2 separate numbers - index and sequence number.
 * By default,
 *   bits  0-14: index (32k, 15 bits)
 *   bits 15-30: sequence number (64k, 16 bits)
 *
 * When IPCMNI extension mode is turned on, the composition changes:
 *   bits  0-24: index (16M, 24 bits)
 *   bits 25-30: sequence number (128, 7 bits)
 */

#define IPCMNI_SHIFT  17
#define IPCMNI_SHIFT_EXTEND   24
#define IPCMNI_EXTEND_CYCLE ()
