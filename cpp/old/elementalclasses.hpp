
// Elemental Classes

class Education {

	private:

	public:
	Education(const Json::Value jstoR);
	Education(const Education& educationO);

	std::string GetInstitution();
	std::string GetHonor();
	unsigned short GetYear();
};

class Experience {

	private:

	public:
	Experience(const Json::Value jstoR);
	Experience(const Experience& experienceO);

	std::string GetTitle();
	std::string GetOrganization();
	std::time_t GetBeginDate();
	std::time_t GetEndDate();
	std::string GetSummary();
	std::string GetAnecdoteList();
	std::vector<std::string> GetAnecdotesBySkill(std::vector<std::string> skillKeys);
	std::map<std::string, std::vector<std::string> > topicAnecdotes;
};

class SampleWork {

	private:

	public:
	SampleWork(const Json::Value jstoR);
	SampleWork(const SampleWork& sampleWorkO);

	std::string GetTypeOfSample();
	std::string GetAddress();
	std::string GetIdea();
	std::string GetDescription();
	std::time_t GetBeginDate();
	std::time_t GetLastDate();
	std::vector<std::string> GetSamplesBySkill(std::vector<std::string> skillKeys);
	std::map<std::string, std::vector<std::string> > topicWorkSamples;
};

// End Elemental Classes

    const std::vector<Experience> ExperienceList;
    const std::vector<Education> EducationList;
    const std::vector<SampleWork> SampleWorkList;

    const std::vector<Education> LoadEducation();
    const std::vector<Experience> LoadExperience();
    const std::vector<SampleWork> LoadSampleWork();

	// List Dumps:
    void DumpEducation(int elementIndex);
    void DumpExperience(int elementIndex);
    void DumpSampleWork(int elementIndex);

	// List Gets:
	std::string GetEducationValue(int elementIndex, std::string itemKey);
	std::string GetExperienceValue(int elementIndex, std::string itemKey);
	std::string GetSampleWorkValue(int elementIndex, std::string itemKey);

