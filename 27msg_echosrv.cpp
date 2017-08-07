//
// Created by chenziwei on 17-6-20.
//

#include <cstring>
#include "common.h"

#define MSGMAX 8192

//struct msgbuf               //error previous definition of ‘struct msgbuf’
//{
//    long mtype;
//    char mtext[MSGMAX];
//};

void echo_srv(int msgid)
{
    struct msgbuf msg;
    memset(&msg,0,sizeof(msg));
    while(1)
    {
        int n = 0;
        if((n = msgrcv(msgid,&msg,MSGMAX,1,0)) < 0)
            ERR_EXIT("msgrcv");

        int pid;
        pid = *((int*)msg.mtext);       //客户端的pid
        fputs(msg.mtext + 4, stdout);
        msg.mtype = pid;

        msgsnd(msgid,&msg,n,0);
        memset(msg.mtext,0,MSGMAX);
    }
}

int main(int argc,char *argv[])
{
    int msgid = msgget(1234,IPC_CREAT|0666);
    if(msgid == -1)
        ERR_EXIT("msgget");

    echo_srv(msgid);

    return 0;
}