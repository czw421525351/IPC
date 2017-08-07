//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"

int main()
{
    close(0);
    open("Makefile",O_RDONLY);
    close(1);
    open("Makefile2",O_RDWR|O_CREAT|O_TRUNC,0644);

    execlp("cat","cat",NULL);//cat 不带参数 从stdin读数据 往stdout写数据  但是这两个都被重定向到Makefile文件了
                            //所以这个程序的功能就是拷贝
    return  0;
}