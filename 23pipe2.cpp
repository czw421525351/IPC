//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"

int main()
{
    int fds[2];
    pipe(fds);

    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        dup2(fds[0],STDIN_FILENO);//复制文件描述字
        close(fds[0]);            //此时关闭fds[0]也没关系
        close(fds[1]);            //子进程不读，所以也关闭
        execlp("wc","wc","-w",NULL); //默认是从stdin中读取数据，但是dup2将stdin重定向到fds[0]
                                    //所以就是从fds[0]中读取数据
        exit(EXIT_FAILURE);
    }

    dup2(fds[1],STDOUT_FILENO);   //将stdout重定向到fds[1]
    close(fds[0]);
    close(fds[1]);
    execlp("ls","ls",NULL);  //默认是输出到stdout，但是dup2将stdout重定向到fds[1]
                                  //所以就是往fds[1]中写入数据

    return 0;
}

