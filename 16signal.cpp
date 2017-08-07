//
// Created by czw-cpp on 17-8-6.
//

#include "common.h"

int flag = false;
void INT_handler(int signo)
{
    printf("----%d----\n",signo);
    flag = true;
}

int main()
{
    printf("----pid: %d ----\n",getpid());

    __sighandler_t old_handler;
    if((old_handler = signal(SIGINT,INT_handler)) == SIG_ERR)
        ERR_EXIT("signal");
    while(!flag)
        ;
    signal(SIGINT,old_handler);

    for (;;)
        ;
    return 0;
}