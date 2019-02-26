
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}" )

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs" )

pybind11_add_module( pysample
                     bindings/pysample_bindings.cpp )

include_directories( "${CMAKE_SOURCE_DIR}/sample_cpp/include" )
include_directories( "${CMAKE_SOURCE_DIR}/sample_cpp/ext/json" )
include_directories( "${CMAKE_SOURCE_DIR}/sample_cpp/ext/xml" )

target_link_libraries( pysample PRIVATE
                       sample_cpp )