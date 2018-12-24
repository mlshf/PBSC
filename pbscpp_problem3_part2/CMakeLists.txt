cmake_minimum_required(VERSION 2.6)
project(problem3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(pbscpp_problem3_part2
    main.cpp
    src/IProduct.cpp
    src/IShop.cpp)

target_link_libraries(pbscpp_problem3_part2 pthread gtest)

target_include_directories(pbscpp_problem3_part2 PRIVATE
    googletest/googletest/include)

add_subdirectory(googletest)
