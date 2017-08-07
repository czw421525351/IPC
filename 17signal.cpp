//
// Created by czw-cpp on 17-8-6.
//

#include "common.h"

void USR1_handler(int signo)
{
    printf("------%d------\n",signo);
}

int main()
{
    printf("------%d------\n",getpid());
    if(signal(SIGUSR1,USR1_handler) == SIG_ERR)
        ERR_EXIT("signal");

    pause();//等待信号
    printf("-----------\n");
    return 0;
}