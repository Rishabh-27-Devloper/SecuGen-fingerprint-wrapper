# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(SecuGenWrapper)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add library directories
link_directories(${PROJECT_SOURCE_DIR}/lib)

# Create DLL
add_library(SecuGenWrapper SHARED
    src/SecuGenWrapper.cpp
)

# Link against SecuGen library
target_link_libraries(SecuGenWrapper sgfplib)

# Set output directories
set_target_properties(SecuGenWrapper
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
add_definitions(-DSECUGENWRAPPER_EXPORTS)