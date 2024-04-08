cmake_minimum_required(VERSION 3.28)
project(OSN_Demo)

set(SFML_DIR)
set(SFML_STATIC_LIBRARIES true)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp
        src/Program.cpp
        src/Program.h
        src/OpenSimplexNoise.cpp
        src/OpenSimplexNoise.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
target_link_libraries(${PROJECT_NAME} PRIVATE -static)