// resin.cpp

#include "resin.hpp"
#include "gtest/gtest.h"

TEST(ResinConstruction, InCorrectInputCase) {
    std::string fn1 = "bogus filename1";
    std::string fn2 = "bogus filename2";
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::invalid_argument
        );
}

TEST(ResinConstruction, EmptyFileCase) {
    std::string fn = "testdata/test_empty.json";
    ASSERT_THROW({
        Resin ro(fn,fn);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, CorrectInputCase) {
    std::string fn1 = "testdata/test_bole_sap.json";
    std::string fn2 = "testdata/test_soil_sap.json";
    ASSERT_NO_THROW({
            Resin ro(fn1,fn2);
        }
        );
}

TEST(ResinConstruction, PartlyCorrectInputCase1) {
    std::string fn1 = "testdata/test_empty.json";
    std::string fn2 = "testdata/test_soil_sap.json";
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, PartlyCorrectInputCase2) {
    std::string fn1 = "testdata/test_bole_sap.json";
    std::string fn2 = "testdata/test_empty.json";
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, PartlyCorrectInputCase3) {
    std::string fn1 = "bogus filename1";
    std::string fn2 = "testdata/test_soil_sap.json";
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::invalid_argument
        );
}
                  
TEST(ResinConstruction, PartlyCorrectInputCase4) {
    std::string fn1 = "testdata/test_bole_sap.json";
    std::string fn2 = "bogus filename1";
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::invalid_argument
        );
}
                  
/*
TEST(ResinConstruction, BadDataCase1) {
    std::string fn1 = "testdata/test_bole_sap_bad1.json";
    std::string fn2 = "testdata/test_soil_sap_bad1.json";
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, WellFormedJSONCase) {
    std::string fn = "testdata/test_bole_sap.json";
    Resin ro(fn);
    ASSERT_NE(ro,NULL);
}

*/
                  
int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

// End of resin.cpp
