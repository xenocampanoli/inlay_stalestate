/* subject.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890
Holds the abstract content of subject data in a single Json::Value tree object.
Said tree is constructed from a defaults Json file, and a primary subject file
that is filtered by a subjectseer object that knows about it's structure.  So
this object is somewhat structure ignorant, and to be properly prepared and
utilized, the subject seer needs to be passed as an cooperative compositional
object.  Said seer object can be for Experience (like Career or CV) data, or
a tract of some kind (for advertising or political work) or an article or even
a book.
 */

#include "subject.hpp"

// Begin:  All includes here should be specific only to this file:
#include <exception>
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <set>
#include <sstream>
#include <streambuf>
#include <sys/stat.h>
#include <time.h>
#include <regex>
#include <unistd.h>

namespace Inlay {

	void Subject::Dump(const Json::Value& jvoR, std::string itemKey = "") {
		if ( jvoR.size() <= 0 ) {
			std::cout << "Non-positive size of seen:  " << jvoR.size() << "." << std::endl;
			return;
		}
		if ( itemKey.size() > 0 ) {
			std::cout << "Json::Value dump for item key '" << itemKey << "':  '" << jvoR[itemKey].asString() << "'." << std::endl;
		} else {
			std::cout << "Json::Value object tree dump:  '" << jvoR.asString() << "'." << std::endl;
		}
	}

	std::string Subject::GetMonthlyString(const Json::Value& jvoR, const std::string& itemKey) {
		std::string mik = "Monthly" + itemKey;
		if ( ! jvoR.isMember(mik) ) {
			std::string estr = "Month key " + itemKey = " not found.";
			throw std::invalid_argument(estr);
		}
		static const std::vector<std::string> month_array =
			{"January","February","March","April","May","June",
			"July","August","September","October","November","December"};
		time_t rawtime;
		time(&rawtime);
		struct tm *ts = localtime(&rawtime);
		std::string month = month_array[ts->tm_mon];
		return jvoR[mik][month].asString();
	}

	Json::Value Subject::ParseSubject(const std::string& fnString) {

		std::string lfs = fnString;
		const char *cfn = lfs.c_str();
		struct stat statbuffer;
		if ( stat(cfn,&statbuffer) != 0 ) {
			char pwd_b[128];
			char fpath_b[256];
			getcwd(pwd_b,128);
			sprintf(fpath_b,"%s/%s",pwd_b,(char *)cfn);
			if ( stat(fpath_b,&statbuffer) != 0 ) {
				char estr1[328];
				sprintf(estr1,"failed to find file path at either %s or %s.",cfn,fpath_b);
				throw std::invalid_argument(estr1);
			}
			lfs = fpath_b;
		}

		std::ifstream input_buffer(lfs.c_str());
		std::istreambuf_iterator<char> beginIt(input_buffer);
		std::istreambuf_iterator<char> endIt;
		std::string input_text(beginIt,endIt);//Meyers p35 on STL 0-201-74962-9

		Json::Reader reader;
		Json::Value root;
		if ( reader.parse( input_text, root ) ) return root;

		std::cout << reader.getFormattedErrorMessages();
		std::string estr2 ="Failure in attempt to parse json from " + lfs + ".";
		throw std::runtime_error(estr2);
	}

	Subject::Subject(std::string& defaultsFile, std::string& subjectFile, SubjectSeer& ssO) : Tree(ParseSubject(defaultsFile)) {
		ssO.validateDefaultsTree(Tree);
		const Json::Value sdb = ParseSap(subjectFile);
		ssO.filterInSubjectData(Tree,sdb);
		ssO.validateCompleteSubjectTree(Tree);
	}

	std::string Subject::glomMoldList(std::shared_ptr<Mold> moldPO, const Json::Value& jvoR) {
		std::string entire;

		for (Json::Value::const_iterator cilo = jvoR.begin(); cilo != jvoR.end(); cilo++) {
			entire += glomMoldTree(moldPO,cilo);
		}
		return entire;
	}

	std::string Subject::glomMoldTree(std::shared_ptr<Mold> moldPO, const Json::Value& jvoR) {
		const std::vector<GlomBase* (*)(std::string)> FactoryVector =
			{
				[](std::string targetText) -> MustSubMoldGlom	{ return std::make_unique<MustSubMoldGlom>(targetText); },
				[](std::string targetText) -> OptionalGlom		{ return std::make_unique<OptionalGlom>(targetText); },
				[](std::string targetText) -> RequiredGlom		{ return std::make_unique<RequiredGlom>(targetText); }
			};
		std::string					fieldkey;
		std::unique_ptr<GlomBase>	pattpo;
		std::string					replacement;
		std::shared_ptr<Mold>		submoldo;

		std::string	product = moldPO.getString();
		for(std::unique_ptr<GlomBase* (*)(std::string)> factorypo : FactoryVector) {
			pattpo = factorypo(product);
			while ( pattpo->itemFound() ) {
				fieldkey = pattpo->getIdentifier();
				if ( moldPO.subMoldExists(fieldkey) ) {
					submoldo = moldPO.newSubMold(fieldkey);
					if ( jvoR.isList(fieldkey) ) {
								replacement = glomMoldList(submoldo,jvoR[fieldkey]);
					} else {
						if jvoR.has_key(fieldkey)
								replacement = glomMoldTree(submoldo,jvoR[fieldkey]);
						else 	replacement = glomMoldTree(submoldo,jvoR);
					}
				} else {
					if ( jvoR.has_key(fieldkey) ) replacement = jvoR[fieldkey].asString();
					else {
								replacement = "Missing submold for sub-list " + fieldkey + std::endl;
								continue;
					}
				}
				pattpo->replaceFoundIdentifier(product, replacement);

				pattpo = factorypo(product);
			}
		}
		return product;
	}

} // End of namespace Inlay

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of subject.cpp
