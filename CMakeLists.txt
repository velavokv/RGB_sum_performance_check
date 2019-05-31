cmake_minimum_required(VERSION 2.6)

set(sources
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/saturated_sum.cpp
)
add_executable(Performance_check ${sources})
