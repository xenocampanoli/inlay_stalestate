/* bioseer.hpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890

	This class is intended to be the data-structure aware level of the JSON
	data.  As such, it needs to see the various layers expected in the
	Json::Value trees, but also help the lower levels be ignorant of that
	structure.
 */
#pragma once

#include <set>

#include "env.hpp"
#include "subjectseer.hpp"

namespace Bio {

	const std::string EducationKey		("Education");
	const std::string ExperienceKey		("Experience");
	const std::string IdentificationKey	("Identification");
	const std::string SampleWorkKey		("SampleWork");

	const std::string AnecdotesKey		("Anecdotes");
	const std::string SkillsKey			("Skills");

	const std::set<std::string> RequiredEducationKeys = { "Subject" };
	const std::set<std::string> OptionalEducationKeys = { "Institution", "Certification", "Secondary Interests", "Comments" };

	const std::set<std::string> RequiredExperienceKeys = { "Title", "Client Organization", "Payroll Organization", "Begin Month", "End Month", "Summary", "City" };
	const std::set<std::string> OptionalExperienceKeys = { "Supervisor Name", "Supervisor Email", "Address", "Mail Code", "Phone" };

	const std::set<std::string> RequiredIdKeys = { "Name" };
	const std::set<std::string> OptionalIdKeys = { "Phone", "Email", "Address", "Summary" };

	const std::set<std::string> RequiredSampleWorkKeys = { "Type","Brief" };
	const std::set<std::string> OptionalSampleWorkKeys = { "CodeURL", "DemoURL", "UniqueId" };

	class Seer : public Inlay::SubjectSeer {

		public:

		void DumpInternals() const;

		bool isExcludedCareer(const std::string& careerField);
		bool isExcludedEmployer(const std::string& employerField);

		bool includeExperienceAnecdote(Json::Value& jvoR);
		bool includeExperienceItem(const Json::Value& jvoR) const;
		bool includeUnrelatedExperience(Json::Value& jvoR);
		inline bool includeExperienceAnecdotesRemainders() { return IncludeExperienceAnecdotesRemainders; }
		bool includeSampleWork(Json::Value& jvoR);

		bool itemHasSkill(Json::Value& jvoR);

		Seer();

		void filterInEducation(Json::Value& subjectTree,const Json::Value& educationData);
		void filterInExperience(Json::Value& subjectTree,const Json::Value& experienceData);
		void filterInIdentification(Json::Value& subjectTree,const Json::Value& personalData);
		void filterInSampleWork(Json::Value& subjectTree,const Json::Value& sampleWorkData);

		void filterInSubjectData(Json::Value& subjectTree, const Json::Value& personalData);

		bool includeExperienceItem(Json::Value& personalData) const;

		void setEducationNotRequired();
		void setEducationRequired();
		void setExperienceNotRequired();
		void setExperienceRequired();
		void setExcludeCareerString(const std::string oArg);
		void setExcludeEmployerString(const std::string oArg);
		void setExcludeExperienceAnecdotesRemainders();
		void setExcludeUnrelatedExperience();
		void setExcludeUnrelatedSampleWork();
		void setIncludeExperienceAnecdotesRemainders();
		void setIncludeUnrelatedExperience();
		void setIncludeUnrelatedSampleWork();
		void setMonthEarliest(const std::string oArg);
		void setMonthLatest(const std::string oArg);
		void setOmitUnrelatedExperience();
		void setOmitUnrelatedSampleWork();
		void setSampleWorkNotRequired();
		void setSampleWorkRequired();
		void setSkillFilter(const std::string oArg);

		void validateCompleteSubjectTree(const Json::Value& jvoR) const;

		void validateEducation(const Json::Value& jvoR) const;
		void validateExperience(const Json::Value& jvoR) const;
		void validateIdentification(const Json::Value& jvoR) const;
		void validateSampleWork(const Json::Value& jvoR) const;

		private:

		std::string EarliestMonth;
		std::string LatestMonth;

		bool EducationRequired;
		bool ExperienceRequired;
		bool SampleWorkRequired;

		std::set<std::string> ExcludeJobsByCareerString;
		std::set<std::string> ExcludeJobsByEmployerString;

		bool IncludeExperienceAnecdotesRemainders;
		bool IncludeUnrelatedExperience;
		bool IncludeUnrelatedSampleWork;

		std::set<std::string> SkillsWanted;

		// -------------------------------------------------------------------------

		void buildInExperienceItem(Json::Value& experienceTree,Json::Value& personalExperience);

		bool anecdoteHasASkillWanted(const Json::Value& jvoR) const;
		bool anecdoteHasSkillMatch(const Json::Value& jvoR) const;

		bool itemHasAnecdoteWithWantedSkill(Json::Value& jvoR);
		bool jobExcludedByCareerString(Json::Value& jvoR);
		bool jobExcludedByEmployerString(Json::Value& jvoR);
		bool occurrenceTooEarly(Json::Value& jvoR);
		bool occurrenceTooLate(Json::Value& jvoR);

		inline bool SkillWanted(std::string sArg) const {
			if (SkillsWanted.find(sArg) == SkillsWanted.end()) return false;
			return true;
		}

		void validateListAspect(const Json::Value& jvoR,
								const std::string aspectKey,
								const bool aspectRequired,
								const std::set<std::string>& RequiredKeys,
								const std::set<std::string>& OptionalKeys) const;

	};

};

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of bioseer.hpp
