//
// Created by czw-cpp on 17-8-6.
//


#include "common.h"

/* sigaction简单使用
void INT_handler(int signo)
{
    printf("----------SIGINT----------\n");
}

int main()
{
    struct sigaction sigact;
    sigact.sa_handler = INT_handler;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags = 0;

    if(sigaction(SIGINT,&sigact,NULL) < 0)
        ERR_EXIT("sigaction");

    for(;;)
        pause();

    return 0;
}
*/



//实际上 linux下signal信号安装函数也是可靠的，我们可以认为它底层也是用sigaction实现
//用sigaction 来模拟 signal


void INT_handler(int signo)
{
    printf("----------SIGINT----------\n");
}

//模拟signal 函数 注意signal的返回值
sighandler_t mysignal(int signum,sighandler_t handler)
{
    struct sigaction sigact;
    sigact.sa_handler = handler;
    sigact.sa_flags = 0;
    sigemptyset(&sigact.sa_mask);

    struct sigaction sigact_old;
    if(sigaction(signum,&sigact,&sigact_old) < 0)
        return SIG_ERR;
    return  sigact_old.sa_handler;
}


int main()
{
    if(mysignal(SIGINT,INT_handler) == SIG_ERR)
        ERR_EXIT("mysignal");

    for(;;)
        pause();

    return 0;
}


