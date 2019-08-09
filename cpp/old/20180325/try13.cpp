#include <cstdlib>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>

void printJSONValue( const Json::Value &val )
{
    if( val.isString() ) {
        printf( "string(%s)", val.asString().c_str() ); 
    } else if( val.isBool() ) {
        printf( "bool(%d)", val.asBool() ); 
    } else if( val.isInt() ) {
        printf( "int(%d)", val.asInt() ); 
    } else if( val.isUInt() ) {
        printf( "uint(%u)", val.asUInt() ); 
    } else if( val.isDouble() ) {
        printf( "double(%f)", val.asDouble() ); 
    }
    else 
    {
        printf( "unknown type=[%d]", val.type() ); 
    }
}

int main(void) {
	Json::Reader reader;
	Json::Value root;
	Json::StyledStreamWriter writer;
	std::ofstream outFile;
  
	std::string fns = "../testdata/test_soil_sap.json";
	std::ifstream input_buffer(fns.c_str());
	std::string input_text(( std::istreambuf_iterator<char>(input_buffer)),
						 std::istreambuf_iterator<char>());
	// Parse JSON and print errors if needed
	if(!reader.parse(input_text, root)) {
		std::cout << reader.getFormattedErrorMessages();
		exit(1);
	} else {

		std::cout << "trace 5a  " << BoleSap["SoilSap"][mik] << "." << std::endl;
		// Read and modify the json data
		std::cout << "Size: " << root.size() << std::endl;
		std::cout << "Contains SoilSap? " << root.isMember("SoilSap") << std::endl;
	}
	Json::Value& r = root;
	return 0;
}
