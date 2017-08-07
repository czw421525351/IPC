//
// Created by czw-cpp on 17-8-7.
//

#include "common.h"

int main()
{
    //execlp("ls","ls",NULL);
    execlp("ps","ps","-ef",NULL);
    return 0;
}