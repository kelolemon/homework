cmake_minimum_required(VERSION 3.16)
project(Computer_Network_task1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Computer_Network_task1 TCP_client.cpp TCP_server.cpp UDP_server.cpp)