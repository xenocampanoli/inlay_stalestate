// glomsetsGTests.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "glomsets.hpp"
#include "gtest/gtest.h"

#include <regex>

using namespace Inlay;

// Simple Construction.

TEST(MustSubMoldGlom, CorrectOverSimpleCase) {
	std::string ttt = "My test target text:  ^^^OneTwoThree^^^";
    ASSERT_NO_THROW({
        MustSubMoldGlom msmgo(ttt);
        }
        );
}

TEST(MustSubMoldGlom, NoTagInMoldSimpleCase) {
	std::string ttt = "My test target text:  ^^OneTwoThree^^^";
    ASSERT_NO_THROW({
        MustSubMoldGlom msmgo(ttt);
        }
        );
}

TEST(OptionalGlom, CorrectOverSimpleCase) {
	std::string ttt = "My test target text:  ###One###Two###Three###";
    ASSERT_NO_THROW({
        OptionalGlom ogo(ttt);
        }
        );
}

TEST(OptionalGlom, NoTagInMoldSimpleCase) {
	std::string ttt = "My test target text:  ###OneTwoThree###";
    ASSERT_NO_THROW({
        OptionalGlom ogo(ttt);
        }
        );
}

TEST(RequiredGlom, CorrectOverSimpleCase) {
	std::string ttt = "My test target text:  @@@OneTwoThree@@@";
    ASSERT_NO_THROW({
        RequiredGlom rgo(ttt);
        }
        );
}

TEST(RequiredGlom, NoTagInMoldSimpleCase) {
	std::string ttt = "My test target text:  @@@OneTwoThree@@";
    ASSERT_NO_THROW({
        RequiredGlom rgo(ttt);
        }
        );
}

// Simple replacement.

TEST(MustSubMoldGlom, SimpleReplacement) {
	std::string ttt = "My test target text:  ^^^OneTwoThree^^^";
	MustSubMoldGlom msmgo(ttt);
}

// Large string with construction and replacement multiple times.

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of glomsetsGTests.cpp
