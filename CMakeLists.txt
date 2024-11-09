cmake_minimum_required(VERSION 3.29)
project(UniWorkC C)

set(CMAKE_C_STANDARD 11)

add_executable(Main main.c)
add_executable(Calculator Basics/Calculator.c)
add_executable(Lec2 LectureStuff/Lec2.c)
add_executable(AfterLec2 Exercises/AfterLec2.c)
add_executable(AfterLec3 Exercises/AfterLec3.c)
add_executable(Lec3 LectureStuff/Lec3.c)
