/* bioseer.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890
 */

#include <assert.h>
#include <iostream>
#include <regex>

#include "bioseer.hpp"
#include "tools4json.hpp"

namespace Bio {

	bool isSkillString(const std::string& sArg) {
		int i = 0;
		for(auto c : sArg) {
			if (i == 0 && ! std::isalpha(c))	return false;
			if (i == 0 && std::islower(c))		return false;
			if (i != 0 && std::isupper(c))		return false;
			++i;
		}
		return true;
	}

	// Begin Bottom Level Methods / (Not Private)

	/*
		Example:
				"Anecdotes": [
							{  "Description":"Assistance with company automated build and test system.",
								"Skills":["Ubuntu","Jenkins","KVM","Bash"]
							}
							],
	 */
	bool Seer::hasASkillWanted(const Json::Value& jvoR) const {
		assert(jvoR.isArray());
		for(auto& si : jvoR) if( SkillWanted(si.asString()) ) return true;
		return false;
	}
	/*
	bool Seer::hasWantedSkill(Json::Value& jvoR) const {
	}
	bool Seer::jobExcludedByCareerString(Json::Value& jvoR) const {
	}
	bool Seer::jobExcludedByEmployerString(Json::Value& jvoR) const {
	}
	bool Seer::occurrenceTooEarly(Json::Value& jvoR) const {
	}
	bool Seer::occurrenceTooLate(Json::Value& jvoR) const {
	}
	*/

	// Begin Even Lower Lower Level Methods / (Not Private)

	void buildExperienceItem(Json::Value& jvvb,const Json::Value& jvi) {
		Json::Value unwanted = Json::Value(Json::arrayValue);
		Json::Value wanted = Json::Value(Json::arrayValue);
		for(auto& ai : jvi[AnecdotesKey]) {
			if(hasASkillWanted(ai[SkillsKey])
				wanted.append(ai);
			else
				unwanted.append(ai);
		}
		if (	! IncludeUnrelatedExperience
			&&	! SkillsWanted.empty()
			&& wanted.empty() )
				return;
		Json::Value eib;
		eib["Title"]				= jvi["Title"];
		eib["Client Organization"]	= jvi["Client Organization"];
		eib["Payroll Organization"]	= jvi["Payroll Organization"];
		eib["Begin Month"]			= jvi["Begin Month"];
		eib["End Month"]			= jvi["End Month"];
		eib["Summary"]				= jvi["Summary"];
		eib["Anecdotes"]			= wanted;
		if ( IncludeExperienceAnecdotesRemainders && ! unwanted.empty() )
			for(auto& ai : unwanted)
				eib["Anecdotes"].append(ai);
		eib["Supervisor Name"]		= jvi["Supervisor Name"];
		eib["Supervisor Email"]		= jvi["Supervisor Email"];
		eib["Address"]				= jvi["Address"];
		eib["City"]					= jvi["City"];
		eib["Mail Code"]			= jvi["Mail Code"];
		eib["Phone"]				= jvi["Phone"];
		}
		
	}

	void sortIntoNewExperienceBranch(subjectTree[ExperienceKey],jvvb) {
	}

	// Begin Lower Level Methods / (Not Private)

	void Seer::filterInEducation(Json::Value& subjectTree,const Json::Value& personalData) {
		if (if EducationRequired && personalData[EducationKey].empty()) {
			mb = "Education Required, but no Education items available.";
			throw std::invalid_argument(mb);
		}
		subjectTree[EducationKey] = Json::Value(Json::arrayValue);
		// Note no filtering designed in at this time.
		for(auto& jvi : personalData[EducationKey]) {
			if (endMonthBefore(EarliestMonth,jvi["Certification Month"])) continue;
			subjectTree[EducationKey].append(jvi);
		}
	}

	void Seer::filterInExperience(Json::Value& subjectTree,const Json::Value& personalData) {
		if (if ExperienceRequired && personalData[ExperienceKey].empty()) {
			mb = "Experience Required, but no Experience items available.";
			throw std::invalid_argument(mb);
		}
		std::vector<Json::Value> jvvb;
		for(jvi : personalData[ExperienceKey]) { partitionAnecdotes(jvi) }
			if (endMonthBefore(EarliestMonth,jvi["End Month"]))						continue;
			if (startMonthAfter(LastMonth,jvi["Begin Month"]))						continue;
			if (hasString(jvi["Title"],ExcludeJobsByCareerString))					continue;
			if (hasString(jvi["Client Organization"],ExcludeJobsByEmployerString))	continue;
			if (hasString(jvi["Payroll Organization"],ExcludeJobsByEmployerString))	continue;
			buildExperienceItem(jvvb,jvi);
		}
		/*
		subjectTree[ExperienceKey] = Json::Value(Json::arrayValue);
		sortIntoNewExperienceBranch(subjectTree[ExperienceKey],jvvb);
		*/
	}

	void Seer::filterInIdentification(Json::Value& subjectTree,const Json::Value& personalData) {
		/*
		mergeJsonValues(subjectTree,personalData,RequiredIdKeys,OptionalIdKeys);
		*/
		return;
	}

	void Seer::filterInSampleWork(Json::Value& subjectTree,const Json::Value& personalData) {
		subjectTree[SampleWorkKey] = Json::Value(Json::arrayValue);
		for(auto& jvi : personalData[SampleWorkKey]) {
			subjectTree[SampleWorkKey].append(jvi);
		}
	}

	/*
	bool Seer::includeExperienceAnecdote(Json::Value& personalData) {
	}

	bool Seer::includeExperienceItem(const Json::Value& jvoR) const {
		if ( occurrenceTooEarly(jvoR) )				return false;
		if ( occurrenceTooLate(jvoR) )				return false;
		if ( jobExcludedByCareerString(jvoR) )		return false;
		if ( jobExcludedByEmployerString(jvoR) )	return false;
		// The above must come before the below:
		if ( IncludeUnwantedExperience )			return true;
		if ( hasWantedSkills(jvoR) )				return true;
		return false;
	}
	 */

	void Seer::validateEducation(const Json::Value& jvoR) const {
		Seer::validateListAspect(jvoR,
								EducationKey,
								EducationRequired,
								RequiredEducationKeys,
								OptionalEducationKeys);
	}

	void Seer::validateExperience(const Json::Value& jvoR) const {
		Seer::validateListAspect(jvoR,
								ExperienceKey,
								ExperienceRequired,
								RequiredExperienceKeys,
								OptionalExperienceKeys);
	}

	void Seer::validateIdentification(const Json::Value& personalData) const {
		if ( personalData.isMember(IdentificationKey)) {
			return; // For now presume okay, but need to address design issues.
		} else {
			ToolsForJSON::validateJsonStringValues(personalData,RequiredIdKeys,OptionalIdKeys);
		}
	}

	void Seer::validateListAspect(const Json::Value& jvoR,
								const std::string aspectKey,
								const bool aspectRequired,
								const std::set<std::string>& RequiredKeys,
								const std::set<std::string>& OptionalKeys) const {
		std::string mb;
		std::cout << "trace 0 validateListAspect " << aspectKey << "." << std::endl;
		if ( ! jvoR.isMember(aspectKey) ) {
			mb = "No " + aspectKey + " Key.";
			std::cout << "trace 1 validateListAspect" << mb << "." << std::endl;
			throw std::invalid_argument(mb);
		}
		if ( ! jvoR[aspectKey].isArray() ) {
			mb = "No Array in " + aspectKey + ".";
			std::cout << "trace 2 validateListAspect" << mb << "." << std::endl;
			throw std::invalid_argument(mb);
		}
		if ( jvoR[aspectKey].empty() ) {
			if ( aspectRequired ) {
				mb = "Empty " + aspectKey + " Array; " + aspectKey + " Required.";
				std::cout << "trace 3 validateListAspect" << mb << "." << std::endl;
				throw std::invalid_argument(mb);
			}
		} else {
			if ( jvoR[aspectKey][0].isObject() ) {
				Json::Value jvb;
				for(jvb : jvoR[aspectKey]) {
					std::cout << "trace 6 validateListAspect " << aspectKey << "." << std::endl;
					ToolsForJSON::validateJsonStringValues(jvb,RequiredKeys,OptionalKeys);
				}
			} else {
				mb = "No Object element in " + aspectKey + " Array.";
				std::cout << "trace 7 validateListAspect" << mb << "." << std::endl;
				throw std::invalid_argument(mb);
			}
			std::cout << "trace 8 validateListAspect " << aspectKey << "." << std::endl;
		}
		std::cout << "trace 9 validateListAspect " << aspectKey << "." << std::endl;
	}

	void Seer::validateSampleWork(const Json::Value& jvoR) const {
		Seer::validateListAspect(jvoR,
								SampleWorkKey,
								SampleWorkRequired,
								RequiredSampleWorkKeys,
								OptionalSampleWorkKeys);
	}

	// Begin Interface Methods / Public 

	void Seer::DumpInternals() const {
		std::cout << "EarliestMonth:" << EarliestMonth << std::endl;
		std::cout << "EducationRequired:" << EducationRequired << std::endl;
		std::cout << "ExperienceRequired:" << ExperienceRequired << std::endl;
		std::cout << "LatestMonth:" << LatestMonth << std::endl;
		std::string si;
		for(si : ExcludeJobsByCareerString) {
			std::cout << "CareerExclusionString:" << si << std::endl;
		}
		for(si : ExcludeJobsByEmployerString) {
			std::cout << "EmployerExclusionString:" << si << std::endl;
		}
		std::cout << "IncludeExperienceAnecdotesRemainders:" << IncludeExperienceAnecdotesRemainders << std::endl;
		std::cout << "IncludeUnrelatedExperience:" << IncludeUnrelatedExperience << std::endl;
		std::cout << "IncludeUnrelatedSampleWork:" << IncludeUnrelatedSampleWork << std::endl;
		std::cout << "SampleWorkRequired:" << SampleWorkRequired << std::endl;
		for(si : SkillsWanted) {
			std::cout << "SkillWanted:" << si << std::endl;
		}
	}

	Seer::Seer() {
		EducationRequired = false;
		ExperienceRequired = false;
		IncludeExperienceAnecdotesRemainders = true;
		IncludeUnrelatedExperience = false;
		IncludeUnrelatedSampleWork = false;
		SampleWorkRequired = false;
	};

	void Seer::filterInSubjectData(Json::Value& subjectTree, const Json::Value& personalData) {
		/* IMPORTANT NOTE:  This method is designed to modify a Json::Value tree from the Subject class.
			The whole idea is that this class knows what specific kind of internals are in that object
			for that class independent of that class's management of its use, because Subject class
			only needs to use that data generically, and doesn't need to actually understand the
			structure of the information.  This compositional use of something that is the primary
			data item in that class is by design, and should stay that way.  Making custom SubjectSeer
			daughter classes then allows for different kinds of documents.
		 */

std::cout << "trace 1 filterInSubjectData " << std::endl;
		filterInIdentification(subjectTree,personalData);
std::cout << "trace 3 filterInSubjectData " << std::endl;
		filterInExperience(subjectTree,personalData);
std::cout << "trace 5 filterInSubjectData " << std::endl;
		filterInEducation(subjectTree,personalData);
std::cout << "trace 7 filterInSubjectData " << std::endl;
		filterInSampleWork(subjectTree,personalData);
std::cout << "trace 9 filterInSubjectData " << std::endl;
	}

	void Seer::setEducationNotRequired() {
		EducationRequired = false;
	}
	void Seer::setEducationRequired() {
		EducationRequired = true;
	}
	void Seer::setExperienceNotRequired() {
		ExperienceRequired = false;
	}
	void Seer::setExperienceRequired() {
		ExperienceRequired = true;
	}
	void Seer::setSampleWorkNotRequired() {
		SampleWorkRequired = false;
	}
	void Seer::setSampleWorkRequired() {
		SampleWorkRequired = true;
	}
	void Seer::setExcludeCareerString(const std::string oArg) {
		ExcludeJobsByCareerString.insert(oArg);
	}
	void Seer::setExcludeEmployerString(const std::string oArg) {
		ExcludeJobsByEmployerString.insert(oArg);
	}
	void Seer::setExcludeExperienceAnecdotesRemainders() {
		IncludeExperienceAnecdotesRemainders = false;
	}
	void Seer::setIncludeExperienceAnecdotesRemainders() {
		IncludeExperienceAnecdotesRemainders = true;
	}
	void Seer::setExcludeUnrelatedExperience() {
		IncludeUnrelatedExperience = false;
	}
	void Seer::setIncludeUnrelatedExperience() {
		IncludeUnrelatedExperience = true;
	}
	void Seer::setExcludeUnrelatedSampleWork() {
		IncludeUnrelatedSampleWork = false;
	}
	void Seer::setIncludeUnrelatedSampleWork() {
		IncludeUnrelatedSampleWork = true;
	}
	void Seer::setMonthEarliest(const std::string oArg) {
		Inlay::validateMonthString(oArg);
		EarliestMonth = oArg;
	}
	void Seer::setMonthLatest(const std::string oArg) {
		Inlay::validateMonthString(oArg);
		LatestMonth = oArg;
	}
	void Seer::setOmitUnrelatedExperience() {
		IncludeUnrelatedExperience = false;
	}
	void Seer::setOmitUnrelatedSampleWork() {
		IncludeUnrelatedSampleWork = false;
	}
	void Seer::setSkillFilter(const std::string oArg) {
		if ( isSkillString(oArg) ) {
			SkillsWanted.insert(oArg); 
			return;
		} 
		std::string comment =
			"Skill strings must be Capitalized with no whitespace";
		std::string mb = "INVALID:  '" + oArg + "'; " + comment;
		throw std::invalid_argument(mb);
	}

	void Seer::validateCompleteSubjectTree(const Json::Value& jvoR) const {
		validateIdentification(jvoR);
		validateExperience(jvoR);
		validateEducation(jvoR);
		validateSampleWork(jvoR);
	}

}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of bioseer.cpp
