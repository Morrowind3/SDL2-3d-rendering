cmake_minimum_required(VERSION 3.7)
project(ThreeDee)

include_directories(external/include)
link_directories(external/lib/x86)

set(MATRIX_SOURCE  src/algebra/MathsVector.cpp src/algebra/Matrix.cpp src/algebra/InvalidMatrixDimensionsException.h src/algebra/Transform.cpp src/algebra/Transform.h )
add_library(Matrices STATIC ${MATRIX_SOURCE})

set(MODEL_SOURCE src/Model/Entities/Spaceship.cpp src/Model/Entities/Mesh.cpp src/Model/Entities/Entity.cpp src/Model/World.cpp src/input/Input.cpp src/input/InputRegistry.cpp src/input/KeyCode.hpp src/input/PressState.hpp)
set(VIEW_SOURCE src/view/Rendering.cpp src/view/RenderingStrategies/RenderingStrategy.h
        src/view/RenderingStrategies/TopView.cpp src/view/RenderingStrategies/SideView.cpp
        src/view/RenderingStrategies/FrontView.cpp src/view/RenderingStrategies/RenderingStrategy.cpp  )
add_executable(ThreeDee Main.cpp ${VIEW_SOURCE} ${MODEL_SOURCE})
add_executable(Tests tests/AlgebraTests.cpp ${MATRIX_SOURCE})

target_link_libraries(ThreeDee PRIVATE SDL2 Matrices)





