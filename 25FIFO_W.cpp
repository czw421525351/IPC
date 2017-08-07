//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"

//O_NONBLOCK disable 阻塞直到有相应进程为读才打开该FIFO !!！
/*
int main()
{
    int fd;
    fd = open("./P1",O_WRONLY);//以写的方式打开  那么读的进程就会阻塞返回
    if(fd == -1)
        ERR_EXIT("open error");

    printf("open succ \n");
    return 0;
}
*/



// O_NONBLOCK enable
/*
int main()
{
    int fd;
    fd = open("./P1",O_WRONLY | O_NONBLOCK);//立即返回失败  错误码是ENXIO
    if(fd == -1)
        ERR_EXIT("open error");

    printf("open succ \n");
    return 0;
}
*/




//拷贝文件

int main()
{
    mkfifo("./P2",0664);

    int infd = open("./Makefile",O_RDONLY);
    if(infd < 0)
        ERR_EXIT("open makefile");

    int outfd;
    outfd = open("./P2",O_WRONLY);
    if(outfd < 0)
        ERR_EXIT("open FIFO");

    char buf[1024] = {0};
    int n = 0;
    while ((n = read(infd,buf,sizeof(buf))) > 0)
    {
            write(outfd,buf,n);
    }

    close(infd);
    close(outfd);
    return 0;
}





