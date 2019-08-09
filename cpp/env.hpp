/* env.hpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890
   Items presumed to be accessed, or at least potentially useful everywhere in
   the app.
 */
#pragma once

#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/value.h>
#include <map>
#include <regex>
#include <streambuf>
#include <string>
#include <sys/stat.h>
#include <vector>

const std::string DEFAULT_CONFIG_FOLDER		("../defaults");
const std::string OUTPUT_SETS_FOLDER		("../output");
const std::string SUBJECT_CONFIG_FOLDER		("../subjects");
const std::string TEMPLATE_CONFIG_FOLDER	("../templates");
const std::string TESTDATA_FOLDER			("../testdata");

inline bool fileExists(std::string fPath) {
	struct stat b;   
	if ( stat(fPath.c_str(),&b) == 0 )
		return true; 
	return false;
}

inline std::string loadFile(std::string fPath) {
    std::ifstream input_buffer(fPath.c_str());
	std::istreambuf_iterator<char> beginIt(input_buffer);
	std::istreambuf_iterator<char> endIt;
    std::string sb(beginIt,endIt);//Meyers p35 on STL 0-201-74962-9
	return sb;
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of env.hpp
