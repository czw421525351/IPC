//
// Created by czw-cpp on 17-8-6.
//


#include "common.h"


//实现一个功能 在SIGINT信号处理过程中 屏蔽SIGQUIT信号
void INT_handler(int signo)
{
    printf("----------SIGINT----------\n");
    sleep(10);  //在10秒内按下ctral+\不会马上有反应
}

int main()
{
    struct sigaction sigact;
    sigact.sa_handler = INT_handler;
    sigemptyset(&sigact.sa_mask);
    sigaddset(&sigact.sa_mask,SIGQUIT);//在SIGINT信号处理过程中 屏蔽SIGQUIT信号!！! signal没有这种功能
    sigact.sa_flags = 0;

    if(sigaction(SIGINT,&sigact,NULL) < 0)
        ERR_EXIT("sigaction");

    for(;;)
        pause();

    return 0;
}
