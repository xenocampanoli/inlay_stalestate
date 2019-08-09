/* subjectseer.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890

 */

#include "tools4json.hpp"
#include "subjectseer.hpp"

#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <regex>
#include <sstream>
#include <string>

using namespace ToolsForJSON;

namespace Inlay {

	void validateMonthString(const std::string sArg) {
		const std::string MonthStringPattern = "^2[0-9][0-9][0-9][01][0-9]$";
		if (std::regex_match(sArg,std::regex(MonthStringPattern))) return;
		std::string estr = "String " + sArg +
			" is not in the required month string pattern:  " +
			MonthStringPattern;
		throw std::invalid_argument(estr);
	}

	SubjectSeer::SubjectSeer() {}

	void SubjectSeer::validateDefaultsTree(const Json::Value& jvoR) const {
		validateStringData(jvoR,"BackgroundColorType", 8);
		validateDictionaryField(jvoR,"Styles");
	}

} // End of namespace Inlay

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of subjectseer.cpp
