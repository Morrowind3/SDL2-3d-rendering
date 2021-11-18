cmake_minimum_required(VERSION 3.7)
project(LinAlg)

include_directories(external/include)
link_directories(external/lib/x86)

add_executable(LinAlg Main.cpp view/GraphPlotter.cpp MathsVector.cpp MathsVector.h)
target_link_libraries(LinAlg PRIVATE SDL2)





