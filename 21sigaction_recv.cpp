//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"

void INT_handler(int signo)
{
    printf("----------SIGINT----------\n");
}

void handler(int sig, siginfo_t * info, void * ctx)
{
    fprintf(stdout,"recv:signal %d,value %d \n",sig,info->si_value.sival_int);
}


int main()
{
    struct sigaction sigact;
//    sigact.sa_handler = INT_handler;
    sigact.sa_sigaction = handler;          //使用第二种信号回调函数 回调函数可以接收到数据
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO;           //回调函数要想接受数据 要指定这个标志

    printf("pid %d\n",getpid());

    if(sigaction(SIGINT,&sigact,NULL) < 0)
        ERR_EXIT("sigaction");

    for(;;)
        pause();

    return 0;
}
