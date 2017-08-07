//
// Created by chenziwei on 17-6-20.
//

#include "common.h"

int main(int argc,char *argv[])
{
    int flag = 0;
    int type = 0;
    int opt;

    while(1)
    {
                                      //getopt 是命令行参数解析函数
        opt = getopt(argc,argv,"n:t:");//26msg_recv -n -t 2
        if(opt == '?')                //如果解析到了一个不认识的参数
            exit(EXIT_FAILURE);
        if(opt == -1)                 //如果解析完毕
            break;
        switch(opt) {
            case 'n':                 //
//                printf("AAA\n");
                flag |= IPC_NOWAIT;
                break;
            case 't':                 //
//                printf("BBB\n");
//                int n = atoi(optarg);
//                printf("n=%d\n",n);
                type = atoi(optarg);
                printf("type == %d \n",type);
                break;
        }
    }

    const int msgMax = 8192;
    int msgid = msgget(1234,0);
    if(msgid == -1)
        ERR_EXIT("msgget");
    struct msgbuf* bufptr = static_cast<msgbuf*>(malloc(sizeof(long) + msgMax));
    int n = 0;
    if((n = msgrcv(msgid,bufptr,msgMax,type,flag)) < 0)
        ERR_EXIT("mrgrcv");
    printf("read %d bytes type = %ld\n",n,bufptr->mtype);

    return 0;
}