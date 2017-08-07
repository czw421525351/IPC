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

    struct msqid_ds buf;
    msgctl(msgid,IPC_STAT,&buf);            //把msgid_ds结构的数据设置为消息队列的当前关联值
    printf("mode = %o\n",buf.msg_perm.mode);//获取权限
    printf("cuurent byte of queue = %d\n",buf.__msg_cbytes);//当前队列的字节数
    printf("current number of messages = %d\n",buf.msg_qnum);//当前队列的消息数
    printf("maximum number of bytes allowed in queue = %d\n",buf.msg_qbytes);//队列允许的最大字节数

    return 0;
}
