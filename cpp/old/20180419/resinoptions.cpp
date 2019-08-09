// resinoptions.cpp

Resin::initSubsets(const Json::Value& jvoR, const Options resinOps, Resin::ReportingIndices rioR) {
	set<string> skillset = resinOps.getSkillSetFromArgString();
	vector<int> tmplist;
	for (Json::Value::ArrayIndex i = 0; i < jvoR.size(); i++) {
		if ( ! resinOps.hasMinMonths(jvoR[i]) )				coninue;
		if ( ! resinOps.inYearsRange(jvoR[i]) )				coninue;
		if ( ! resinOps.inIndexRange(jvoR[i]) )				coninue;
		if ( ! resinOps.treeHasTopic(jvoR[i],skillset ) )	coninue;
		rioR.Experience.push_back(i);
		rioR.Examples.push_back(vector<int>());
		tmplist = {};
		for (std::string skill:  skillset) {
			for (Json::Value::ArrayIndex j = 0; j < jvoR[i][ExampleId].size(); j++) {
				if ( resinOps.hasSkill(jvoR[i][ExampleId][j] and notYetIndexed(rioR.Examples[i],j) ) {
					rioR.Examples[i].push_back(j);
				} else {
					tmplist.push_back(j);
				} 
			}
		}
		if ( resinOps.includeExampleRemainders(resinOps) )
			// append tmplist to examples, thus preserving original order.
	}
}


Options::getSkillSetFromArgString(const Options resinOps) {
} 
Options::stintHasMinMonths(const Options resinOps, const Json::Value& jvoR) {
} 
Options::inExperienceYearsRange(const Options resinOps, const Json::Value& jvoR) {
} 
Options::inJobIndexRange(const Options resinOps, const Json::Value& jvoR) {
} 
Options::neededExample(const Options resinOps, const Json::Value& jvoR) {
} 
Options::hasSkill(const Json::Value& jvoR) {
} 
Options::notYetIndexed(const Options resinOps, const Json::Value& jvoR) {
} 
Options::includeExampleRemainders(const Options resinOps, const Json::Value& jvoR) {
} 

// End of resinoptions.cpp
