// glomsets.hpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "env.hpp"


class GlomBase { // State Changing Object!!

	private:

	const std::string identifier; // Json Key within the interpolation pattern to be processed.
	const std::string idpattern;  // The actual interpolation pattern to be processed.
	const std::smatch SMatchO;
	const std::string TagPattern;
	const std::regex TagRegexO;

	const std::smatch findFirst(std::string targetText);

	virtual const std::string _adjust_Replacement_String(const std::string replacmentString,const std::smatch sMO) = 0;
	virtual const std::string _get_Identifier(const std::smatch sMO) = 0;
	virtual const std::string _get_Id_Pattern(const std::smatch sMO) = 0;

	inline const std::string getIdentifier() {
		const std::string b = _get_identifier(smatch_object);
		return b;
	}
	inline const std::string getIdPattern() {
		const std::string b = _get_Id_Pattern(smatch_object);
		return b;
	}

	public:

	GlomBase(const std::string& tagPattern,const std::string& targetText);

	void replaceFoundIdentifier(std::string targetText, std::string replacementString);
};

class MustSubMoldGlom: public GlomBase {
};

class OptionalGlom: public GlomBase {
	const std::string _get_Identifier(std::smatch sMO) {
	}
	const std::string _get_Id_Pattern(std::smatch sMO) {
	}
	const std::string getPrefix(std::smatch sMO) {
	}
	const std::string getSuffix(std::smatch sMO) {
	}
};

class RequiredGlom: public GlomBase {
	const std::string _get_Identifier(std::smatch sMO) {
	}
	const std::string _get_Id_Pattern(std::smatch sMO) {
	}
};

const std::vector<GlomBase* (*)()> FactoryVector;

MustSubMoldGlom*	createMustSubMoldGlomObject();
OptionalGlom*		createOptionalGlomObject();
RequiredGlom*		createRequiredGlomObject();

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of glomsets.hpp
