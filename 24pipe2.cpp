//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"


//测试pipe的缓冲区有多大
int main()
{
    int fds[2];
    pipe(fds);

    int flags = fcntl(fds[1],F_GETFL);
    fcntl(fds[1],F_SETFL,flags|O_NONBLOCK);

    int count = 0;
    while(1)
    {
        char data = '1';
        int ret ;
        ret = write(fds[1],&data,1);
        if(ret == -1 && errno == EAGAIN)//当pipe是O_NONBLOCK 缓冲区满的时候返回-1 errno=EAGAIN
            break;
        ++count;
    }
    printf("----%d----\n",count);//65536 64k的容量
    return 0;
}
