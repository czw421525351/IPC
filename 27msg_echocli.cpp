//
// Created by chenziwei on 17-6-20.
//

#include <cstring>
#include "common.h"

//struct msgbuf
//{
//    long mtype;
//    char mtex[1];
//};

#define MSGMAX 8192
void echo_cli(int msgid)
{
    int pid;
    pid = getpid();
    int n = 0;

    struct msgbuf msg;
    memset(&msg,0,sizeof(msg));
    msg.mtype = 1;
    *((int*)msg.mtext) = pid;
    while(fgets(msg.mtext+4,MSGMAX-4,stdin) != NULL)
    {
        if(msgsnd(msgid,&msg,4 + strlen(msg.mtext+4),0) < 0)
            ERR_EXIT("msgsnd");

        memset(msg.mtext+4,0,MSGMAX-4);
        if((n = msgrcv(msgid, &msg, MSGMAX, pid,0)) < 0)
            ERR_EXIT("msgrcv");
        fputs(msg.mtext+4, stdout);
        memset(msg.mtext+4, 0, MSGMAX-4);
    }
}

int main(int argc, char* argv[])
{
    int msgid;
    msgid = msgget(1234,0);
    if(msgid == -1)
        ERR_EXIT("msgget");
    echo_cli(msgid);

    return 0;
}

