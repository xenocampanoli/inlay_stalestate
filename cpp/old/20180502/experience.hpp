// subjectseer.hpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

/*	This class is intended to be the data-structure aware level of the JSON data.
	As such, it needs to see the various layers expected in the Json::Value
	trees, but also help the lower levels be ignorant of that structure.
 */

#include "env.hpp"

class SeepFilter {

	private:

	std::string EarliestMonth;
	std::string LatestMonth;

	std::vector<std::string> ExcludeJobsByCareerString;
	std::vector<std::string> ExcludeJobsByEmployerString;

	bool IncludeExperienceAnecdotesRemainders;
	bool IncludeUnrelatedExperience;
	bool IncludeUnrelatedSampleWork;

	std::vector<std::string> SkillsWanted;

	// -------------------------------------------------------------------------

	void _mixInIdentification(Json::Value& cookingSapOR, const Json::Value& mixInSapOR);
	void _mixInEducation(Json::Value& cookingSapOR, const Json::Value& mixInSapOR);
	void _mixInExperience(Json::Value& cookingSapOR, const Json::Value& mixInSapOR);
	void _mixInSampleWork(Json::Value& cookingSapOR, const Json::Value& mixInSapOR);

	bool isExperienceTree(Json::Value& jvoR);
	bool isListField(Json::Value& jvoR);
	bool isHashField(Json::Value& jvoR);

	inline void validateMonthString(std::string sArg) {
		const std::string MonthStringPattern = "^2[0-9][0-9][0-9][01][0-9]$";
		if (std::regex_match(sArg,std::regex(MonthStringPattern))) return;
		std::string estr = "String " + sArg +
			" is not in the required month string pattern:  " +
			MonthStringPattern;
		throw std::invalid_argument(estr);
	}

	bool isSampleWorkdTree(Json::Value& jvoR);
	bool isScalarField(Json::Value& jvoR);
	bool isSkillsFlaggedList(Json::Value& jvoR);
	bool isTrainingList(Json::Value& jvoR);

	inline bool _isExcludedByCategoryString(std::vector<std::string> catStrVector,std::string catField) {
		std::string pb;
		for(std::string loopcstr : catStrVector) {
			pb = ".*" + loopcstr + ".*";
			if (std::regex_match(catField,std::regex(pb))) return true;
		}
		return false;
	}

	inline void _validateStringData(Json::Value& jvoR, std::string keyArg) {
	}

	inline void _validateStringField(Json::Value& jvoR, std::string keyArg) {
	}

    public:

	void _validateField(const std::string& keyArg) {
		if ( JVOP->isMember(keyArg) ) return;
		std::string m = "No " + keyArg + " key exists.";
		throw std::invalid_argument(m);
	}
	
	inline void validateArrayField(const std::string& keyArg) {
		_validateField(keyArg);
		if ( (*JVOP)[keyArg].isArray() ) return;
		std::string m = "Field " + keyArg + " is not an Array.";
		throw std::invalid_argument(m);
	}
	inline void validateDictionaryField(const std::string& keyArg) {
		// I use the term Dictionary here because of other ambiguities.
		// See Python use of the term Dictionary, Ruby use of "Hash".
		_validateField(keyArg);
		if ( (*JVOP)[keyArg].isObject() ) return;
		std::string m = "Field " + keyArg + " is not an Dictionary.";
		throw std::invalid_argument(m);
	}
	inline void validateStringField(const std::string& keyArg) {
		std::cout << "trace 0 validateStringField" << std::endl;
		_validateField(keyArg);
		std::cout << "trace 2 validateStringField" << std::endl;
		if ( (*JVOP)[keyArg].isString() ) return;
		std::cout << "trace 5 validateStringField" << std::endl;
		std::string m = "Field " + keyArg + " is not a String.";
		throw std::invalid_argument(m);
		std::cout << "trace 9 validateStringField" << std::endl;
	}

	void validateStringData(const std::string& keyArg,const uint8_t minValue);
	bool isExcludedCareer(const std::string& careerField);
	bool isExcludedEmployer(const std::string& employerField);

	bool includeExperienceAnecdote(Json::Value& jvoR);
	bool includeUnrelatedExperience(Json::Value& jvoR);
	inline bool includeExperienceAnecdotesRemainders() { return IncludeExperienceAnecdotesRemainders; }
	bool includeSampleWork(Json::Value& jvoR);

	bool itemHasSkill(Json::Value& jvoR);

	void mixInBoleSap(Json::Value& cookingSap, const Json::Value& sapNodeO);

	SeepFilter();

	inline void setExcludeCareerString(const std::string oArg) {
		ExcludeJobsByCareerString.push_back(oArg);
	}
	inline void setExcludeEmployerString(const std::string oArg) {
		ExcludeJobsByEmployerString.push_back(oArg);
	}
	inline void setExcludeExperienceAnecdotesRemainders() {
		IncludeExperienceAnecdotesRemainders = true;
	}
	inline void setIncludeExperienceAnecdotesRemainders() {
		IncludeExperienceAnecdotesRemainders = false;
	}
	inline void setIncludeUnrelatedExperience() {
		IncludeUnrelatedExperience = true;
	}
	inline void setOmitUnrelatedExperience() {
		IncludeUnrelatedExperience = false;
	}
	inline void setIncludeUnrelatedSampleWork() {
		IncludeUnrelatedSampleWork = true;
	}
	inline void setOmitUnrelatedSampleWork() {
		IncludeUnrelatedSampleWork = false;
	}
	inline void setSkillFilterSet(const std::string oArg) {
		SkillsWanted.push_back(oArg); 
	}
	inline void setMonthEarliest(const std::string oArg) {
		validateMonthString(oArg);
		EarliestMonth = oArg;
	}
	inline void setMonthLatest(const std::string oArg) {
		validateMonthString(oArg);
		LatestMonth = oArg;
	}

	void validateEducation(const Json::Value& mixInSapOR);
	void validateExperience(const Json::Value& mixInSapOR);
	void validateIdentification(const Json::Value& mixInSapOR);
	void validateSampleWork(const Json::Value& mixInSapOR);
};

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of subjectseer.hpp
