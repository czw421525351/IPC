//
// Created by chenziwei on 17-6-16.
//

#include "common.h"

int main()
{
    int msgid;
    msgid = msgget(1234,0666 | IPC_CREAT);                   //0666是权限 跟open函数类似

//    msgid = msgget(123,0666 | IPC_CREAT | IPC_EXCL);        //如果消息队列存在，就会出错

//    msgid = msgget(IPC_PRIVATE,0666 | IPC_CREAT | IPC_EXCL);  //IPC_PRIVATE表示每次都会创建一个新的消息队列，以下写法都是一样的效果
//    msgid = msgget(IPC_PRIVATE,0666 | IPC_CREAT);
//    msgid = msgget(IPC_PRIVATE,0666);




//    msgid = msgget(1234,0400 | IPC_CREAT);//创建一个0400
//    msgid = msgget(1234,0600);            //用0600打开，发现没有权限
//    msgid = msgget(1234,0);                 //标志指定为0，表示按照创建的方式去打开队列
    if(msgid == -1)
        ERR_EXIT("msgget");
    printf("msgget success : %d\n",msgid);

    return 0;
}