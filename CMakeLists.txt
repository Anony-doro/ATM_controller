cmake_minimum_required(VERSION 3.30)
project(ATM_controller)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
        BankSys.hpp
        BankSys.cpp
        ATM_control.cpp
        ATM_control.hpp
        main.cpp
)

include_directories(.)

add_executable(ATM_App ${SOURCE_FILES})