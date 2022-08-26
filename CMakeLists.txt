cmake_minimum_required(VERSION 3.7)
project(ThreeDee)

include_directories(external/include)
include_directories(external/SDL2_gfx)
link_directories(external/lib/x86)
link_directories(external/SDL2_gfx)

set(MATRIX_SOURCE  src/algebra/MathsVector.cpp src/algebra/Matrix.cpp src/algebra/InvalidMatrixDimensionsException.h src/algebra/Transform.cpp src/algebra/Transform.h )
add_library(Matrices STATIC ${MATRIX_SOURCE})

set(SDL2_GFX_SOURCE external/SDL2_gfx/SDL2_gfxPrimitives.c external/SDL2_gfx/SDL2_imageFilter.c external/SDL2_gfx/SDL2_rotozoom.c)
add_library(SDL2_GFX STATIC ${SDL2_GFX_SOURCE})

target_link_libraries(SDL2_GFX PRIVATE SDL2)


set(MODEL_SOURCE src/model/Entities/Spaceship.cpp src/model/Entities/Mesh.cpp src/model/Entities/Entity.cpp src/model/World.cpp src/input/Input.cpp src/input/InputRegistry.cpp src/input/KeyCode.hpp src/input/PressState.hpp
        src/model/Entities/MeshPane.cpp )
set(VIEW_SOURCE src/view/Rendering.cpp src/view/RenderingStrategies/RenderingStrategy.h
        src/view/RenderingStrategies/TopView.cpp src/view/RenderingStrategies/SideView.cpp
        src/view/RenderingStrategies/FrontView.cpp src/view/RenderingStrategies/RenderingStrategy.cpp src/view/Camera.cpp src/view/RenderingStrategies/CameraView.cpp src/view/RenderingStrategies/CameraView.h )
add_executable(ThreeDee Main.cpp ${VIEW_SOURCE} ${MODEL_SOURCE} src/env.hpp)
add_executable(Tests tests/AlgebraTests.cpp ${MATRIX_SOURCE})

target_link_libraries(ThreeDee PRIVATE SDL2 Matrices SDL2_GFX)





