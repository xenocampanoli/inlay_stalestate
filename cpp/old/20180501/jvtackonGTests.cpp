// jvtackonGTests.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "jvtackon.hpp"
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

TEST(Construction, CorrectOverSimpleCase) {
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_text_1, testroot );
	});
	std::cout << "trace top " << testroot["Name"] << "." << std::endl;
    ASSERT_NO_THROW({
		JVTackon jvto(testroot);
        }
        );
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of jvtackonGTests.cpp
