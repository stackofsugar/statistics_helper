cmake_minimum_required(VERSION 3.16)

set(SRC_Fs
    "main"
    "binomial"
)

set(SRC_FILE "")
foreach(SRC_F IN LISTS SRC_Fs)
    set(SRC_FILE ${SRC_FILE} "${CMAKE_CURRENT_SOURCE_DIR}/src/${SRC_F}.cpp")
endforeach()

project(StaticsHelper)
add_executable(StaticsHelper ${SRC_FILE})
target_include_directories(StaticsHelper PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")