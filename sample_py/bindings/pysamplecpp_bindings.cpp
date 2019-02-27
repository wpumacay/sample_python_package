
#include <sample_cpp_common.h>

#include <pybind11/pybind11.h>
namespace py = pybind11;

namespace sampleCpp {
namespace bindings {

    std::string GetContentFromXML( const std::string& filename )
    {
        return getXMLContents( filename );
    }

    std::string GetContentFromJSON( const std::string& filename )
    {
        return getJSONContents( filename );
    }

}}

PYBIND11_MODULE( sample_cpp_wrapper, m )
{

    m.def( "GetContentFromXML", &sampleCpp::bindings::GetContentFromXML );
    m.def( "GetContentFromJSON", &sampleCpp::bindings::GetContentFromJSON );

    m.attr( "__version__" ) = "dev";
}