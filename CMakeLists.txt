cmake_minimum_required(VERSION 3.8)
project(cdictionary)

set(CMAKE_C_STANDARD 99)

set(HEADERS dictionary.h storage_manager.h menu.h user_interactions.h)

set(SOURCE_FILES main.c storage_manager.c dictionary.c menu.c user_interactions.c)
add_executable(cdictionary ${SOURCE_FILES})