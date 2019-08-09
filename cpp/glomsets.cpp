/* glomsets.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890
 */

#include "glomsets.hpp"

#include <exception>

namespace Inlay {

	const std::string OptionalTagPattern	= "###([^#]*)###([^#]*)###([^#]*)###";
	const std::string RequiredTagPattern	= "@@@([^@]*)@@@";
	const std::string SubMoldTagPattern		= "\\^\\^\\^([^^]*)\\^\\^\\^";

	// GlomBase stuff first:

	GlomBase::GlomBase(const std::string& tagPattern,const std::string& targetText) :
		SMatchO(findFirst(tagPattern,targetText))
		{}

	const std::smatch GlomBase::findFirst(const std::string& tagPattern,const std::string& targetText) {
		std::smatch smo;
		const std::regex TagRegexO = std::regex(tagPattern);
		std::string ltt = targetText;
		std::regex_search(ltt, smo, TagRegexO);
		return smo;
	}

	void GlomBase::replaceFoundIdentifier(std::string& targetText, std::string& replacementString) {
		const std::string		idpattern	= _get_Id_Pattern(SMatchO);
		const size_t			position	= targetText.find(idpattern);
		const size_t			idsize		= idpattern.size();
		const std::string		lrstr		= _adjust_Replacement_String(replacementString,SMatchO);

		targetText.replace(position, idsize, lrstr);
	}

	// Then derived glomset class methods:

	//		Begin MustSubMoldGlom:

	const std::string MustSubMoldGlom::_adjust_Replacement_String(const std::string& replacementString, const std::smatch& sMO) {
		if ( sMO.empty() ) throw "Try to make warning go away until better way to handle it found.";
		return replacementString;
	}
	const std::string MustSubMoldGlom::_get_Identifier(const std::smatch& sMO) {
		return sMO[1].str();
	}
	const std::string MustSubMoldGlom::_get_Id_Pattern(const std::smatch& sMO) {
		return sMO[0].str();
	}

	MustSubMoldGlom::MustSubMoldGlom(const std::string& targetText) : GlomBase(SubMoldTagPattern,targetText) {}

	//		Begin OptionalGlom:

	const std::string OptionalGlom::_adjust_Replacement_String(const std::string& replacementString, const std::smatch& sMO) {
		std::string lars = sMO[1].str() + replacementString + sMO[3].str();
		return lars;
	}
	const std::string OptionalGlom::_get_Identifier(const std::smatch& sMO) {
		return sMO[2].str();
	}
	const std::string OptionalGlom::_get_Id_Pattern(const std::smatch& sMO) {
		return sMO[0].str();
	}

	OptionalGlom::OptionalGlom(const std::string& targetText) :  GlomBase(OptionalTagPattern,targetText) {}

	//		Begin RequiredGlom:

	const std::string RequiredGlom::_adjust_Replacement_String(const std::string& replacementString, const std::smatch& sMO) {
		if ( sMO.empty() ) throw "Try to make warning go away until better way to handle it found.";
		return replacementString;
	}
	const std::string RequiredGlom::_get_Identifier(const std::smatch& sMO) {
		return sMO[1].str();
	}
	const std::string RequiredGlom::_get_Id_Pattern(const std::smatch& sMO) {
		return sMO[0].str();
	}

	RequiredGlom::RequiredGlom(const std::string& targetText) : GlomBase(RequiredTagPattern,targetText) {}

} // End of namespace Inlay

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of glomsets.cpp
