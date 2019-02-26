#include <sample_cpp_common.h>

namespace sampleCpp
{

    std::string getXMLContents( const std::string& xmlfile )
    {
        std::string _strXML = "none";

        tinyxml2::XMLDocument _doc;
        auto _errorId = _doc.LoadFile( xmlfile.c_str() );

        if ( _errorId == tinyxml2::XML_SUCCESS )
            _strXML = std::string( _doc.FirstChildElement()->Value() );

        return _strXML;
    }

    std::string getJSONContents( const std::string& jsonfile )
    {
        std::string _strXML = "none";

        std::ifstream _filehandle;
        _filehandle.open( jsonfile.c_str(), std::ifstream::in );

        if ( !_filehandle.good() )
            return _strXML;

        nlohmann::json _json;
        try 
        {
            _filehandle >> _json;
            _strXML = _json.dump();
        }
        catch ( nlohmann::json::parse_error& e )
        {
            std::cout << "ERROR> Failed to parse json file: " << jsonfile << std::endl;
            std::cout << "ERROR> error message: " << e.what() << std::endl;
        }
        _filehandle.close();

        return _strXML;
    }

    std::string getResourcesPath()
    {
        std::string _resStr;
        _resStr += SAMPLE_CPP_RESOURCES_PATH;
        
        return _resStr;
    }

    std::string getXMLResourcesPath()
    {
        std::string _resStr;
        _resStr += SAMPLE_CPP_RESOURCES_PATH;
        _resStr += "xml/";
        
        return _resStr;
    }

    std::string getJSONResourcesPath()
    {
        std::string _resStr;
        _resStr += SAMPLE_CPP_RESOURCES_PATH;
        _resStr += "json/";
        
        return _resStr;
    }

    std::string getImageResourcesPath()
    {
        std::string _resStr;
        _resStr += SAMPLE_CPP_RESOURCES_PATH;
        _resStr += "imgs/";
        
        return _resStr;
    }

    std::string getLibrariesPath()
    {
        std::string _resStr;
        _resStr += SAMPLE_CPP_LIBS_PATH;
        
        return _resStr;
    }

}