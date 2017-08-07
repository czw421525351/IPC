//
// Created by czw-cpp on 17-8-5.
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

//创建一个信号量集 跟 打开一个信号量集分开
//这函数只用来创建信号量集 而不做打开功能 且不允许创建两次

//当只有IPC_CREAT选项打开时,不管是否已存在该块共享内存，则都返回该共享内存的ID，若不存在则创建共享内存
//当只有IPC_EXCL选项打开时，不管有没有该快共享内存，shmget()都返回-1
//所以当IPC_CREAT | IPC_EXCL时, 如果没有该块共享内存，则创建，并返回共享内存ID。若已有该块共享内存，则返回-1；

int sem_create(key_t key)
{
    int semid;
    semid = semget(key,1,IPC_CREAT | IPC_EXCL | 0666);
    if (semid == -1)
        ERR_EXIT("semget");

    return semid;
}

//只用于打开一个信号量集 不能用于创建信号量集
int sem_open(key_t key)
{
    int semid;
    semid = semget(key,0,0);//因为只打开已存在的信号量集 所以可以不指定信号量集的个数，第二个参数填0就好，第三个参数也填0就好
    if(semid == -1)
        ERR_EXIT("semget");

    return semid;
}

int sem_setval(int semid, int val)
{
    semun su;
    su.val = val;
    int ret;

    ret = semctl(semid,0,SETVAL,su);
    if(ret == -1)
        ERR_EXIT("sem_setval");
    return ret;
}

int sem_getval(int semid)
{
    int ret;
    ret = semctl(semid,0,GETVAL);
    if(ret == -1)
        ERR_EXIT("sem_getval");
    return ret;
}

int sem_delete(int semid)
{
    int ret;
    ret = semctl(semid,0,IPC_RMID);
    if(ret == -1)
        ERR_EXIT("sem_rmid");
    return 0;
}

int sem_p(int semid)
{
    struct sembuf sb = {0,-1,0};
//    struct sembuf sb = {0,-1,IPC_NOWAIT};
//    struct sembuf sb = {0,-1,SEM_UNDO};

    int ret;
    ret = semop(semid,&sb,1);
    if(ret == -1)
        ERR_EXIT("semop_p");
    return ret;
}


int sem_v(int semid)
{
    struct sembuf sb = {0,1,0};
    int ret;
    ret = semop(semid,&sb,1);
    if(ret == -1)
        ERR_EXIT("semop_v");
    return ret;
}

int main()
{
    int semid;

//    key_t key = ftok(".",'s');
//    semid = sem_create(key);
    semid = sem_create(IPC_PRIVATE);
    semid = sem_create(IPC_PRIVATE);
    semid = sem_create(IPC_PRIVATE);
    semid = sem_create(IPC_PRIVATE);
    sleep(5);
    //sem_delete(semid);
    sem_setval(semid,10);
    cout << sem_getval(semid) << endl;
    sem_delete(semid);

    return 0;
}
