/* batch.hpp
	Manages the sets of documents to be rendered, taking
	parameters specified from the command line.
 */
#pragma once

#include "batch.hpp"
#include <jsoncpp/json/value.h>
#include <map>

class Batch {

    public:

	// --------------------------------------------------

	Batch::driveConfiguredCombinationThreads();

	void setBoleSapExclude(conststd::string nameCSV);
	void setBoleSapInclude(conststd::string nameCSV);
	void setGenerateDOCXs(conststd::bool generateEm);
	void setGeneratePDFs(conststd::bool generateEm);
	void setMoldsExclude(conststd::string nameCSV);
	void setMoldsInclude(conststd::string nameCSV);
	void setReport(conststd::bool reportIt);
	void setSoilSapExclude(conststd::string nameCSV);
	void setSoilSapInclude(conststd::string nameCSV);

	private:

	std::vector<std::string> BoleSapIncludeList;
	std::vector<std::string> MoldIncludeList;
	std::vector<std::string> SoilSapIncludeList;
	bool GenerateDOCXs;
	bool GeneratePDFs;
	bool ReportIt;

	// --------------------------------------------------

	std::string Batch::cookAmber(std::string moldFileId=Batch::TopFileId);

};

// End of batch.hpp 
