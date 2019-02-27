
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}" )

pybind11_add_module( sample_cpp_wrapper
                     bindings/pysamplecpp_bindings.cpp )

include_directories( "${CMAKE_SOURCE_DIR}/sample_cpp/include" )
include_directories( "${CMAKE_SOURCE_DIR}/sample_cpp/ext/json" )
include_directories( "${CMAKE_SOURCE_DIR}/sample_cpp/ext/xml" )

target_link_libraries( sample_cpp_wrapper PRIVATE
                       sample_cpp )