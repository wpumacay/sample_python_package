#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include <json.hpp>
#include <tinyxml2.h>

namespace sampleCpp
{

    std::string getXMLContents( const std::string& xmlfile );
    std::string getJSONContents( const std::string& jsonfile );

}