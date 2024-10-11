cmake_minimum_required(VERSION 3.25)
project(PlatformerGameDev)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent to handle dependencies
include(FetchContent)

# Specify that we want to build static libraries
set(BUILD_SHARED_LIBS OFF)

# Fetch and build SFML from the official repository
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

# Add the executable target for your game
add_executable(PlatformerGameDev src/main.cpp src/Background.cpp
        src/Platform.cpp
        include/Platform.h
        src/Tile.cpp
        include/Tile.h
        src/Player.cpp
        include/Player.h
        src/CollisionBox.cpp
        include/CollisionBox.h)

# Include SFML's include directories explicitly for CLion's code analysis
target_include_directories(PlatformerGameDev PRIVATE ${SFML_SOURCE_DIR}/include)

# Link SFML libraries to the target
target_link_libraries(PlatformerGameDev sfml-graphics sfml-window sfml-system)