
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

    std::string GetSampleContentXML()
    {
        auto _xmlpath = getXMLResourcesPath();
        _xmlpath += "hello_world.xml";

        return getXMLContents( _xmlpath );
    }

    std::string GetSampleContentJSON()
    {
        auto _jsonpath = getJSONResourcesPath();
        _jsonpath += "hello_world.json";

        return getJSONContents( _jsonpath );
    }

    std::string GetXMLResourcesPath()
    {
        return getXMLResourcesPath();
    }

    std::string GetJSONResourcesPath()
    {
        return getJSONResourcesPath();
    }

}}

PYBIND11_MODULE( pysample, m )
{
    m.def( "GetContentFromXML", &sampleCpp::bindings::GetContentFromXML );
    m.def( "GetContentFromJSON", &sampleCpp::bindings::GetContentFromJSON );
    m.def( "GetSampleContentXML", &sampleCpp::bindings::GetSampleContentXML );
    m.def( "GetSampleContentJSON", &sampleCpp::bindings::GetSampleContentJSON );
    m.def( "GetXMLResourcesPath", &sampleCpp::bindings::GetXMLResourcesPath );
    m.def( "GetJSONResourcesPath", &sampleCpp::bindings::GetJSONResourcesPath );

    m.attr( "__version__" ) = "dev";
}