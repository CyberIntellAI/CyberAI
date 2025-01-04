cmake_minimum_required(VERSION 3.10)
project(cpp_components)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/quantum_resistant.cpp
    src/blockchain.cpp
    src/network_intelligence.cpp
)

# Add executable
add_executable(cpp_components ${SOURCES})

# Link libraries if any
# target_link_libraries(cpp_components PRIVATE some_library)
