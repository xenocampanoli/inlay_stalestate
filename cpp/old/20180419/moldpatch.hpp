// resin.hpp

#include "env.hpp"

#include <ctime>
#include <cstring>
#include <string>
#include <jsoncpp/json/value.h>
#include <map>
#include <vector>

class Resin {

	public:	// public structs needed in private area:

	struct ListSubsets {
		int index;
		std::map< std::string, std::vector<ListSubsets *> > listnode;
	};

    private:

	ListSubsets *ResinSubsets;

	// ---------------------------------------------------------------------------------------------

	std::string GetMonthlyString(std::string itemKey);
	std::string GetUniversalString(std::string itemKey);

	ListSubsets *InitSubsets(const Json::Value &jvoR, const Options resinOps);

	void DumpSap(const Json::Value& jvoR, std::string itemKey);
	std::string GetValue(const Json::Value& jvoR, std::string itemKey);
	const Json::Value ParseSap(const std::string SapKey, std::string fnString);
	std::string secreteItems(const Json::Value& jvoR, const std::string& moldString, const std::string& sapKey, const std::string& subListSapKey, const std::string& subListMold);
	std::vector<int> selectExperienceSubsets(boleSap[ExperienceId],resinOps);
	std::vector<std::vector<int>> selectExperienceExamples(boleSap[ExperienceId],resinOps);
	std::vector<int> selectSampleWorkSubsets(bolSap[SampleWorkId],resinOps);
	bool ValidateSap(const Json::Value& jvoR, std::vector<std::string> &keySet, bool quietFailure);

    public:

	// Initialization only keys:

	static const std::string BoleSapKey;
	static const std::string SoilSapKey;

	// Established Identifiers, public for reference by user objeccts:

	static const std::string TopFileId;

	static const std::string PrefixPattern;
	static const std::string SuffixPattern;

	static const std::string OptionalTagPattern;
	static const std::string RequiredTagPattern;
	static const std::string SubMoldTagPattern;

	static const std::vector<std::string> InclusionPatterns;

	// ---------------------------------------------------------------------------------------------

	// Sap Dumps:
    void DumpBoleSap(std::string itemKey);
    void DumpSoilSap(std::string itemKey);

	std::string Resin::glomMoldTree( const std::string& moldString, const Json::Value& jvoR) {

	Resin(std::string fnString1, std::string fnString2, const Options resinOps);
    Resin(const Resin &resinO);

	// Validate Saps
    bool ValidateBoleSap(std::vector<std::string> &keySet, bool quietFailure);
    bool ValidateSoilSap(std::vector<std::string> &keySet, bool quietFailure);

};

// End of resin.hpp
