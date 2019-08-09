/* subjectseer.hpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890

	This class is intended to be the data-structure aware level of the JSON data.
	As such, it needs to see the various layers expected in the Json::Value
	trees, but also help the lower levels be ignorant of that structure.
 */
#pragma once

#include "env.hpp"

namespace Inlay {

	void validateMonthString(const std::string sArg);

	class SubjectSeer {

		public:

		SubjectSeer();

		virtual void validateCompleteSubjectTree(const Json::Value& jvoR) const = 0;

		void validateDefaultsTree(const Json::Value& jvoR) const;

	};

} // End of namespace Inlay

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of subjectseer.hpp
