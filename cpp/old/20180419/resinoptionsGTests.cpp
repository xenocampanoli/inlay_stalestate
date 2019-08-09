// ovenGTests.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "env.hpp"
#include "oven.hpp"
#include "gtest/gtest.h"

TEST(OvenConstruction, InCorrectInputCase) {
    std::string fn1 = "bogus filename1";
    std::string fn2 = "bogus filename2";
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::invalid_argument
        );
}



int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of ovenGTests.cpp
