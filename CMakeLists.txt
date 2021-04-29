cmake_minimum_required(VERSION 3.10)

# set the project name
project(Test)

# add the executable
add_executable(Test main.cpp)

# link to tmxlite
set(TMXLITE_PATH "../tmxlite")
set(TMXLITE_LIBS_PATH "${TMXLITE_PATH}/build")

target_include_directories(Test PRIVATE "${TMXLITE_PATH}/include")
target_link_directories(Test PRIVATE "${TMXLITE_LIBS_PATH}")
target_link_libraries(Test tmxlite)