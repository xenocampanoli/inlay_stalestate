// glomsets.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

const std::string OptionalTagPattern	= "###([^#]*)###([^#]*)###([^#]*)###";
const std::string RequiredTagPattern	= "@@@([^@]*)@@@";
const std::string SubMoldTagPattern		= "\\^\\^\\^([^^]*)\\^\\^\\^";

// GlomBase stuff first:

GlomBase::GlomBase(const std::string& tagPattern,const std::string& targetText) :
	TagPattern(tagPattern),
	TagRegexO(std::regex(tagPattern)),
	smatch_object(findFirst(targetText)),
	idpattern(getIdPattern()),
	identifier(getIdentifier())

std::smatch smo; GlomBase::findFirst(std::string targetText) {
	bool bb = std::regex_search(targetText, GlomBase::SMatchO, GlomBase::TagRegexO);
}

void GlomBase::replaceFoundIdentifier(std::string targetText, std::string replacementString) {
	size_t			position	= targetText.find(idpattern);
	size_t			idsize		= idpattern.size();

	targetText.replace(position, idsize, replacementString);
}

void GlomBase::replaceFoundIdentifier(std::string targetText, std::string replacementString) {
	size_t			position	= targetText.find(idpattern);
	size_t			idsize		= idpattern.size();
	std::string		lrstr		= _adjust_Replacement_String(replacmentString,smatch_object)

	targetText.replace(position, idsize, lrstr);
}

// Then derived glomset class methods:

//		Begin MustSubMoldGlom:

const std::string MustSubMoldGlom::_adjust_Replacement_String(const std::string replacementString, const std::smatch sMO) {
	return replacementString;
}
const std::string MustSubMoldGlom::_get_Identifier(const std::smatch sMO) {
	return sMO[1].str();
}
const std::string MustSubMoldGlom::_get_Id_Pattern(const std::smatch sMO) {
	return sMO[0].str();
}

MustSubMoldGlom::MustSubMoldGlom(std::string targetText) : GlomBase(SubMoldTagPattern,targetText) {}

//		Begin OptionalGlom:

const std::string OptionalGlom::_adjust_Replacement_String(const std::string replacementString, const std::smatch sMO) {
	return replacementString;
}
const std::string OptionalGlom::_get_Identifier(const std::smatch sMO) {
	return sMO[1].str();
}
const std::string OptionalGlom::_get_Id_Pattern(const std::smatch sMO) {
	return sMO[0].str();
}

OptionalGlom::OptionalGlom(std::string targetText) :  GlomBase(OptionalTagPattern,targetText) {}

//		Begin RequiredGlom:

const std::string OptionalGlom::_adjust_Replacement_String(const std::string replacementString, const std::smatch sMO) {
	return replacementString;
}
const std::string OptionalGlom::_get_Identifier(const std::smatch sMO) {
	return sMO[1].str();
}
const std::string OptionalGlom::_get_Id_Pattern(const std::smatch sMO) {
	return sMO[0].str();
}

RequiredGlom::RequiredGlom(std::string targetText) : GlomBase(RequiredTagPattern,targetText) {}

// Local Internals only needed in this file:

// The following three local functions are to allow for an effective array of classes:

MustSubMoldGlom*	createMustSubMoldGlomObject(std::string targetText) {
	MustSubMoldGlom::MustSubMoldGlom* b = new MustSubMoldGlom::MustSubMoldGlom(targetText);
	return b; 
}
OptionalGlom*		createOptionalGlomObject() {
	OptionalGlom::OptionalGlom* b = new OptionalGlom::OptionalGlom(targetText);
	return b; 
}
RequiredGlom*		createRequiredGlomObject() {
	RequiredGlom::RequiredGlom* b = new RequiredGlom::RequiredGlom(targetText);
	return b; 
}

// Said effective array of classes:
const std::vector<GlomBase* (*)()> FactoryVector =
	{	createRequiredGlomObject,
		createOptionalGlomObject,
		createMustSubMoldGlomObject
	};

GlomBase(const std::string& tagPattern,const std::string& targetText) :
	smo(findFirst(targetText)),
	idpattern(getIdPattern()),
	identifier(getIdentifier())

void GlomBase::replaceFoundIdentifier(std::string targetText, std::string replacementString) {
	int id
	std::string		identifier	= getIdentifier;
	size_t			idsize		= identifier.size();
	size_t			position	= targetText.find(identifier);

	targetText.replace(position, idsize, replacementString);
}

static const std::vector<std::regex> InclusionPatterns = {
	std::regex(Resin::OptionalTagPattern),
	std::regex(Resin::RequiredTagPattern),
	std::regex(Resin::SubMoldTagPattern)
};

std::string Resin::glomMoldList( const std::string& moldString, const Json::Value& jvoR) {
	std::string		entire;

	for (Json::Value::const_iterator cilo = jvoR.begin() ; cilo != jvoR.end() ; cilo++ ) {
		entire += glomMoldTree(moldString,cilo);
	}
	return entire;
}

std::string Resin::glomMoldTree( const std::string& moldString, const Json::Value& jvoR) {
	std::string					fieldkey;
	std::string					product;
	std::string					replacement;
	std::string					submoldstring;
	std::unique_ptr<GlomBase>	gbsp;

	// TBD xc
	// Need to figure out case for list of items
	product=moldString;
	for(std::regex patto : GlomSets::PatternClasses) {
		while ( patto.findFirst(product) )
			fieldkey			= patto.getKey();
			if ( jvoR.isList(fieldkey) ) {
							submoldstring = patto.loadSubMold(fieldkey)
							replacement = glomMoldList(submoldstring,jvoR[fieldkey]);
			} else {
				if ( patto.subMoldFound(fieldkey) )
							submoldstring = patto.loadSubMold(fieldkey)
					if jvoR.has_key(fieldkey)
							replacement = glomMoldTree(submoldstring,jvoR[fieldkey]);
					else 	replacement = glomMoldTree(submoldstring,jvoR);
				} else		replacement = jvoR[fieldkey].asString();
			}
			patto.replaceFoundIdentifier(product, replacement);
		}
	}
	return product;
}

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of glomsets.cpp
