cmake_minimum_required(VERSION 3.20)

project(EtexUI)
set(CMAKE_CXX_STANDARD 23)

add_executable(EtexUI
    src/main.cpp
    src/core/Buffer.cpp
    src/core/Cursor.cpp
    src/core/Editor.cpp
    src/core/Terminal.cpp
    src/core/Input.cpp
)
