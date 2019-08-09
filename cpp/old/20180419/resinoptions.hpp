// resinoptions.hpp

#include "env.hpp"

#include <ctime>

#include <map>
#include <vector>

class ResinOptions {

	public:

	getSkillSet();
	hasSkill(const Json::Value& jvoR);
	includeExampleRemainders(const Json::Value& jvoR);
	inExperienceYearsRange(const Json::Value& jvoR);
	inJobIndexRange(const Json::Value& jvoR);
	neededExample(const Json::Value& jvoR);
	stintHasMinMonths(const Json::Value& jvoR);

	setEarlyYearsToExclude(std::string optArg);
	setExcludeExperienceRemainder();
	setIncludeExperienceRemainder();
	setIncludeUnrelatedExperience();
	setJobsExclude(std::string optArg);
	setJobsInclude(std::string optArg);
	setOmitUnrelatedExperience();
	setSkillFilterSet(std::string optArg);
	setYearsBackToInclude(std::string optArg);

	ResinOptions();
};

// End of resinoptions.hpp
