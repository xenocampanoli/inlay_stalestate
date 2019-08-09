// oven.hpp

class Oven {

	private:

    const Json::Value RequirementsTree;
    const std::vector<string> MoldFilenameList;

	const Json::Value DivineRequirements(Options& opO, Resin &resinO);

	void bakeAmber(std::string fnString);

    public:

	int executeGenerators();

	Json::Value getRequirementsTree();

    Oven(Options& opO, Resin& resinO);
    Oven(const Oven &ovenO);
}

// End of oven.hpp 
