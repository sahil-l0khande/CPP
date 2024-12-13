#include "command.hpp" /* Custom header file for command */

#define PROJECT_ID 5
#define FILE_NAME "common.txt"
#define SLEEP_TIME 5

struct command cmd;

class sender
{

private:
    key_t key;    /* for ftok return value */
    int msgid;    /* message queue descriptor */
    int ret_send; /* return value of msgsnd() */

public:
    sender()
    {
    }

    void create_ipc()
    {
        key = ftok(FILE_NAME, PROJECT_ID);
        msgid = msgget(key, IPC_CREAT);
        if (msgid == -1)
        {
            fprintf(stderr, "msgget:%s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    void create_file()
    {
        cmd.cmd_type = CMD_FILE_CREATE;
        memset(cmd.path_name, 0, MAX_PATH_LENGTH);
        strncpy(cmd.path_name, "test.txt", strlen("test.txt"));
        cmd.open_flag = O_RDWR | O_CREAT | O_TRUNC;
        cmd.permissions = 0644;

        ret_send = msgsnd(msgid, (void *)&cmd, sizeof(struct command), 0);
        if (ret_send == -1)
        {
            fprintf(stderr, "msgsnd:%s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    void write_file()
    {
        memset(&cmd, 0, sizeof(struct command));
        cmd.cmd_type = CMD_FILE_WRITE;
        strncpy(cmd.path_name, "test.txt", strlen("test.txt"));
        cmd.offset = 0;
        cmd.size = 32;

        ret_send = msgsnd(msgid, (void *)&cmd, sizeof(struct command), 0);
        if (ret_send == -1)
        {
            fprintf(stderr, "msgsnd:%s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    void read_file()
    {
        memset(&cmd, 0, sizeof(struct command));
        cmd.cmd_type = CMD_FILE_READ;
        strncpy(cmd.path_name, "test.txt", strlen("test.txt"));
        cmd.offset = 0;
        cmd.size = 32;

        ret_send = msgsnd(msgid, (void *)&cmd, sizeof(struct command), 0);
        if (ret_send == -1)
        {
            fprintf(stderr, "msgsnd:%s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    void terminate()
    {
        memset(&cmd, 0, sizeof(struct command));
        cmd.cmd_type = CMD_TERMINATE;

        ret_send = msgsnd(msgid, (void *)&cmd, sizeof(struct command), 0);
        if (ret_send == -1)
        {
            fprintf(stderr, "msgsnd:%s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    ~sender()
    {
        if (msgctl(msgid, IPC_RMID, NULL) == -1)
        {
            fprintf(stderr, "msgctl:%s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
};

int main(void)
{
    sender send;
    // create ipc
    send.create_ipc();
    // create file
    send.create_file();
    sleep(SLEEP_TIME);

    send.write_file();

    // write file
    sleep(SLEEP_TIME);

    send.read_file();
    // read file
    sleep(SLEEP_TIME);

    send.terminate();

    // terminate
    sleep(SLEEP_TIME);

    return 0;
}
