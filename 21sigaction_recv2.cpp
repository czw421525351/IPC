//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"

void handler(int signo)
{
    if(signo == SIGINT || signo == SIGRTMIN)
        printf("---recv %d---\n",signo);
    else
    {
        sigset_t set;
        sigemptyset(&set);
        sigaddset(&set,SIGINT);
        sigaddset(&set,SIGRTMIN);
        sigprocmask(SIG_UNBLOCK,&set,NULL);
    }
}




int main()
{
    printf("pid %d\n",getpid());

    struct sigaction sigact;
    sigact.sa_handler = handler;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags = 0;


    sigset_t maskset;
    sigemptyset(&maskset);
    sigaddset(&maskset,SIGINT);
    sigaddset(&maskset,SIGRTMIN);
    sigprocmask(SIG_BLOCK,&maskset,NULL);


    if(sigaction(SIGINT,&sigact,NULL) < 0)    //不可靠信号 不会排队 信号丢失
        ERR_EXIT("sigaction");
    if(sigaction(SIGRTMIN,&sigact,NULL) < 0) //可靠信号 会排队接受
        ERR_EXIT("sigaction");
    if(sigaction(SIGUSR1,&sigact,NULL) < 0) //可靠信号
        ERR_EXIT("sigaction");

    for(;;)
        pause();
    return 0;
}