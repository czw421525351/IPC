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
//    if(argc != 2)
//    {
//        fprintf(stderr,"Usage: %s <file>\n",argv[0]);
//        exit(EXIT_FAILURE);
//    }
    int fd;
    fd = open("./test.txt",O_RDWR,0666);
    if(fd == -1)
        ERR_EXIT("open");

    STU* p;
    p = (STU*)mmap(NULL,sizeof(STU)*5,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(p == NULL)
        ERR_EXIT("mmap");

    //此时对文件的访问就好像对内存的访问
//    char ch = 'a';
    for(int i = 0; i < 5;++i)
        printf("name = %s, age = %d\n",(p+i)->name,(p+i)->age);

    munmap(p,sizeof(STU)*5);
    printf("exit ...\n");

    return 0;
}
