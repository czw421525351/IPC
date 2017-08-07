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
    printf("get val %d\n",ret);
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


// sem_op 通常是 -n +n 但也可以是0 表示阻塞直到信号量为0
//struct sembuf
//{
//    unsigned short int sem_num;	/* semaphore number */
//    short int sem_op;		/* semaphore operation */
//    short int sem_flg;		/* operation flag */
//};


int sem_p(int semid)
{
    struct sembuf sb = {0,-1,0};
//    struct sembuf sb = {0,-1,IPC_NOWAIT};
    //struct sembuf sb = {0,-1,SEM_UNDO};

    int ret;
    ret = semop(semid,&sb,1);
    if(ret == -1)
        ERR_EXIT("semop_p");
    return ret;
}


int sem_v(int semid)
{
    struct sembuf sb = {0,1,0};
    //struct sembuf sb = {0,1,SEM_UNDO};

    int ret;
    ret = semop(semid,&sb,1);
    if(ret == -1)
        ERR_EXIT("semop_v");
    return ret;
}


int sem_getmode(int semid)
{
    semun su;
    semid_ds sem;
    su.buf = &sem;
    int ret = semctl(semid,0,IPC_STAT,su);
    if(ret == -1)
        ERR_EXIT("sem_setmode");
    printf("current permissions is %o\n",su.buf->sem_perm.mode);
    return ret;
}

int sem_setmode(int semid,char mode[])
{
    /*
    semun su;
    struct semid_ds sem;
    su.buf = &sem;
    int ret = semctl(semid,0,IPC_STAT,su);
    if(ret == -1)
        ERR_EXIT("sem_setmode");
    printf("current permissions is %o\n",su.buf->sem_perm.mode);
     */
    sem_getmode(semid);
    semun su;
    semid_ds sem;
    su.buf = &sem;
    sscanf(mode,"%o",(unsigned int*)&(su.buf->sem_perm.mode));
    int ret = semctl(semid,0,IPC_SET,su);
    if(ret == -1)
        ERR_EXIT("sem_setmode");
    printf("permissions update...\n");
    return ret;
}

void usage()
{
    fprintf(stderr,"usage:\n");
    fprintf(stderr,"semtool -c\n");
    fprintf(stderr,"semtool -d\n");
    fprintf(stderr,"semtool -p\n");
    fprintf(stderr,"semtool -v\n");
    fprintf(stderr,"semtool -s <value>\n");
    fprintf(stderr,"semtool -g\n");
    fprintf(stderr,"semtool -f\n");
    fprintf(stderr,"semtool -m <mode>\n");

}

int main(int argc,char*argv[])
{
    int opt;
    opt = getopt(argc,argv,"cdpvs:gfm:");
    if(opt =='?')
        exit(EXIT_FAILURE);
    if (opt == -1)
    {
        usage();
        exit(EXIT_FAILURE);
    }
    key_t key = ftok(".",'h');
    int semid;
    switch (opt)
    {
        case 'c':
            semid = sem_create(key);
            break;
        case 'p':
            semid = sem_open(key);
            sem_p(semid);
            sem_getval(semid);
            break;
        case 'v':
            semid = sem_open(key);
            sem_v(semid);
            sem_getval(semid);
            break;
        case 'd':
            semid = sem_open(key);
            sem_delete(semid);
            break;
        case 's':
            semid = sem_open(key);
            sem_setval(semid,atoi(optarg));
            break;
        case 'g':
            semid = sem_open(key);
            sem_getval(semid);
            break;
        case 'f':
            semid = sem_open(key);
            sem_getmode(semid);
            break;
        case 'm':
            semid = sem_open(key);
            sem_setmode(semid,argv[2]);//optarg
            break;
    }
    return 0;
}