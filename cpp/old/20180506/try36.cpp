#include <regex>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <string>

#include "env.hpp"

inline void mergeJsonValues(Json::Value& targetJvoR,
							const Json::Value& sourceJvoR,
							const std::vector<std::string>& RequiredKeys,
							const std::vector<std::string>& OptionalKeys) {
	std::string bi;
	for(bi : RequiredKeys) {			targetJvoR[bi] = sourceJvoR[bi]; }
	for(bi : OptionalKeys) {
		if ( sourceJvoR.isMember(bi) )	targetJvoR[bi] = sourceJvoR[bi];
	} 
}

void subroutine1(const Json::Value& jvoR) {
	Json::StreamWriterBuilder builder;
	builder["indentation"] = ""; // If you want whitespace-less output
	const std::string output = Json::writeString(builder, jvoR);
	std::cout << "subroutine1 trace 1 output:  " << output << "." << std::endl;
	std::cout << "subroutine1 trace 2 output:  " << jvoR["Name"] << "." << std::endl;
	std::string sb = jvoR["Name"];
	std::cout << "subroutine1 trace 3 output:  " << sb << "." << std::endl;
}

void subroutine2(const Json::Value& jvoR) {
	Json::StreamWriterBuilder builder;
	builder["indentation"] = ""; // If you want whitespace-less output
	const std::string output = Json::writeString(builder, jvoR);
	std::cout << "subroutine2 trace output:  " << output << "." << std::endl;
	std::cout << "subroutine2 trace output:  " << jvoR["Name"] << "." << std::endl;
	subroutine1(jvoR);
}

void subroutine3(const Json::Value& jvoR) {
	Json::StreamWriterBuilder builder;
	builder["indentation"] = ""; // If you want whitespace-less output
	const std::string output = Json::writeString(builder, jvoR);
	std::cout << "subroutine3 trace output:  " << output << "." << std::endl;
	std::cout << "subroutine3 trace output:  " << jvoR["Name"] << "." << std::endl;
	subroutine2(jvoR);
}

void subroutine4(const Json::Value& jvoR) {
	Json::StreamWriterBuilder builder;
	builder["indentation"] = ""; // If you want whitespace-less output
	const std::string output = Json::writeString(builder, jvoR);
	std::cout << "subroutine4 trace output:  " << output << "." << std::endl;
	std::cout << "subroutine4 trace output:  " << jvoR["Name"] << "." << std::endl;
	subroutine3(jvoR);
}

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
	std::cout << "------" << std::endl;
	subroutine1(jvtesttarget);
	std::cout << "------" << std::endl;
	subroutine2(jvtesttarget);
	std::cout << "------" << std::endl;
	subroutine3(jvtesttarget);
	std::cout << "------" << std::endl;
	subroutine4(jvtesttarget);
}
