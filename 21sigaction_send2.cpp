//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"

int main(int argc,char** args)
{
    if(argc < 2)
    {
        fprintf(stderr,"usage:%s pid",args[0]);
        ERR_EXIT("usage");
    }

    pid_t pid = atoi(args[1]);
    sigval_t val;
    val.sival_int = 100;

    sigqueue(pid,SIGINT,val);//发送信号
    sigqueue(pid,SIGINT,val);//发送信号
    sigqueue(pid,SIGINT,val);//发送信号
    sigqueue(pid,SIGRTMIN,val);//发送信号
    sigqueue(pid,SIGRTMIN,val);//发送信号
    sigqueue(pid,SIGRTMIN,val);//发送信号
    sleep(10);
    kill(pid,SIGUSR1);
    return 0;
}
