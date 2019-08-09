#include <regex>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <string>

#include "env.hpp"

int main() {
	std::string jsonstr="{ \"one\":\"1\" }";
    Json::Reader reader;
    Json::Value root;
    Json::Value target;

    reader.parse( jsonstr, root );
	Json::FastWriter fastWriter;
	std::string output = fastWriter.write(root);
	std::cout << "trace output:  " << output << "." << std::endl;
}
