cmake_minimum_required(VERSION 3.7)
project(ThreeDee)

include_directories(external/include)
link_directories(external/lib/x86)

set(MATRIX_SOURCE  src/algebra/MathsVector.cpp src/algebra/Matrix.cpp src/algebra/InvalidMatrixDimensionsException.h src/algebra/Transform.cpp src/algebra/Transform.h )
add_library(Matrices STATIC ${MATRIX_SOURCE})

set(MODEL_SOURCE src/model/Entities/Spaceship.cpp src/model/Entities/Mesh.cpp src/model/Entities/Entity.cpp src/model/World.cpp src/input/Input.cpp src/input/InputRegistry.cpp src/input/KeyCode.hpp src/input/PressState.hpp)
set(VIEW_SOURCE src/view/Rendering.cpp src/view/RenderingStrategies/RenderingStrategy.h
        src/view/RenderingStrategies/TopView.cpp src/view/RenderingStrategies/SideView.cpp
        src/view/RenderingStrategies/FrontView.cpp src/view/RenderingStrategies/RenderingStrategy.cpp src/view/Camera.cpp src/view/RenderingStrategies/CameraView.cpp src/view/RenderingStrategies/CameraView.h)
add_executable(ThreeDee Main.cpp ${VIEW_SOURCE} ${MODEL_SOURCE} src/env.hpp)
add_executable(Tests tests/AlgebraTests.cpp ${MATRIX_SOURCE})

target_link_libraries(ThreeDee PRIVATE SDL2 Matrices)





