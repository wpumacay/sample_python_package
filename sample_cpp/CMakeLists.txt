cmake_minimum_required( VERSION 3.0.0 )

project( sample_cpp )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}" )

if( NOT DEFINED SETUP_SAMPLE_CPP_RESOURCES_PATH )
    message( "Configuring default respath" )
    add_definitions( -DSAMPLE_CPP_RESOURCES_PATH="${CMAKE_SOURCE_DIR}/res/" )
else()
    message( "Configuring respath from setup: ${SETUP_SAMPLE_CPP_RESOURCES_PATH}" )
    add_definitions( -DSAMPLE_CPP_RESOURCES_PATH="${SETUP_SAMPLE_CPP_RESOURCES_PATH}" )
endif()

if( NOT DEFINED SETUP_SAMPLE_CPP_LIBS_PATH )
    message( "Configuring default libspath" )
    add_definitions( -DSAMPLE_CPP_LIBS_PATH="${CMAKE_BINARY_DIR}/libs/" )
else()
    message( "Configuring libspath from setup: ${SETUP_SAMPLE_CPP_LIBS_PATH}" )
    add_definitions( -DSAMPLE_CPP_LIBS_PATH="${SETUP_SAMPLE_CPP_LIBS_PATH}" )
endif()

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

