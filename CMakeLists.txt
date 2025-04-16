cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML installed on the system (make sure SFML and SFML-devel are installed)
find_package(SFML COMPONENTS system window graphics REQUIRED)

# Add your source files
add_executable(snakeGame src/main.cpp)

# Link SFML libraries
target_link_libraries(snakeGame
        sfml-graphics
        sfml-window
        sfml-system
)

# Optional: show compile commands (helpful in CLion)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
