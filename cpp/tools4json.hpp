/* tools4json.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890

 */
#pragma once

#include <jsoncpp/json/json.h>
#include <set>
#include <string>

namespace ToolsForJSON {

	void DumpStringFromJsonValueTree(Json::Value& jvoR,bool lineDelimited=false);

	std::string GetStringFromJsonValueTree(Json::Value& jvoR);

	void mergeJsonValues(Json::Value& targetJvoR,
						const Json::Value& sourceJvoR,
						const std::set<std::string>& RequiredKeys,
						const std::set<std::string>& OptionalKeys);

	bool stringWantedInArray(	const std::string StringWanted,
										const Json::Value& jvoR);

	void validateArrayField(const Json::Value& jvoR, const std::string& keyArg);

	void validateDictionaryField(	const Json::Value& jvoR,
									const std::string& keyArg);

	void validateField(const Json::Value& jvoR, const std::string& keyArg);

	void validateJsonStringValues(const Json::Value& jvoR,
								const std::set<std::string>& RequiredKeys,
								const std::set<std::string>& OptionalKeys);

	void validateStringData(const Json::Value& jvoR,
							const std::string& keyArg,
							const uint8_t minValue);

	void validateStringField(const Json::Value& jvoR, const std::string& keyArg);
};

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of tools4json.hpp
