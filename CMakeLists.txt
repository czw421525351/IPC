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