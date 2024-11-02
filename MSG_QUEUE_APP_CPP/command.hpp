#ifndef _COMMAND_HPP
#define _COMMAND_HPP

#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/ipc.h> /* Declarations common to all IPC */
#include <sys/msg.h> /* Declarations specific to msg Q */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cerrno>
#include <string>
#include <cstring>

#define CMD_FILE_CREATE     1
#define CMD_FILE_READ       2
#define CMD_FILE_WRITE      3
#define CMD_TERMINATE       4
#define  MAX_PATH_LENGTH    32

struct command
{
    int cmd_type;
    char path_name[MAX_PATH_LENGTH];

    /* create command */
    int open_flag;
    int permissions;

    /* read/write command */
    long offset;
    unsigned long size;



};



#endif /* _COMMAND_HPP */