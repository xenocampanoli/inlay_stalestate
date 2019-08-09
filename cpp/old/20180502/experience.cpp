// subjectseer.cpp

#include "seepfilter.hpp"

#include <regex>
#include <iostream>

SeepFilter::SeepFilter() {
	IncludeExperienceAnecdotesRemainders = true;
	IncludeUnrelatedExperience = false;
	IncludeUnrelatedSampleWork = false;
};

bool SeepFilter::isExcludedCareer(const std::string& careerField) {
	bool bb = _isExcludedByCategoryString(ExcludeJobsByCareerString,careerField);
	return bb;
}

bool SeepFilter::isExcludedEmployer(const std::string& employerField) {
	bool bb = _isExcludedByCategoryString(ExcludeJobsByEmployerString,employerField);
	return bb;
}

void SeepFilter::_mixInEducation(Json::Value& cookingSapOR, const Json::Value& mixInSapOR) {
}

void SeepFilter::_mixInExperience(Json::Value& cookingSapOR, const Json::Value& mixInSapOR) {
}

void SeepFilter::_mixInIdentification(Json::Value& cookingSapOR, const Json::Value& mixInSapOR) {
}

void SeepFilter::_mixInSampleWork(Json::Value& cookingSapOR, const Json::Value& mixInSapOR) {
}

void SeepFilter::mixInBoleSap(Json::Value& cookingSapOR, const Json::Value& mixInSapOR) {

	validateIdentification(mixInSapOR);
	_mixInIdentification(cookingSapOR,mixInSapOR);
	validateExperience(mixInSapOR);
	_mixInExperience(cookingSapOR,mixInSapOR[ExperienceKey]);
	_mixInEducation(cookingSapOR,mixInSapOR);
	_mixInSampleWork(cookingSapOR,mixInSapOR);
}

void SeepFilter::validateEducation(const Json::Value& mixInSapOR) {
	if ( ! mixInSapOR.isMember(EducationKey) ) throw std::invalid_argument("No Education Key.");
	if ( ! mixInSapOR[EducationKey].isArray() ) throw std::invalid_argument("No Array in Education.");
	if ( ! mixInSapOR[EducationKey][0].isObject() ) throw std::invalid_argument("No Object element in Education Array.");
	Json::Value jvb = mixInSapOR[EducationKey];
	_validateStringField("Institution");
	_validateStringField("Certification");
	_validateStringData("Subject");
	_validateStringField("Secondary Interests");
	_validateStringField("Comments");
	std::cout << "trace 9 validateEducation" << std::endl;
}

void SeepFilter::validateExperience(const Json::Value& mixInSapOR) {
	if ( ! mixInSapOR.isMember(ExperienceKey)) throw std::invalid_argument("No Experience Key in BoleSap.");
}

void SeepFilter::validateIdentification(const Json::Value& mixInSapOR) {
	if ( ! mixInSapOR.isMember(IdentificationKey)) throw std::invalid_argument("No Identification Key in BoleSap.");
}

void SeepFilter::validateSampleWork(const Json::Value& mixInSapOR) {
	if ( ! mixInSapOR.isMember(SampleWorkKey)) throw std::invalid_argument("No SampleWork Key in BoleSap.");
}

// End of subjectseer.cpp
