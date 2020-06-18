cmake_minimum_required(VERSION 3.16)
project(computer_network_program_exp3)

set(CMAKE_CXX_STANDARD 14)

add_executable(computer_network_program_exp3 main.cpp tcp_echo_srv.c test.c tcp_echo_cli.c)