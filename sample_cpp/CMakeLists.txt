cmake_minimum_required( VERSION 3.0.0 )

project( sample_cpp )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}" )

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs" )

add_definitions( -DSAMPLE_CPP_RESOURCES_PATH="${CMAKE_SOURCE_DIR}/res/" )
add_definitions( -DSAMPLE_CPP_LIBS_PATH="${CMAKE_BINARY_DIR}/libs/" )

# Main Sources
file( GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )

# Main includes
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/include/" )
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/ext/json/" )
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/ext/xml/" )

set( SOURCES 
     ${SOURCES}
     "${CMAKE_CURRENT_SOURCE_DIR}/ext/xml/tinyxml2.cpp" )

add_library( sample_cpp SHARED
             ${SOURCES} )

