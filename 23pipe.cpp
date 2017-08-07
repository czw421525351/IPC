//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"

int main()
{
    int pipefds[2];
    if(pipe(pipefds) < 0)
        ERR_EXIT("pipe");

    pid_t pid;
    if((pid = fork()) < 0)
        ERR_EXIT("fork");
    if(pid == 0)
    {
        close(pipefds[0]);
        char buf[10] = "hello";
        write(pipefds[1],buf,strlen(buf));
        /*实验一下发现也可以自写自读
        char buf2[10] = {0};
        read(pipefds[0],buf2,sizeof(buf2));
        printf("child recv %s\n",buf2);
        */
        exit(EXIT_SUCCESS);
    }

    close(pipefds[1]);
    char buf[10] = {0};
    read(pipefds[0],buf,sizeof(buf));
    printf("father recv %s\n",buf);

    return 0;
}

