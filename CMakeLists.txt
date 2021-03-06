cmake_minimum_required(VERSION 3.7)
project(IPC)

set(CMAKE_CXX_STANDARD 11)

add_executable(25msg_get 25msg_get.cpp)
add_executable(25msg_rmid 25msg_rmid.cpp)
add_executable(25msg_stat 25msg_stat.cpp)
add_executable(25msg_set 25msg_set.cpp)

add_executable(26msg_send 26msg_send.cpp)
add_executable(26msg_recv 26msg_recv.cpp)

add_executable(27msg_echosrv 27msg_echosrv.cpp)
add_executable(27msg_echocli 27msg_echocli.cpp)

add_executable(28mmap_write 28mmap_write.cpp)
add_executable(28mmap_read 28mmap_read.cpp)

add_executable(29shm_write 29shm_write.cpp)
add_executable(29shm_read 29shm_read.cpp)

add_executable(30sem 30sem.cpp)
add_executable(30semtool 30semtool.cpp)

add_executable(32sem_philosopher 32sem_philosopher.cpp)

add_executable(16signal 16signal.cpp)
add_executable(17signal 17signal.cpp)
add_executable(18alarm 18alarm.cpp)
add_executable(19sigprocmask 19sigprocmask.cpp)

add_executable(20sigaction 20sigaction.cpp)
add_executable(20sigaction2 20sigaction2.cpp)

add_executable(21sigaction_recv 21sigaction_recv.cpp)
add_executable(21sigaction_send 21sigaction_send.cpp)

add_executable(21sigaction_recv2 21sigaction_recv2.cpp)
add_executable(21sigaction_send2 21sigaction_send2.cpp)


add_executable(23pipe 23pipe.cpp)

add_executable(23pipe2 23pipe2.cpp)
add_executable(23pip3 23pip3.cpp)

add_executable(24pipe 24pipe.cpp)
add_executable(24pipe2 24pipe2.cpp)

add_executable(23exec 23exec.cpp)

add_executable(25FIFO_R 25FIFO_R.cpp)
add_executable(25FIFO_W 25FIFO_W.cpp)