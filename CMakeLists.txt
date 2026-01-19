cmake_minimum_required(VERSION 4.2.1)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 23)

# Include Raylib headers
include_directories(build/external/raylib-master/src)

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/food.cpp
	src/snake.cpp
	src/gamestate.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)