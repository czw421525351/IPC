//
// Created by chenziwei on 17-6-20.
//

#include "common.h"

//struct msgbuf
//{
//    long mtype;
//    char mtex[1];
//};

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        fprintf(stderr,"Usages: %s <bytes> <type>\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    int len = atoi(argv[1]);
    int type = atoi(argv[2]);

    int msgid;
    msgid = msgget(1234,0);
    if(msgid == -1)
        ERR_EXIT("msgget");
    struct msgbuf *ptr;
    ptr = static_cast<msgbuf*>(malloc(sizeof(long) + len));
    ptr->mtype = type;
//    if(msgsnd(msgid,ptr,len,0) < 0)
//    if(msgsnd(msgid,ptr,len,IPC_NOWAIT))//不阻塞
      if(msgsnd(msgid,ptr,len,IPC_NOWAIT|MSG_NOERROR) < 0)
        ERR_EXIT("msgsnd");

    return 0;
}