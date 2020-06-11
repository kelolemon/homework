cmake_minimum_required(VERSION 3.16)
project(computer_network_program_exp1 C)

set(CMAKE_C_STANDARD 99)

add_executable(computer_network_program_exp1 main.c tcp_echo_srv.c tcp_echo_cli.c)