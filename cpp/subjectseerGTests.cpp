// subjectseerGTests.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "subject.hpp"
#include "bioseer.hpp"
#include "gtest/gtest.h"

#include <fstream>
#include <jsoncpp/json/json.h>
#include <regex>
#include <streambuf>

using namespace Bio;
using namespace Inlay;

// Simple Construction.

TEST(SubjectSeerDaughter, SimpleConstruction) {
    ASSERT_NO_THROW({
        Bio::Seer bso;
        });
}

TEST(SubjectSeerDaughter,CHECK_validateMonthString) {
    ASSERT_NO_THROW({
		validateMonthString("201805");
        });
    ASSERT_NO_THROW({
		validateMonthString("201813");
        });
    ASSERT_THROW({
		validateMonthString("2018059");
		},
		std::invalid_argument
		);
    ASSERT_THROW({
		validateMonthString("2018");
		},
		std::invalid_argument
		);
    ASSERT_THROW({
		validateMonthString("2018051234");
		},
		std::invalid_argument
		);
    ASSERT_THROW({
		validateMonthString("2018057");
		},
		std::invalid_argument
		);
}

/*
	*/
TEST(SubjectSeerDaughter,CHECK_validateDefaultsTree) {
	Bio::Seer bso;
	std::string lfs = DEFAULT_CONFIG_FOLDER + "/default.json";
    std::string sb = loadFile(lfs);
    Json::Reader reader;
    Json::Value jvo;
    ASSERT_NO_THROW({
		reader.parse( sb, jvo );
	});
    ASSERT_NO_THROW({
		bso.validateDefaultsTree(jvo);
        });
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of subjectseerGTests.cpp
