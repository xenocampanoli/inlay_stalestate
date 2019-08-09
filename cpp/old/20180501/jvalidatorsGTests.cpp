// jvalidatorsGTests.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "jvalidators.hpp"
#include "gtest/gtest.h"

#include <jsoncpp/json/json.h>
#include <regex>

// Simple Construction.

static std::string test_text_1 = R"EOS(
{
	"EmptyField": "",
	"ObjectTest": { "One":"1", "Two":"2", "Three":"3"},
	"Name":"Xeno Campanoli",
	"Education": [
		{"Institution":"University of Washington", "Certification":"Bachelor of Arts", "Subject":"Economics", "Secondary Interests":"Math","Comments":
			"General GPA 3.67, with 48 credits in mathematics (math GPA 3.81)"}
	],
	"SampleWork": []
}
	)EOS";

void meddleWithJsonValueRef_1(const Json::Value jvoR) {
	std::cout << "trace 0 meddle " << jvoR["Name"] << "." << std::endl;
	std::cout << "trace 1 meddle " << jvoR["ObjectTest"]["One"] << "." << std::endl;
	std::cout << "trace 2 meddle " << jvoR["Education"][0]["Subject"] << "." << std::endl;
}

void meddleWithJsonValueRef_2(const Json::Value& jvoR) {
	std::cout << "trace 0 meddle " << jvoR["Name"] << "." << std::endl;
	std::cout << "trace 1 meddle " << jvoR["ObjectTest"]["One"] << "." << std::endl;
	std::cout << "trace 2 meddle " << jvoR["Education"][0]["Subject"] << "." << std::endl;
}

void meddleWithJsonValueRef_3(const Json::Value* jvoR) {
	std::cout << "trace 0 meddle " << (*jvoR)["Name"] << "." << std::endl;
	std::cout << "trace 1 meddle " << (*jvoR)["ObjectTest"]["One"] << "." << std::endl;
	std::cout << "trace 2 meddle " << (*jvoR)["Education"][0]["Subject"] << "." << std::endl;
}

TEST(Construction, CorrectOverSimpleCase) {
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_text_1, testroot );
	});
	std::cout << "trace top " << testroot["Name"] << "." << std::endl;
	meddleWithJsonValueRef_1(testroot);
	meddleWithJsonValueRef_2(testroot);
	meddleWithJsonValueRef_3(&testroot);
    ASSERT_NO_THROW({
		JsonValidators jvo(&testroot);
        }
        );
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of jvalidatorsGTests.cpp
