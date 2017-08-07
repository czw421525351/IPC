//
// Created by chenziwei on 17-6-16.
//

#ifndef IPC_COMMON_H
#define IPC_COMMON_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/ipc.h>
#include <sys/msg.h>    //for msgget

#include <sys/mman.h>	//for mmap

#include <sys/shm.h>    //for shmget

#include <sys/sem.h>    //for semget
#include <sys/wait.h>

#include <signal.h>      //for signal

#define ERR_EXIT(m) \
		do \
		{	\
			perror(m); \
			exit(EXIT_FAILURE); \
		}while(0)

#include <iostream>
using std::cout;
using std::endl;

#endif //IPC_COMMON_H
