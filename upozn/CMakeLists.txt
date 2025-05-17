cmake_minimum_required(VERSION 3.30)
project(upozn C)

set(CMAKE_C_STANDARD 11)

add_executable(upozn main.c operating_mode.c validators.c animations.c task_operations.c getch_unix_without_conio.c
tasks_sorting_q_sort.c auxiliary.c save_load_to_files.c)
