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

TEST(Construction, CorrectOverSimpleCase) {
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_text_1, testroot );
	});
    ASSERT_NO_THROW({
		JsonValidators jvo(testroot);
        }
        );
}

TEST(Validations, ArrayField) {
    Json::Reader reader;
    Json::Value testroot;
	reader.parse( test_text_1, testroot );
	JsonValidators jvo(testroot);
    ASSERT_NO_THROW({
		jvo.validateArrayField("Education");
	});
    ASSERT_THROW({
		jvo.validateArrayField("Name");
		},
        std::invalid_argument
	);
}

TEST(Validations, DictionaryField) {
    Json::Reader reader;
    Json::Value testroot;
	reader.parse( test_text_1, testroot );
	JsonValidators jvo(testroot);
    ASSERT_NO_THROW({
		jvo.validateDictionaryField("ObjectTest");
	});
    ASSERT_THROW({
		jvo.validateDictionaryField("Education");
		},
        std::invalid_argument
	);
    ASSERT_THROW({
		jvo.validateDictionaryField("Name");
		},
        std::invalid_argument
	);
}

TEST(Validations, StringData) {
    Json::Reader reader;
    Json::Value testroot;
	reader.parse( test_text_1, testroot );
	JsonValidators jvo(testroot);
/*
*/
	std::cout << "trace top " << testroot["Name"] << "." << std::endl;
    ASSERT_NO_THROW({
		jvo.validateStringData("Name",1);
	});
    ASSERT_NO_THROW({
		jvo.validateStringData("Name",4);
	});
    ASSERT_NO_THROW({
		jvo.validateStringData("Name",0);
	});
    ASSERT_THROW({
		jvo.validateStringData("Name",128);
		},
        std::invalid_argument
	);
    ASSERT_THROW({
		jvo.validateStringData("EmptyField",1);
		},
        std::invalid_argument
	);
    ASSERT_THROW({
		jvo.validateStringData("Education",1);
		},
        std::invalid_argument
	);
    ASSERT_THROW({
		jvo.validateStringData("ObjectTest",1);
		},
        std::invalid_argument
	);
}

TEST(Validations, StringField) {
    Json::Reader reader;
    Json::Value testroot;
	reader.parse( test_text_1, testroot );
	JsonValidators jvo(testroot);
    ASSERT_NO_THROW({
		jvo.validateStringField("Name");
	});
    ASSERT_THROW({
		jvo.validateStringField("Education");
		},
        std::invalid_argument
	);
    ASSERT_THROW({
		jvo.validateStringField("ObjectTest");
		},
        std::invalid_argument
	);
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of jvalidatorsGTests.cpp
