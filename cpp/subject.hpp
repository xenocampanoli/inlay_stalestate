/* subject.hpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890

 */
#pragma once

#include "env.hpp"
#include "subjectseer.hpp"
#include "templates.hpp"

namespace Inlay {

	class Subject {

		public:

		std::string GetMonthlyString(const Json::Value& jvoR, const std::string& itemKey);

		std::string glomMoldList(std::shared_ptr<Mold> moldPO, const Json::Value& jvoR);
		std::string glomMoldTree(std::shared_ptr<Mold> moldPO, const Json::Value& jvoR);

		void Dump(const Json::Value& jvoR, std::string itemKey);

		Subject(std::string& defaultsFile, std::string& subjectFile, SubjectSeer& ssO);

		private:

		Json::Value Tree;

		Json::Value ParseSubject(const std::string& fnString);

	};

} // End of namespace Inlay

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of Subject.hpp
