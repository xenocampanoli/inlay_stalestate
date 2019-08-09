// bioseerGTests.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "gtest/gtest.h"

#include <jsoncpp/json/json.h>
#include <regex>

#include "subject.hpp"
#include "bioseer.hpp"

#include "testjson.hpp"

bool dumpHasStr(const std::string dumpString,const std::string strArg) {
	std::string bs = ".*" + strArg + ".*";
	return std::regex_search(dumpString,std::regex(bs));
}

// Simple Construction.

TEST(BioSeer, SimpleConstruction) {
    ASSERT_NO_THROW({
        Bio::Seer bso;
        }
        );
}

TEST(BioSeer, CHECK_DumpInternals) {
	Bio::Seer bso;
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	std::string dumped_output = testing::internal::GetCapturedStdout();
	std::string expected = 
		"EarliestMonth:\nEducationRequired:0\nExperienceRequired:0\nLatestMonth:\nIncludeExperienceAnecdotesRemainders:1\nIncludeUnrelatedExperience:0\nIncludeUnrelatedSampleWork:0\nSampleWorkRequired:0\n";
	ASSERT_EQ(dumped_output,expected);
}

TEST(BioSeer, CHECK_filterInEducation) {
	Bio::Seer bso;
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_literal_7, testroot );
	});
	Json::Value jvtesttarget;
    ASSERT_NO_THROW({
			bso.filterInSubjectData(jvtesttarget, testroot);
        });
    ASSERT_EQ(jvtesttarget[Bio::EducationKey][0]["Institution"],"University of Washington");
}

TEST(BioSeer, CHECK_filterInExperience) {
	Bio::Seer bso;
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_literal_7, testroot );
	});
	Json::Value jvtesttarget;
    ASSERT_NO_THROW({
			bso.filterInExperience(jvtesttarget, testroot);
        });
    ASSERT_EQ(jvtesttarget[Bio::ExperienceKey][0]["Title"],"Senior Consultant");
}

/*
TEST(BioSeer, CHECK_filterInIdentification) {
	Bio::Seer bso;
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_literal_7, testroot );
	});
	Json::Value jvtesttarget;
    ASSERT_NO_THROW({
			bso.filterInIdentification(jvtesttarget, testroot);
        });
    ASSERT_EQ(jvtesttarget["Name"],"Xeno Campanoli");
}

TEST(BioSeer, CHECK_filterInSampleWork) {
	Bio::Seer bso;
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_literal_7, testroot );
	});
	Json::Value jvtesttarget;
    ASSERT_NO_THROW({
			bso.filterInSampleWork(jvtesttarget, testroot);
        });
    ASSERT_EQ(jvtesttarget[Bio::SampleWorkKey][0]["Type"],"Hack");
}

TEST(BioSeer, CHECK_filterInSubjectData) {
	Bio::Seer bso;
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_literal_7, testroot );
	});
	Json::Value jvtesttarget;
    ASSERT_NO_THROW({
			bso.filterInSubjectData(jvtesttarget, testroot);
        });
    ASSERT_EQ(jvtesttarget["Name"],"Xeno Campanoli");
}

TEST(BioSeer, CHECK_validateCompleteSubjectTree) {
	Bio::Seer bso;
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_literal_7, testroot );
	});
    ASSERT_NO_THROW({
			bso.validateCompleteSubjectTree(testroot);
        });
}

TEST(BioSeer_Settings,CHECK_setExcludeCareerString) {
	Bio::Seer bso;
	bso.setExcludeCareerString("Blek");
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	std::string dumped_output = testing::internal::GetCapturedStdout();
	std::cout << dumped_output;
	ASSERT_TRUE(dumpHasStr(dumped_output,"CareerExclusionString:Blek"));
}

TEST(BioSeer_Settings,CHECK_setExcludeEmployerString) {
	Bio::Seer bso;
	bso.setExcludeEmployerString("Blek");
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	std::string dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"EmployerExclusionString:Blek"));
}

TEST(BioSeer_Settings,CHECK_setEducationRequired) {
	Bio::Seer bso;
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	std::string dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"EducationRequired:0"));
	bso.setEducationRequired();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"EducationRequired:1"));
	bso.setEducationNotRequired();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"EducationRequired:0"));
}

TEST(BioSeer_Settings,CHECK_setExperienceRequired) {
	Bio::Seer bso;
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	std::string dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"ExperienceRequired:0"));
	bso.setExperienceRequired();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"ExperienceRequired:1"));
	bso.setExperienceNotRequired();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"ExperienceRequired:0"));
}

TEST(BioSeer_Settings,CHECK_setSampleWorkRequired) {
	Bio::Seer bso;
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	std::string dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"SampleWorkRequired:0"));
	bso.setSampleWorkRequired();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"SampleWorkRequired:1"));
	bso.setSampleWorkNotRequired();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"SampleWorkRequired:0"));
}

TEST(BioSeer_Settings,CHECK_setExcludeExperienceAnecdotesRemainders) {
	Bio::Seer bso;
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	std::string dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"IncludeExperienceAnecdotesRemainders:1"));
	bso.setExcludeExperienceAnecdotesRemainders();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"IncludeExperienceAnecdotesRemainders:0"));
	bso.setIncludeExperienceAnecdotesRemainders();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"IncludeExperienceAnecdotesRemainders:1"));
}

TEST(BioSeer_Settings,CHECK_setExcludeUnrelatedExperience) {
	Bio::Seer bso;
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	std::string dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"IncludeUnrelatedExperience:0"));
	bso.setIncludeUnrelatedExperience();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"IncludeUnrelatedExperience:1"));
	bso.setExcludeUnrelatedExperience();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"IncludeUnrelatedExperience:0"));
}

TEST(BioSeer_Settings,CHECK_setExcludeUnrelatedSampleWork) {
	Bio::Seer bso;
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	std::string dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"IncludeUnrelatedSampleWork:0"));
	bso.setIncludeUnrelatedSampleWork();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"IncludeUnrelatedSampleWork:1"));
	bso.setExcludeUnrelatedSampleWork();
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"IncludeUnrelatedSampleWork:0"));
}

TEST(BioSeer_Settings,CHECK_setSkillFilter) {
	Bio::Seer bso;
	bso.setSkillFilter("Blek");
	testing::internal::CaptureStdout();
	bso.DumpInternals();
	std::string dumped_output = testing::internal::GetCapturedStdout();
	ASSERT_TRUE(dumpHasStr(dumped_output,"SkillWanted:Blek"));
}

TEST(BioSeer_Validations,CHECK_validateEducation) {
	Bio::Seer bso;
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_literal_7, testroot );
	});
    ASSERT_NO_THROW({
			bso.validateEducation(testroot);
        });
    Json::Value testroot2;
    ASSERT_NO_THROW({
		reader.parse( test_literal_1, testroot );
	});
    ASSERT_THROW({
		bso.validateEducation(testroot2);
        },
        std::invalid_argument
        );
}

TEST(BioSeer_Validations,CHECK_validateExperience) {
	Bio::Seer bso;
    Json::Reader reader;
    Json::Value testroot;
    ASSERT_NO_THROW({
		reader.parse( test_literal_7, testroot );
	});
    ASSERT_NO_THROW({
			bso.validateExperience(testroot);
        });
    Json::Value testroot2;
    ASSERT_NO_THROW({
		reader.parse( test_literal_1, testroot );
	});
    ASSERT_THROW({
		bso.validateExperience(testroot2);
        },
        std::invalid_argument
        );
}
*/

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
