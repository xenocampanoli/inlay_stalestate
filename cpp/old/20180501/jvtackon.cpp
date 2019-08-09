// jvalidators.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "jvtackon.hpp"

JVTackon::JVTackon(const Json::Value& jvoR) : JVOR(jvoR) {
	if ( jvoR.isMember("Name") ) std::cout << "trace 1" << std::endl;
	//std::string s = jvoR["Name"];
}

