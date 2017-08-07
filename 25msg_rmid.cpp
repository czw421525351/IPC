//
// Created by chenziwei on 17-6-20.
//

#include "common.h"

int main()
{
    int msgid;
    msgid = msgget(1234,0);
    if(msgid == -1)
        ERR_EXIT("msgget");

    printf("msgget success\n");
    printf("msgid=%d\n",msgid);

    msgctl(msgid,IPC_RMID, nullptr);//通过程序删除ipc对象
    return 0;
}
