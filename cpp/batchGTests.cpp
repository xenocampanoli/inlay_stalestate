// batchGTests.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "deeptime.hpp"
#include "gtest/gtest.h"

#include <regex>

// Simple Construction.

TEST(MustSubMoldGlom, CorrectOverSimpleCase) {
	std::string ttt = "My test target text:  ^^^OneTwoThree^^^";
    ASSERT_NO_THROW({
        MustSubMoldGlom msmgo(ttt);
        }
        );
}

// Large string with construction and replacement multiple times.

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of batchGTests.cpp
