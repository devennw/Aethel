#ifndef _PID_TYPES_H_
#define _PID_TYPES_H_

enum type_for_pid {
  PID_TYPE_PID,
  PID_TYPE_TGID,
  PID_TYPE_PGID,
  PID_TYPE_SID,
  PID_TYPE_MAX,
  PID_TYPE_UID,
};

struct pid_namespc;
extern struct pid_namespc init_pid_t;
extern struct pid_namespc init_uid_t;

#endif // _PID_TYPES_H_
