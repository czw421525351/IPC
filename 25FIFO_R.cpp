//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"

//mkfifo 创建有名管道文件
/*
int main()
{
    if(mkfifo("./P1",0664) < 0)
        ERR_EXIT("mkfifo");

    return 0;
}
*/


//命名管道的打开规则


//O_NONBLOCK disable 阻塞直到有相应进程为写才打开该FIFO !!！
/*
int main()
{
    int fd;
    fd = open("./P1",O_RDONLY);//以读的方式打开  那么写的进程就会阻塞返回
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
    fd = open("./P1",O_RDONLY | O_NONBLOCK);//立即返回成功
    if(fd == -1)
        ERR_EXIT("open error");

    printf("open succ \n");
    return 0;
}
*/



int main()
{
    int outfd = open("./Makefile2",O_CREAT|O_WRONLY|O_TRUNC,0664);
    if(outfd < 0)
        ERR_EXIT("open makefile");

    int infd;
    infd = open("./P2",O_RDONLY);
    if(infd < 0)
        ERR_EXIT("open FIFO");

    char buf[1024] = {0};
    int n = 0;
    while ((n = read(infd,buf,sizeof(buf))) > 0)
    {
        write(outfd,buf,n);
    }

    close(infd);
    close(outfd);

    unlink("./P2");//删除管道文件
    return 0;
}


