/* tools4jsonGTests.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890
 */

#include "tools4json.hpp"
#include "gtest/gtest.h"

#include <jsoncpp/json/json.h>
#include <regex>

#include "testjson.hpp"

// Begin Json Text Literals for tests

TEST(ToolsForJSON, CHECK_DumpStringFromJsonValueTree) {
    Json::Reader reader;
    Json::Value jvo;
    ASSERT_NO_THROW({
		reader.parse( test_literal_2, jvo );
	});
	std::string expected = "{\"Name\":\"Xeno Campanoli\"}\n";
	testing::internal::CaptureStdout();
	ToolsForJSON::DumpStringFromJsonValueTree(jvo);
	std::string dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(dumped_output,expected);
}

TEST(ToolsForJSON, CHECK_GetStringFromJsonValueTree) {
    Json::Reader reader;
    Json::Value jvo1;
    ASSERT_NO_THROW({
		reader.parse( test_literal_5, jvo1 );
	});
	std::string sb1 = ToolsForJSON::GetStringFromJsonValueTree(jvo1);
    Json::Value jvo2;
    ASSERT_NO_THROW({
		reader.parse( sb1, jvo2 );
	});
	bool bb = false;
	if ( jvo1 == jvo2 ) bb = true;
	ASSERT_TRUE(bb);
	std::string sb2 = ToolsForJSON::GetStringFromJsonValueTree(jvo2);
	ASSERT_EQ(sb1,sb2);
}

TEST(ToolsForJSON, CHECK_stringWantedInArray) {
    Json::Reader reader;
    Json::Value jvo;
    ASSERT_NO_THROW({
		reader.parse( test_literal_7, jvo );
	});
    ASSERT_DEATH({
		ToolsForJSON::stringWantedInArray("","");
        },
        ""
        );
	bool bb;
    ASSERT_NO_THROW({
		bb = ToolsForJSON::stringWantedInArray("Bash",jvo["SampleWork"][0]["Skills"]);
	});
	ASSERT_TRUE(bb);
    ASSERT_NO_THROW({
		bb = ToolsForJSON::stringWantedInArray("Whack",jvo["SampleWork"][0]["Skills"]);
	});
	ASSERT_FALSE(bb);
    ASSERT_NO_THROW({
		bb = ToolsForJSON::stringWantedInArray("",jvo["SampleWork"][0]["Skills"]);
	});
	ASSERT_FALSE(bb);
}

TEST(ToolsForJSON, CHECK_mergeJsonValues) {
    Json::Reader reader;
    Json::Value testroot;
	Json::Value jvtesttarget;
    ASSERT_NO_THROW({
		reader.parse( test_literal_1, testroot );
	});
    ASSERT_NO_THROW({
		reader.parse( test_literal_2, jvtesttarget );
	});
    ASSERT_NO_THROW({
		ToolsForJSON::mergeJsonValues(jvtesttarget,testroot,{"Name"},{"Phone"});
	});
	ASSERT_EQ(jvtesttarget["Name"],testroot["Name"]);
	ASSERT_EQ(jvtesttarget["Phone"],testroot["Phone"]);
	Json::StreamWriterBuilder builder;
	builder["indentation"] = ""; // If you want whitespace-less output
	const std::string output = Json::writeString(builder, jvtesttarget);
	//std::cout << "trace output:  " << output << "." << std::endl;
}

TEST(ToolsForJSON, CHECK_validateArrayField) {
    Json::Reader reader;
    Json::Value jvo;
    ASSERT_NO_THROW({
		reader.parse( test_literal_4, jvo );
	});
    ASSERT_NO_THROW({
		ToolsForJSON::validateArrayField(jvo, "Education");
	});
    ASSERT_THROW({
		ToolsForJSON::validateArrayField(jvo, "");
        },
        std::invalid_argument
        );
    ASSERT_THROW({
		ToolsForJSON::validateArrayField(jvo, "Name");
        },
        std::invalid_argument
        );
    ASSERT_THROW({
		ToolsForJSON::validateArrayField(jvo, "Phone");
        },
        std::invalid_argument
        );
    ASSERT_NO_THROW({
		ToolsForJSON::validateArrayField(jvo, "SampleWork");
        });
}

TEST(ToolsForJSON, CHECK_validateDictionaryField) {
    Json::Reader reader;
    Json::Value jvo;
    ASSERT_NO_THROW({
		reader.parse( test_literal_5, jvo );
	});
    ASSERT_NO_THROW({
		ToolsForJSON::validateDictionaryField(jvo,"Abstract");
	});
    ASSERT_THROW({
		ToolsForJSON::validateDictionaryField(jvo, "");
        },
        std::invalid_argument
        );
    ASSERT_THROW({
		ToolsForJSON::validateDictionaryField(jvo, "Name");
        },
        std::invalid_argument
        );
    ASSERT_THROW({
		ToolsForJSON::validateDictionaryField(jvo, "Phone");
        },
        std::invalid_argument
        );
    ASSERT_THROW({
		ToolsForJSON::validateDictionaryField(jvo, "Education");
        },
        std::invalid_argument
        );
}

TEST(ToolsForJSON, CHECK_validateField) {
    Json::Reader reader;
    Json::Value jvo;
    ASSERT_NO_THROW({
		reader.parse( test_literal_5, jvo );
	});
    ASSERT_NO_THROW({
		ToolsForJSON::validateField(jvo,"Abstract");
	});
    ASSERT_THROW({
		ToolsForJSON::validateField(jvo, "NotThereNeverWas");
        },
        std::invalid_argument
        );
    ASSERT_NO_THROW({
		ToolsForJSON::validateField(jvo, "Name");
        });
    ASSERT_NO_THROW({
		ToolsForJSON::validateField(jvo, "Phone");
        });
    ASSERT_NO_THROW({
		ToolsForJSON::validateField(jvo, "Education");
        });
}

TEST(ToolsForJSON, CHECK_validateJsonStringValues) {
    Json::Reader reader;
    Json::Value jvo;
    ASSERT_NO_THROW({
		reader.parse( test_literal_1, jvo );
	});
    ASSERT_NO_THROW({
		ToolsForJSON::validateJsonStringValues(jvo,{"Name"},{"Phone","Email"});
	});
}

TEST(ToolsForJSON, CHECK_validateStringData) {
    Json::Reader reader;
    Json::Value jvo;
    ASSERT_NO_THROW({
		reader.parse( test_literal_5, jvo );
	});
    ASSERT_NO_THROW({
		ToolsForJSON::validateStringData(jvo,"Name",1);
	});
    ASSERT_THROW({
		ToolsForJSON::validateStringData(jvo,"Phone",1);
        },
        std::invalid_argument
        );
    ASSERT_THROW({
		ToolsForJSON::validateStringData(jvo,"NotThereNeverWas",1);
        },
        std::invalid_argument
        );
    ASSERT_THROW({
		ToolsForJSON::validateStringData(jvo,"Abstract",1);
        },
        std::invalid_argument
        );
    ASSERT_THROW({
		ToolsForJSON::validateStringData(jvo,"Education",1);
        },
        std::invalid_argument
        );
}

TEST(ToolsForJSON, CHECK_validateStringField) {
    Json::Reader reader;
    Json::Value jvo;
    ASSERT_NO_THROW({
		reader.parse( test_literal_5, jvo );
	});
    ASSERT_NO_THROW({
		ToolsForJSON::validateStringField(jvo, "Name");
	});
    ASSERT_NO_THROW({
		ToolsForJSON::validateStringField(jvo, "Phone");
        });
    ASSERT_THROW({
		ToolsForJSON::validateStringField(jvo, "NotThereNeverWas");
        },
        std::invalid_argument
        );
    ASSERT_THROW({
		ToolsForJSON::validateStringField(jvo,"Abstract");
        },
        std::invalid_argument
        );
    ASSERT_THROW({
		ToolsForJSON::validateStringField(jvo, "Education");
        },
        std::invalid_argument
        );
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of tools4jsonGTests.cpp
