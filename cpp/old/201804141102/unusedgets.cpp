
Json::Value Resin::GetEducationObject(int itemIndex) {
	return BoleSap[EducationId][itemIndex];
}

std::vector<int> Resin::GetEducationObjectIndices() {
	return BoleSap[EducationId].size();
}

Json::Value Resin::GetExperienceObject(int itemIndex) {
	return BoleSap[ExperienceId][itemIndex];
}

std::vector<int> Resin::GetExperienceObjectIndices(std::vector<std::string> &experienceAnecdoteTypeIds) {
	return BoleSap[ExperienceId].size();
}

Json::Value Resin::GetSampleWorkObject(int itemIndex) {
	return BoleSap[SampleWorkId][itemIndex];
}

std::vector<int> Resin::GetSampleWorkObjectIndices(std::vector<std::string> &sampleWorkTypeIds) {
	return BoleSap[SampleWorkId].size();
}

std::string Resin::GetIdentityString(std::string itemKey) {
	std::string buffer = Resin::GetValue(BoleSap,itemKey);
	return buffer;
}

const std::vector<std::vector <int>> InitEducationUse(const Json::Value boleSap, const Options resinOps) {
	std::set<int> skills_sought_indices;
	/* Tasks:
	1.	Get total sample work items, and maximal briefs over all items.
	2.	Create the array.
	3.	Loop through the samples, including those designated by options, and assigning order to briefs for each.
	4.	return the array.
	 */
	std::vector<std::vector<int>> lil;
	return lil;
}

const std::vector<std::vector <int>> InitExperienceUse(const Json::Value boleSap, const Options resinOps) {
	/* Tasks:
	1.	Get total experience items, and maximal briefs over all items.
	2.	Create the array.
	3.	Loop through the experiences, including those designated by options, and assigning order to briefs for each.
	4.	return the array.
	 */
	
	std::vector<std::vector<int>> lil;
	return lil;
}

const std::vector<std::vector <int>> InitExperienceBriefs(const Json::Value boleSap, const std::vector<int> experienceIndices, const Options resinOps) {
	std::vector<std::vector<int>> lil;
	return lil;
}
/*
	const std::vector<std::vector <int>> InitEducationUse(const Json::Value boleSap, const Options resinOps);
	const std::vector<std::vector <int>> InitExperienceUse(const Json::Value boleSap, const Options resinOps);
	const std::vector<std::vector <int>> InitExperienceBriefs(const Json::Value boleSap, const std::vector<int> experienceIndices, const Options resinOps);
	const std::vector<std::vector <int>> InitSampleWorkUse(const Json::Value boleSap, const Options resinOps);
 */

const std::vector<std::vector <int>> InitSampleWorkUse(const Json::Value boleSap, const Options resinOps) {
	/* Tasks:
	1.	Get total sample work items, and maximal briefs over all items.
	2.	Create the array.
	3.	Loop through the samples, including those designated by options, and assigning order to briefs for each.
	4.	return the array.
	 */
	std::vector<std::vector<int>> lil;
	return lil;
}

