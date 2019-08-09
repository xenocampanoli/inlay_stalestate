/* templates.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890

 */

#include "templates.hpp"

#include <exception>
#include <fstream>
#include <glob.h>
#include <iostream>
#include <set>

namespace Inlay {

	const std::string Mold::findExtensionFromMoldKey(const std::string& moldDir, const std::string& moldKey) {
		std::string pattern = moldDir + "/" + moldKey + ".*";
		glob_t glob_result;
		glob(pattern.c_str(),GLOB_TILDE,NULL,&glob_result);
		if ( glob_result.gl_pathc != 1 ) {
			std::string estr ="More than one file find from glob of " + moldKey + ".";
			throw std::invalid_argument(estr);
		}
		std::string bs = std::string(glob_result.gl_pathv[0]);
		globfree(&glob_result);
		std::string extension = bs.substr(bs.find_last_of(".") + 1);
		return extension;
	}

	std::string Mold::getString() {
		std::string fpath = getTemplateFilePath(MoldKey);
		std::ifstream inbuffer(fpath.c_str());
		std::string bs(( std::istreambuf_iterator<char>(inbuffer)),
								 std::istreambuf_iterator<char>());
		return bs;    
	}

	Mold::Mold(const std::string& moldDir,const std::string& moldKey) :
		MoldDir(moldDir),
		MoldExtension(findExtensionFromMoldKey(moldDir,moldKey)),
		MoldKey(moldKey)
		{}

	Mold::Mold(const std::string& moldDir,const std::string& moldKey, const std::string& moldExtension) :
		MoldDir(moldDir),
		MoldExtension(moldExtension),
		MoldKey(moldKey)
											{
		if ( this->topTemplateFileExists() ) return;
		std::string fpath = getTemplateFilePath(MoldKey);
		std::string estr = "File " + fpath + " implied by constructor arguments not found.";
		throw std::invalid_argument(estr);
	}

	bool Mold::templateFileExists(std::string fieldKey) {
		std::string fpath = getTemplateFilePath(fieldKey);
		if ( fileExists(fpath) ) return true;
		return false;
	}

	bool Mold::topTemplateFileExists() {
		bool bb = templateFileExists(MoldKey);
		return bb;
	}

	std::shared_ptr<Mold> Mold::newSubTemplate(const std::string keyField) const {
		std::shared_ptr<Mold> lmo = std::make_shared<Mold>(MoldDir,keyField,MoldExtension);
		return lmo;
	}

} // End of namespace Inlay

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of templates.cpp
