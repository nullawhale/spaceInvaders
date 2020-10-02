cmake_minimum_required(VERSION 3.17)
project(spaceInvaders)

set(CMAKE_CXX_STANDARD 17)

add_executable(spaceInvaders
        src/Main.cpp
        src/Vec.h
        src/Constants.h
        src/LoadTexture.h src/LoadTexture.cpp
        src/Player.h src/Player.cpp
        src/CircleBlock.h src/CircleBlock.cpp
        src/Block.h src/Block.cpp
        src/CheckCollision.h src/CheckCollision.cpp
        src/World.h src/World.cpp
        src/Bullet.h src/Bullet.cpp
        src/Shader.h src/Shader.cpp)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS} ${GLFW3_INCLUDE_DIRS})

target_link_libraries(spaceInvaders ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLM_LIBRARIES} ${GLFW3_LIBRARY} glfw)