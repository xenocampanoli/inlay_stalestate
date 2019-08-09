/* templatesGTests.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890

 */

#include "templates.hpp"
#include "bioseer.hpp"
#include "gtest/gtest.h"

#include <regex>
#include <vector>

using namespace Bio;
using namespace Inlay;
//using namespace Bio

// Simple Construction.

TEST(TemplatesConstruction, CorrectOverSimpleCase) {
	std::string mdir = TEMPLATE_CONFIG_FOLDER + "/test_mold_1";
    ASSERT_NO_THROW({
		Mold mo(mdir,"Top");
        }
        );
}

TEST(TemplatesConstruction, IncorrectOverSimpleCase) {
	std::string mdir = TEMPLATE_CONFIG_FOLDER + "/test_mold_1";
    ASSERT_THROW({
		Mold mo(mdir,"TopNot");
        },
        std::invalid_argument
        );
}

TEST(TemplatesConstruction, SubTemplateWithExtension) {
	std::string mdir = TEMPLATE_CONFIG_FOLDER + "/test_mold_1";
    ASSERT_NO_THROW({
		Mold mo(mdir,"SubMold","html");
        }
        );
}

TEST(TemplatesConstruction, IncorrectOverSimpleSubmold) {
	std::string mdir = TEMPLATE_CONFIG_FOLDER + "/test_mold_1";
    ASSERT_THROW({
		Mold mo(mdir,"SubMold","latex");
        },
        std::invalid_argument
        );
}

TEST(TemplatesUsage, GetSimpleString) {
	std::string mdir = TEMPLATE_CONFIG_FOLDER + "/test_mold_1";
	Mold mo(mdir,"SubMold","html");
	std::string lstr = mo.getString();
	std::string expected = R"EOS(
@@@Idonno@@@


)EOS";
	ASSERT_EQ(lstr,expected);
}

TEST(TemplatesUsage, TestSubTemplateExists) {
	std::string mdir = TEMPLATE_CONFIG_FOLDER + "/test_mold_1";
	Mold mo(mdir,"Top");
	ASSERT_TRUE(mo.templateFileExists("SubMold"));
}

TEST(TemplatesUsage, Test_newSubTemplate) {
	std::string mdir = TEMPLATE_CONFIG_FOLDER + "/test_mold_1";
	Mold mo(mdir,"Top");
	std::shared_ptr<Mold> smop = mo.newSubTemplate("SubMold");
	std::string lstr = smop->getString();
	std::string expected = R"EOS(
@@@Idonno@@@


)EOS";
	ASSERT_EQ(lstr,expected);
}

TEST(TemplatesUsage, GeneralLargerTemplateTest) {
	std::string mdir = TEMPLATE_CONFIG_FOLDER + "/test_mold_2";
	Mold mo(mdir,"Top");
	
	std::vector<std::string> submoldnames =
		{ IdentificationKey, ExperienceKey, EducationKey, SampleWorkKey }; 
	std::shared_ptr<Mold> smop;
	std::string lstr;
	for(std::string smn : submoldnames) {
		ASSERT_TRUE(mo.templateFileExists(smn));
		smop = mo.newSubTemplate(smn);
		lstr = smop->getString();
		ASSERT_TRUE(lstr.size() > 0);
	}
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of templatesGTests.cpp
