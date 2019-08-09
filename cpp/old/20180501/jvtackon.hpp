#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <string>

class JVTackon {

	private:

	const Json::Value JVOR;

	public:

	JVTackon(const Json::Value& jvoR);
};
