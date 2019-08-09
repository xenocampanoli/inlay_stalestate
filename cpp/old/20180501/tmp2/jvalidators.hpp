// jvalidators.hpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

/* An independently validated library of jsoncpp Json::Value test methods.
 */

#include "env.hpp"

#include <stdint.h>

class JsonValidators {

	private:

	Json::Value JVObject;

	void _validateField(const std::string& keyArg) {
		if ( JVObject.isMember(keyArg) ) return;
		std::string m = "No " + keyArg + " key exists.";
		throw std::invalid_argument(m);
	}
	
    public:

	JsonValidators(Json::Value& jvoR);

	inline void validateArrayField(const std::string& keyArg) {
		_validateField(keyArg);
		if ( JVObject[keyArg].isArray() ) return;
		std::string m = "Field " + keyArg + " is not an Array.";
		throw std::invalid_argument(m);
	}
	inline void validateDictionaryField(const std::string& keyArg) {
		// I use the term Dictionary here because of other ambiguities.
		// See Python use of the term Dictionary, Ruby use of "Hash".
		_validateField(keyArg);
		if ( JVObject[keyArg].isObject() ) return;
		std::string m = "Field " + keyArg + " is not an Dictionary.";
		throw std::invalid_argument(m);
	}
	inline void validateStringField(const std::string& keyArg) {
		std::cout << "trace 0 validateStringField" << std::endl;
		_validateField(keyArg);
		std::cout << "trace 2 validateStringField" << std::endl;
		if ( JVObject[keyArg].isString() ) return;
		std::cout << "trace 5 validateStringField" << std::endl;
		std::string m = "Field " + keyArg + " is not a String.";
		throw std::invalid_argument(m);
		std::cout << "trace 9 validateStringField" << std::endl;
	}

	void validateStringData(const std::string& keyArg,const uint8_t minValue);
};

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of jvalidators.hpp
