//
// Created by czw-cpp on 17-8-6.
//

#include "common.h"

/*
void ALARM_handler(int signo)
{
    printf("------%d------\n",signo);
    alarm(2);
}

int main()
{
    printf("------%d------\n",getpid());

    if(signal(SIGALRM,ALARM_handler) == SIG_ERR)
        ERR_EXIT("signal");

    alarm(2);
    for(;;)
        pause();

    return 0;
}
 */

struct Test
{
    int a;
    int b;
    int c;
};

Test test;

//为了程序的稳定性，信号处理函数尽量使用可重入代码
//不可重入代码演示
void ALARM_handler(int signo)
{
    printf("------a = %d------b = %d------c = %d\n",test.a,test.b,test.c);
    alarm(1);
}

int main()
{
    Test zero = {0,0,0};
    Test one = {1,1,1};

    if(signal(SIGALRM,ALARM_handler) == SIG_ERR)
        ERR_EXIT("signal");

    alarm(1);
    for(;;)
    {
        test = zero;
        test = one;
    }

    return 0;
}