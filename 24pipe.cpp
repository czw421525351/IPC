//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"

//int main()
//{
//    int pipefds[2];
//    if(pipe(pipefds) < 0)
//        ERR_EXIT("pipe");
//
//    pid_t pid;
//    if((pid = fork()) < 0)
//        ERR_EXIT("fork");
//    if(pid == 0)
//    {
//        sleep(3);
//        close(pipefds[0]);
//        char buf[10] = "hello";
//        write(pipefds[1],buf,strlen(buf));
//        /*实验一下发现也可以自写自读
//        char buf2[10] = {0};
//        read(pipefds[0],buf2,sizeof(buf2));
//        printf("child recv %s\n",buf2);
//        */
//        exit(EXIT_SUCCESS);
//    }
//
//    close(pipefds[1]);
//    char buf[10] = {0};
//    read(pipefds[0],buf,sizeof(buf));   //没数据到来时会阻塞
//    printf("father recv %s\n",buf);
//
//    return 0;
//}


//将管道文件描述符设置为 NONBLOCK
/*
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
        sleep(5);       //这里故意等待5s
        close(pipefds[0]);
        char buf[10] = "hello";
        write(pipefds[1],buf,strlen(buf));

        exit(EXIT_SUCCESS);
    }

    close(pipefds[1]);
    char buf[10] = {0};

    int flags = fcntl(pipefds[0],F_GETFL);//现获取文件描述符的标志
    fcntl(pipefds[0],F_SETFL,flags | O_NONBLOCK);

    int ret = read(pipefds[0],buf,sizeof(buf));
    if(ret == -1 && errno == EAGAIN)
        ERR_EXIT("read");

    printf("father recv %s\n",buf);

    return 0;
}
*/


//如果所有的管道写端对应的文件描述符被关闭，则read返回0
/*
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
        close(pipefds[1]);      //关闭写端
        exit(EXIT_SUCCESS);
    }

    close(pipefds[1]);          //关闭写端
    sleep(1);

    char buf[10] = {0};
    int ret = read(pipefds[0],buf,sizeof(buf));
    printf("read %d\n",ret);//read 返回0  意思是读到了文件末尾

    return 0;
}
*/


//如果管道中所有的读端被关闭  则写入数据时会产生SIGPIPE信号

void handler(int signo)
{
    printf("-------%d-------\n",signo);
}

int main()
{
    //signal(SIGPIPE,handler);

    int pipefds[2];
    if(pipe(pipefds) < 0)
        ERR_EXIT("pipe");

    pid_t pid;
    if((pid = fork()) < 0)
        ERR_EXIT("fork");
    if(pid == 0)
    {
        close(pipefds[0]);      //关闭读端
        exit(EXIT_SUCCESS);
    }

    close(pipefds[0]);          //关闭读端
    sleep(1);
    char buf[10] = {0};

    int ret = write(pipefds[1],buf,sizeof(buf));//触发了SIGPIPE信号  终止进程
    if(ret == -1)
        ERR_EXIT("write");


}



//验证一下管道的容量
