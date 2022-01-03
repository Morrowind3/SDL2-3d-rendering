cmake_minimum_required(VERSION 3.7)
project(ThreeDee)

include_directories(external/include)
link_directories(external/lib/x86)

set(MATRIX_SOURCE  src/algebra/MathsVector.cpp src/algebra/Matrix.cpp src/algebra/InvalidMatrixDimensionsException.h src/algebra/Transform.cpp src/algebra/Transform.h )
add_library(Matrices STATIC ${MATRIX_SOURCE})

set(VIEW_SOURCE src/view/Rendering.cpp src/view/RenderingStrategies/RenderingStrategy.h
        src/view/RenderingStrategies/TopView.cpp src/view/RenderingStrategies/SideView.cpp
        src/view/RenderingStrategies/FrontView.cpp src/view/RenderingStrategies/RenderingStrategy.cpp src/view/Entities/Mesh.h src/view/Entities/Spaceship.cpp src/view/Entities/Spaceship.h src/view/Entities/Entity.h src/view/Entities/Mesh.cpp src/view/Entities/Entity.cpp src/view/World.cpp src/view/World.h)
add_executable(ThreeDee Main.cpp ${VIEW_SOURCE})
add_executable(Tests tests/AlgebraTests.cpp ${MATRIX_SOURCE})

target_link_libraries(ThreeDee PRIVATE SDL2 Matrices)





