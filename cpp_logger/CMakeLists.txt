cmake_minimum_required(VERSION 3.28)
project(cpp_logger)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXE_LINKER_FLAGS "-static") # Add this so that you can actually run the .exe located in the "cmake-build-debug" folder.

add_executable(cpp_logger main.cpp)
