/* subjectGTests.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890

 */

#include "env.hpp"
#include "subject.hpp"
#include "gtest/gtest.h"

#include <regex>

const std::string BOGUS_FILENAME1 = TESTDATA_FOLDER + "/" + "bogus filename1";
const std::string BOGUS_FILENAME2 = TESTDATA_FOLDER + "/" + "bogus filename2";

const std::string TEST_EMPTY_FILENAME = TESTDATA_FOLDER + "/" + "test_empty.json";

const std::string GOOD_BOLE_SAP_FILENAME1 = TESTDATA_FOLDER + "/" + "test_bole_sap.json";
const std::string GOOD_SOIL_SAP_FILENAME2 = TESTDATA_FOLDER + "/" + "test_soil_sap.json";

const std::string BAD_BOLE_SAP_FILENAME1 = TESTDATA_FOLDER + "/" + "test_bole_sap_bad1.json";
const std::string BAD_SOIL_SAP_FILENAME2 = TESTDATA_FOLDER + "/" + "test_soil_sap_bad2.json";
const std::string BAD_BOLE_SAP_FILENAME3 = TESTDATA_FOLDER + "/" + "test_bole_sap_bad1.json";
const std::string BAD_SOIL_SAP_FILENAME4 = TESTDATA_FOLDER + "/" + "test_soil_sap_bad2.json";

const std::string XC1_BOLE_FILENAME = TESTDATA_FOLDER + "/" + "xc1.json";
const std::string XC2_BOLE_FILENAME = TESTDATA_FOLDER + "/" + "xc2.json";

TEST(ResinConstruction, InCorrectInputCase) {
    std::string fn1 = BOGUS_FILENAME1;
    std::string fn2 = BOGUS_FILENAME2;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::invalid_argument
        );
}

TEST(ResinConstruction, EmptyFileCase) {
    std::string fn = TEST_EMPTY_FILENAME;
    ASSERT_THROW({
        Resin ro(fn,fn);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, CorrectInputCase) {
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
    ASSERT_NO_THROW({
        }
        );
}

TEST(ResinConstruction, PartlyCorrectInputCase1) {
    std::string fn1 = TEST_EMPTY_FILENAME;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, PartlyCorrectInputCase2) {
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = TEST_EMPTY_FILENAME;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, PartlyCorrectInputCase3) {
    std::string fn1 = BOGUS_FILENAME1;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::invalid_argument
        );
}
                  
TEST(ResinConstruction, PartlyCorrectInputCase4) {
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = BOGUS_FILENAME2;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::invalid_argument
        );
}
                  
TEST(ResinConstruction, BadDataCase1) {
    std::string fn1 = BAD_BOLE_SAP_FILENAME1;
    std::string fn2 = BAD_SOIL_SAP_FILENAME2;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, BadDataCase2) {
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = BAD_SOIL_SAP_FILENAME2;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, BadDataCase3) {
    std::string fn1 = BAD_BOLE_SAP_FILENAME1;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, BadDataCase4) {
    std::string fn1 = BAD_BOLE_SAP_FILENAME1;
    std::string fn2 = BAD_SOIL_SAP_FILENAME2;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, BadDataCase5) {
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = BAD_SOIL_SAP_FILENAME4;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinConstruction, BadDataCase6) {
    std::string fn1 = BAD_BOLE_SAP_FILENAME3;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
    ASSERT_THROW({
        Resin ro(fn1,fn2);
        },
        std::runtime_error
        );
}
                  
TEST(ResinAssignmentConstructor, SimpleCaseOnly) {
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
	Resin ro1(fn1,fn2);
    ASSERT_NO_THROW({
			Resin ro2(ro1);
        }
        );
}

TEST(ResinDumpBoleSap, SimpleCaseOnly) {
	std::stringstream b;
	std::streambuf * savestreambuf = std::cout.rdbuf(b.rdbuf());
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
	Resin ro(fn1,fn2);
	ro.DumpBoleSap("Name");
	std::string lstr = b.str();
	std::string expected = "Json::Value BoleSap dump for item key 'Name':  'Xeno Campanoli'.\n";
	ASSERT_EQ(lstr,expected);
	std::cout.rdbuf(savestreambuf);
}

TEST(ResinDumpSoilSap, SimpleCaseOnly) {
	std::stringstream b;
	std::streambuf * savestreambuf = std::cout.rdbuf(b.rdbuf());
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
	Resin ro(fn1,fn2);
	ro.DumpSoilSap("AllYearBackgroundColor");
	std::string lstr = b.str();
	std::string expected = "Json::Value SoilSap dump for item key 'AllYearBackgroundColor':  'lightgray'.\n";
	ASSERT_EQ(lstr,expected);
	std::cout.rdbuf(savestreambuf);
}

TEST(ResinGetIdentityString, SimpleCase) {
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
	Resin ro(fn1,fn2);
	std::string rstr = ro.GetIdentityString("Name");
	std::string expected = "Xeno Campanoli";
	ASSERT_EQ(rstr,expected);
}

TEST(ResinGetUniversalString, SimpleCase) {
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
	Resin ro(fn1,fn2);
	std::string rstr = ro.GetUniversalString("AllYearBackgroundColor");
	std::string expected = "lightgray";
	ASSERT_EQ(rstr,expected);
}

TEST(ResinValidateBoleValue, SimpleCase) {
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
	Resin ro(fn1,fn2);
    std::vector<std::string> keyset = {"Name","Phone","Email","Summary","Experience","Education","SampleWork"};
	bool b = ro.ValidateBoleSap(keyset,false);
	ASSERT_TRUE(b);
}

TEST(ResinValidateSoilValue, SimpleCase) {
    std::string fn1 = GOOD_BOLE_SAP_FILENAME1;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
	Resin ro(fn1,fn2);
    std::vector<std::string> keyset = {"BackgroundColorType","AllYearBackgroundColor","MinimalMonthsToShow","YearsBackToShow","YearsFromStartToIgnore"};
	bool b = ro.ValidateSoilSap(keyset,false);
	ASSERT_TRUE(b);
}

TEST(ResinValidateBoleValue, FullExampleXC1) {
    std::string fn1 = XC1_BOLE_FILENAME;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
	Resin ro(fn1,fn2);
    std::vector<std::string> keyset = {"Name","Phone","Email","Summary","Experience","Education","SampleWork"};
	bool b = ro.ValidateBoleSap(keyset,false);
	ASSERT_TRUE(b);
}

TEST(ResinValidateBoleValue, FullExampleXC2) {
    std::string fn1 = XC2_BOLE_FILENAME;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
	Resin ro(fn1,fn2);
    std::vector<std::string> keyset = {"Name","Phone","Email","Summary","Experience","Education","SampleWork","BackgroundColorType"};
	bool b = ro.ValidateBoleSap(keyset,false);
	ASSERT_TRUE(b);
}

TEST(ResinGetMonthlyString, SimpleExampleSoilSap) {
    std::string fn1 = XC1_BOLE_FILENAME;
    std::string fn2 = GOOD_SOIL_SAP_FILENAME2;
	Resin ro(fn1,fn2);
	std::string s = ro.GetMonthlyString("BackgroundColors");
	std::regex reo("^(\\w{4,14})");
	ASSERT_TRUE(regex_match(s,reo));
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of subjectGTests.cpp
