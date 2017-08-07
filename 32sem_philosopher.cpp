//
// Created by czw-cpp on 17-8-6.
//

#include "common.h"

union semun
{
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
};

#define DELAY ((rand() % 5 + 1))

int semid;

void wait_for_2fork(int no)
{
    int left = no;
    int right = (no + 1)%5;

    sembuf buf[2] = {{left,-1,0},{right,-1,0}};
    semop(semid,buf,2);     //解决哲学家问题的方式:仅当两边的叉子都可获得时才吃饭 就不会死锁
}

void free_for_2fork(int no)
{
    int left = no;
    int right = (no + 1)%5;

    sembuf buf[2] = {{left,1,0},{right,1,0}};
    semop(semid,buf,2);
}

void philosopher(int no)
{
    srand(getpid());

    for(;;)
    {

        printf("%d is thinking...\n",no);
        sleep(DELAY);
        printf("%d is hungry...\n",no);
        wait_for_2fork(no);
        printf("%d is eating... \n",no);
        sleep(DELAY);
        free_for_2fork(no);

    }
}



int main()
{
    semid = semget(IPC_PRIVATE,5,IPC_CREAT|IPC_EXCL|0666);
    if(semid == -1)
        ERR_EXIT("semget");

    semun su;
    su.val = 1;

    for (int i = 0; i < 5; ++i)
        semctl(semid,i,SETVAL,su);

    int no = 0;
    pid_t pid;
    for(int i = 1;i < 5; ++i)
    {
        pid = fork();
        if(pid == -1)
            ERR_EXIT("fork");
        if(pid == 0)
        {
            no = i;
            break;
        }
    }
    //5个进程都跑到这里
    philosopher(no);
    return 0;
}