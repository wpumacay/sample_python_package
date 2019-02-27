cmake_minimum_required( VERSION 3.0.0 )

project( sample_cpp )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}" )

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

