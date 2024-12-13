#include "command.hpp"

#define FILE_NAME           "common.txt"
#define PROJECT_ID          5
#define READ_WRITE_SIZE     32
#define TRUE                1


class receiver{
    private:
    
    char msg[READ_WRITE_SIZE] = "AAAAAAAAAAABBBBBBCCCCCCCCCDDDDD";
    char r_buffer[READ_WRITE_SIZE];
    key_t key;          /* output of ftok */
    int msgid;          /* message queue descriptor */
    int ret_recv;       /* status of msgrvc() */
    int fd;             /* file descriptor for new file */
    long offset;        /* return value of lseek() */
    ssize_t wb, rb;     /* return values of read()/write() */
    struct command cmd;

    public:

    receiver(){
        
    }

    void create_ipc(){
        key = ftok(FILE_NAME, PROJECT_ID);
        msgid = msgget(key, IPC_CREAT);
        if(msgid == -1){
            fprintf(stderr, "msgget:%s\n", std::strerror(errno));
            exit(EXIT_FAILURE);
        }

    }

    void rcv_msg(){
                memset(&cmd, 0, sizeof(struct command));
        ret_recv = msgrcv(msgid, (void *)&cmd, sizeof(struct command), 0, 0);

        if (ret_recv == -1)
        {
            std::cout<<"\nmsg recvvvv\n"<<std::endl;
            fprintf(stderr, "msgrcv:%s\n", std::strerror(errno));
            exit(EXIT_FAILURE);
        }

    }

    void exec_app(){
        switch (cmd.cmd_type)
        {
            case CMD_FILE_CREATE:

            //create
            create_file();
                    break;

        case CMD_FILE_READ:

            //read
            read_file();
            break;
        case CMD_FILE_WRITE:
            
            //write
            write_file();
                break;

            case CMD_TERMINATE:
                std::cout << "Calling destructor\n"<< std::endl;
                puts("\nexisting...");
                exit(EXIT_SUCCESS);
                default:
                    break;
        }

    }
    // file create

    void create_file()
    {
        fd = open(cmd.path_name, cmd.open_flag, cmd.permissions);
        if (fd == -1)
        {
            fprintf(stderr, "open:%s:%s\n", cmd.path_name, strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (close(fd) == -1)
        {
            fprintf(stderr, "close:%s:%s\n", cmd.path_name,
                    strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    // file read

    void read_file(){
        fd = open(cmd.path_name, O_RDONLY);
            if (fd == -1)
            {
                fprintf(stderr, "open:%s:%s\n", cmd.path_name, strerror(errno));
                exit(EXIT_FAILURE);
            }

            offset = lseek(fd, SEEK_SET, cmd.offset);
            if (offset == -1)
            {
                fprintf(stderr, "lseek:%s:%s\n", cmd.path_name, strerror(errno));
                exit(EXIT_FAILURE);
            }

            memset(r_buffer, 0, READ_WRITE_SIZE);
            rb = read(fd, r_buffer, READ_WRITE_SIZE);
            if (rb == -1)
            {
                fprintf(stderr, "read:%s:%s\n", cmd.path_name, strerror(errno));
                exit(EXIT_FAILURE);
            }

            puts("Read portion of file:");
            write(STDOUT_FILENO, r_buffer, READ_WRITE_SIZE);

            if (close(fd) == -1)
            {
                fprintf(stderr, "close:%s:%s\n", cmd.path_name, strerror(errno));
                exit(EXIT_FAILURE);
            }
    }

    // file write
    void write_file(){
                fd = open(cmd.path_name, O_RDWR);
                if(fd == -1){
                    fprintf(stderr, "write:%s:%s\n", cmd.path_name,
                                    strerror(errno));
                    exit(EXIT_FAILURE);
                }

                offset = lseek(fd, SEEK_SET, cmd.offset);
                if(offset == -1){
                    fprintf(stderr, "lseek:%s:%s\n", cmd.path_name,
                                    strerror(errno));
                    exit(EXIT_FAILURE);
                }

                // GAP
                wb = write(fd, msg, READ_WRITE_SIZE);
                if (wb == -1)
                {
                    fprintf(stderr, "write:%s:%s\n", cmd.path_name, strerror(errno));
                    exit(EXIT_FAILURE);
                }

                if(close(fd) == -1){
                    fprintf(stderr, "close:%s:%s\n", cmd.path_name,
                                    strerror(errno));
                    exit(EXIT_FAILURE);
                }
    }
    
};


int main(void){
    
    receiver rec;

    // create IPC
    rec.create_ipc();

    while (TRUE)
    {
        rec.rcv_msg();
        
        rec.exec_app();
    }

    return 0;
}