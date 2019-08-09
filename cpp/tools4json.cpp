/* tools4json.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890

 */

#include "tools4json.hpp"

#include <assert.h>
#include <iostream>
#include <regex>

namespace ToolsForJSON {

	void DumpStringFromJsonValueTree(Json::Value& jvoR,bool lineDelimited) {
		std::string sb = GetStringFromJsonValueTree(jvoR);
		const std::string l = std::string(80,'-');
		if ( lineDelimited ) std::cout << l << std::endl;
		std::cout << sb << std::endl;
		if ( lineDelimited ) std::cout << l << std::endl;
	}

	std::string GetStringFromJsonValueTree(Json::Value& jvoR) {
		Json::StreamWriterBuilder builder;
		builder["indentation"] = ""; // No whitespace indicated.
		const std::string string_content = Json::writeString(builder, jvoR);
		return string_content;
	}

	void mergeJsonValues(Json::Value& targetJvoR,
						const Json::Value& sourceJvoR,
						const std::set<std::string>& RequiredKeys,
						const std::set<std::string>& OptionalKeys) {
		std::string bi;
		for(bi : RequiredKeys) {			targetJvoR[bi] = sourceJvoR[bi]; }
		for(bi : OptionalKeys) {
			if ( sourceJvoR.isMember(bi) )	targetJvoR[bi] = sourceJvoR[bi];
		} 
	}

	bool stringWantedInArray(const std::string StringWanted,const Json::Value& jvoR) {
		assert(jvoR.isArray());
		for (const auto& si : jvoR)
			if (si.isString() && si.asString() == StringWanted)
				return true;
		return false;
	}

	void validateField(const Json::Value& jvoR, const std::string& keyArg) {
		if ( jvoR.isMember(keyArg) ) return;
		std::string m = "No " + keyArg + " key exists.";
		throw std::invalid_argument(m);
	}

	void validateJsonStringValues(const Json::Value& jvoR,
								const std::set<std::string>& RequiredKeys,
								const std::set<std::string>& OptionalKeys) {
		Json::StreamWriterBuilder builder;
		builder["indentation"] = ""; // If you want whitespace-less output
		const std::string output = Json::writeString(builder, jvoR);
		std::string bi;
		std::string estr;
		for(bi : RequiredKeys) {
			validateStringData(jvoR,bi,2);
		}
		for(bi : OptionalKeys) {
			validateStringField(jvoR,bi);
		}
	}

	void validateArrayField(const Json::Value& jvoR, const std::string& keyArg) {
		validateField(jvoR,keyArg);
		if ( jvoR[keyArg].isArray() ) return;
		std::string m = "Field " + keyArg + " is not an Array.";
		throw std::invalid_argument(m);
	}

	void validateArrayOfStringsField(const Json::Value& jvoR, const std::string& keyArg) {
		validateField(jvoR,keyArg);
		Json::Value jvb;
		for(jvb : jvoR[keyArg]) { validateStringField(jvb,keyArg); }
	}

	void validateDictionaryField(const Json::Value& jvoR, const std::string& keyArg) {
		// I use the term Dictionary here because of other ambiguities.
		// See Python use of the term Dictionary, Ruby use of "Hash".
		validateField(jvoR,keyArg);
		if ( jvoR[keyArg].isObject() ) return;
		std::string m = "Field " + keyArg + " is not an Dictionary.";
		throw std::invalid_argument(m);
	}

	void validateStringData(const Json::Value& jvoR,
							const std::string& keyArg,
							const uint8_t minValue) {
		validateStringField(jvoR,keyArg);
		std::string sb = jvoR[keyArg].asString();
		size_t ls = sb.size();
		if ( ls >= minValue ) return;
		std::string szs = std::to_string(ls);
		std::string ns = std::to_string(minValue);
		std::string m =
			"Field " + keyArg + " of size " + szs + " is not a minimum " + ns + " sized String.";
		throw std::invalid_argument(m);
	}

	void validateStringField(const Json::Value& jvoR, const std::string& keyArg) {
		validateField(jvoR,keyArg);
		if ( jvoR[keyArg].isString() ) return;
		std::string m = "Field " + keyArg + " is not a String.";
		throw std::invalid_argument(m);
	}

}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of tools4json.cpp
