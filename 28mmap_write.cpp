//
// Created by chenziwei on 17-6-21.
//

#include "common.h"

typedef struct Student
{
    char name[4];
    int age;
}STU;

int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: %s <file>\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    int fd;
    fd = open(argv[1],O_CREAT|O_RDWR|O_TRUNC,0666);
    if(fd == -1)
        ERR_EXIT("open");

    lseek(fd,sizeof(STU)*5-1,SEEK_SET);//从文件的头开始 定位到39这个位置
    write(fd,"",1);

    STU* p;
    p = (STU*)mmap(NULL,sizeof(STU)*5,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(p == NULL)
        ERR_EXIT("mmap");

    //此时对文件的访问就好像对内存的访问
    char ch = 'a';
    int i;
    for(int i = 0; i < 10;++i)
    {
        memcpy((p+ i%5)->name,&ch,1);
        (p+i)->age = 20+i;
        ++ch;
    }
    printf("initialize over\n");
    munmap(p,sizeof(STU)*5);
    printf("exit ...\n");

    return 0;
}