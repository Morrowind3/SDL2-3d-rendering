cmake_minimum_required(VERSION 3.7)
project(LinAlg)

include_directories(external/include)
link_directories(external/lib/x86)

set(VIEW src/view/GraphPlotter.cpp)
set(SOURCE  src/algebra/MathsVector.cpp src/algebra/MathsVector.h src/algebra/Matrix.cpp InvalidMatrixDimensionsException.h src/algebra/Transform.cpp src/algebra/Transform.h)
add_executable(LinAlg Main.cpp ${SOURCE} ${VIEW})
add_executable(Tests tests/AlgebraTests.cpp ${SOURCE})

target_link_libraries(LinAlg PRIVATE SDL2)





