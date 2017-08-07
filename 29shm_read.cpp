//
// Created by chenziwei on 17-6-22.
//

#include "common.h"


typedef struct stu
{
    char name[32];
    int age;
}STU;

int main()
{
//    shmget(1234,sizeof(STU),0);
    int shmid = shmget(1234,0,0);//如果不知道共享内存的大小，直接填0就行
    if(shmid == -1)
        ERR_EXIT("shmget");
    STU* p = NULL;
    p = (STU*)shmat(shmid,NULL,0);
    if(p == (void*)-1)
        ERR_EXIT("shmat");
    printf("name = %s, age = %d\n",p->name,p->age);

    memcpy(p,"quit",4);
    shmdt(p);

    return 0;
}