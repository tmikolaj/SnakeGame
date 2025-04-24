cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML installed on the system (make sure SFML and SFML-devel are installed)
find_package(SFML COMPONENTS system window graphics REQUIRED)

# Copy assets to the build directory
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Add your source files
add_executable(snakeGame src/main.cpp
        include/State.hpp
        src/StateManager.cpp
        include/StateManager.h
        src/Game.cpp
        include/Game.h
        src/MainMenu.cpp
        include/MainMenu.h
        include/AssetManager.h
        src/AssetManager.cpp
        src/GamePlay.cpp
        include/GamePlay.h
        src/Snake.cpp
        include/Snake.h
        src/EndScreen.cpp
        include/EndScreen.h
        src/Pause.cpp
        include/Pause.h
)

# Link SFML libraries
target_link_libraries(snakeGame
        sfml-graphics
        sfml-window
        sfml-system
)

# Optional: show compile commands (helpful in CLion)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
