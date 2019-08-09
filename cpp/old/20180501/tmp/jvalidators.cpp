// jvalidators.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "jvalidators.hpp"

JsonValidators::JsonValidators(Json::Value& jvoR) : JVObject(jvoR) {
	//std::string s = jvoR["Name"];
	//std::cout << "trace constructor 0 " << s << "." << std::endl;
	//std::cout << "trace constructor 1 " << jvoR["Name"] << "." << std::endl;
	//std::cout << "trace constructor 2 " << JVObject["Name"] << "." << std::endl;
}

void JsonValidators::validateStringData(const std::string& keyArg,const uint8_t minValue) {
	std::cout << "trace 0 validateStringData " << keyArg << "." << std::endl;
	validateStringField(keyArg);
//	std::cout << "trace 1 validateStringData " << std::to_string(JVObject[keyArg]) << "." << std::endl;
	std::string szs = std::to_string(JVObject[keyArg].size());
	std::cout << "trace 2 validateStringData " << szs << "." << std::endl;
	if ( JVObject[keyArg].size() >= minValue ) return;
	std::cout << "trace 3 validateStringData" << std::endl;
	std::string ns = std::to_string(minValue);
	std::cout << "trace 4 validateStringData " << ns << "." << std::endl;
	std::string m =
		"Field " + keyArg + " is not a minimum " + ns + " sized String.";
	throw std::invalid_argument(m);
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of jvalidators.cpp
