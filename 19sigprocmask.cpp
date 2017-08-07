//
// Created by czw-cpp on 17-8-6.
//

#include "common.h"

/*
void INT_handler(int signo)
{
    printf("----------signo----------\n");
}

void printSigset(sigset_t* set)
{
    for(int i = 1; i< NSIG ; ++i)
    {
        if(sigismember(set,i))
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
}

int main()
{
    sigset_t sigset;
    sigset_t maskset;
    sigemptyset(&maskset);
    sigaddset(&maskset,SIGINT);

    if(signal(SIGINT,INT_handler) == SIG_ERR)
        ERR_EXIT("signal");
    sigprocmask(SIG_BLOCK,&maskset,NULL);//更改信号屏蔽字 此时即使SIGINT信号到了 也会被阻塞住 相应的pending位被置1 处于未决状态
    for(;;)
    {
        sigpending(&sigset);
        printSigset(&sigset);
        sleep(1);
    }

    return 0;
}
*/



void INT_handler(int signo)
{
    if(signo == SIGINT)
        printf("----------SIGINT----------\n");
    else//SIGQUIT
    {
        sigset_t unmaskset;
        sigemptyset(&unmaskset);
        sigaddset(&unmaskset,SIGINT);
        sigprocmask(SIG_UNBLOCK,&unmaskset,NULL);//效果是出来了  但是为什么这里解除了阻塞之后  下次SIGINT信号过来还是会阻塞
    }
}

void printSigset(sigset_t* set)
{
    for(int i = 1; i< NSIG ; ++i)
    {
        if(sigismember(set,i))
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
}

int main()
{
    sigset_t sigset;
    sigset_t maskset;
    sigemptyset(&maskset);
    sigaddset(&maskset,SIGINT);

    sigprocmask(SIG_BLOCK,&maskset,NULL);//更改信号屏蔽字 此时即使SIGINT信号到了 也会被阻塞住 相应的pending位被置1 处于未决状态

    if(signal(SIGINT,INT_handler) == SIG_ERR)
        ERR_EXIT("signal");
    if(signal(SIGQUIT,INT_handler) == SIG_ERR)
        ERR_EXIT("signal");

    for(;;)
    {
        sigpending(&sigset);
        printSigset(&sigset);
        sleep(1);
    }

    return 0;
}
