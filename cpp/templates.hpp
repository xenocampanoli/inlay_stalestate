/* templates.hpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890

 */
#pragma once

#include "env.hpp"
#include "subjectseer.hpp"

namespace Inlay {

	/* Apologies, but Mold is the template class, and it is shorter, so I stayed
		with it.  However I wanted to visibly call the files template for clarity
		at the higher level.
	 */
	class Mold {

		public:

		std::string getTemplateFilePath(const std::string moldKey) {
			std::string filepath = MoldDir + "/" + moldKey + "." + MoldExtension; 
			return filepath;
		} 

		std::string getString();

		Mold(	const std::string& moldDir,
				const std::string& moldKey);

		Mold(	const std::string& moldDir,
				const std::string& moldKey,
				const std::string& moldExtension);

		Mold(const Mold &moldO);

		bool templateFileExists(std::string fieldKey);

		bool topTemplateFileExists();

		std::shared_ptr<Mold> newSubTemplate(const std::string keyField) const;

		private:

		const std::string MoldDir;
		const std::string MoldExtension;
		const std::string MoldKey;  // Json key also to be used as file name here.

		// ------------------------------------------------------------------------

		const std::string findExtensionFromMoldKey(const std::string& moldDir, const std::string& moldKey);

	};

} // End of namespace Inlay

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of templates.hpp
