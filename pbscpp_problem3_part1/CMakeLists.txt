cmake_minimum_required(VERSION 2.6)
project(problem3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pbscpp_problem3_part1 main.cpp)
add_executable(pbscpp_problem3_part1_alt main_alt.cpp)

target_link_libraries(pbscpp_problem3_part1 pthread)
target_link_libraries(pbscpp_problem3_part1_alt pthread)
