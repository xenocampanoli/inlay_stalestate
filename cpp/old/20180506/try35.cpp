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
	Json::StreamWriterBuilder builder;
	builder["indentation"] = ""; // If you want whitespace-less output
	const std::string output = Json::writeString(builder, root);
	std::cout << "trace output:  " << output << "." << std::endl;

	Json::Value jvtesttarget;
	Json::Value testroot;
	std::string test_text = R"EOS(
{
	"Name":"Xeno Campanoli",
	"Education": [
		{"Institution":"University of Washington", "Certification":"Bachelor of Arts", "Subject":"Economics", "Secondary Interests":"Math","Comments":
			"General GPA 3.67, with 48 credits in mathematics (math GPA 3.81)"}
	],
	"SampleWork": []
}
	)EOS";
	reader.parse( test_text, testroot );
	const std::vector<std::string> RequiredIdKeys = { "Name" };
	const std::vector<std::string> OptionalIdKeys = { "Phone", "Email", "Address", "Summary" };
	mergeJsonValues(jvtesttarget,testroot,RequiredIdKeys,OptionalIdKeys);
	const std::string output2 = Json::writeString(builder, jvtesttarget);
	std::cout << "trace output:  " << output2 << "." << std::endl;
}
