//
// Created by chenziwei on 17-6-21.
//

#include "common.h"


typedef struct stu
{
    char name[32];
    int age;
}STU;

int main()
{
    int shmid;
    shmid = shmget(1234,sizeof(STU),IPC_CREAT|0666);
    if(shmid == -1)
        ERR_EXIT("shmid");

    STU* p = NULL;
    p = (STU*)shmat(shmid,NULL,0);
    if(p == (void*)-1)
        ERR_EXIT("shmat");

    printf("-----------SHMLBA:%d-----------\n",SHMLBA);

    //此时对共享内存的访问就是对指针p的访问
    strcpy(p->name,"lisi");
    p->age = 20;

    while(1)
    {
        sleep(2);
        if(memcmp(p,"quit",4) == NULL)
            break;
    }
    shmdt(p);
    shmctl(shmid,IPC_RMID, nullptr);
    return 0;
}
