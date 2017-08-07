//
// Created by chenziwei on 17-6-20.
//

#include "common.h"

int main()
{
    int msgid;
    msgid = msgget(123,0);
    if(msgid == -1)
        ERR_EXIT("msgget");

    printf("msgget success\n");
    printf("msgid=%d\n",msgid);

    struct msqid_ds buf;
    msgctl(msgid,IPC_STAT,&buf);            //先获取状态
    printf("current mode = %o\n",buf.msg_perm.mode);
    sscanf("444","%o",&buf.msg_perm.mode);  //改变权限
    msgctl(msgid,IPC_SET,&buf);             //再设置状态

    struct msqid_ds buf2;
    msgctl(msgid,IPC_STAT,&buf2);
    printf("current mode = %o\n",buf2.msg_perm.mode);//状态确实改变了

    return 0;
}

