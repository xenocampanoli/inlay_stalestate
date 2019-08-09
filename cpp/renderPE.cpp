/* renderPE.cpp
12345678901234567890123456789012345678901234567890123456789012345678901234567890
 */

#include <sstream>
#include <fstream>
#include <streambuf>
#include <iostream>
#include <unistd.h>

#include "batch.hpp"
#include "env.hpp"
#include "experienceseer.hpp"

std::map<std::string,std::string> topops;

void printError(std::string eMsg) {
	std::cout << "ERROR:  " << eMsg << std::endl;
}

const char *GETOPTS = ":b:B:dDe:E:f:F:hj:J:lLm:M:pPrRs:S:";

void printUsage() {
	std::cout <<
R"EOUS(USAGE:  ./resinate [options]
Where options include:
	-b l	Include only list of bole sap configurations by extensionless filename.  Default is process only bole/default.json.
	-B l	Exclude only list of bole sap configurations by extensionless filename.  Default is process only bole/default.json.
	-d	 	Generate docx output.
	-e n	Include only n years back of work experience, ignoring confugred numbers in Sap configurations.
	-E n	Exclude first n years of work experience, ignoring confugred numbers in Sap configurations.
	-f l	Filter/Order Experience examples and Sample Work by the skills id list provided with this option.
			Then list any items not matching these skills at the end.  Default is use all in original Json order.
	-F l	Filter/Order Experience examples and Sample Work by the skills id list provided with this option.
			Leave off any items not matching these skills.  Default is use all in original Json order.
	-h		Print this usage statement.
	-j n	Include only most recent n jobs of work experience, ignoring confugred numbers in Sap configurations.
	-J n	Exclude earliest n jobs of work experience, ignoring confugred numbers in Sap configurations.
	-l		List available configurations and molds.
	-L		List existing output.
	-m l	Include only list of mold/templates by extensionless filename.  Default is process all available molds.
	-M l	Exclude only list of mold/templates by extensionless filename.  Default is process all available molds.
	-o		Omit Experience when no anecdotes have pertinent skill typeids.
	-O		Don't omit unrelated experience items.
	-p	 	Generate pdf output.
	-r	 	Provide a run report, requirements, products, etc.
	-R	 	Leave out run report.
	-s l	Include only list of soil sap configurations by extensionless filename.  Default is process only bole/default.json.
	-S l	Exclude only list of soil sap configurations by extensionless filename.  Default is process only bole/default.json.
)EOUS";
}

void usageErrorMultiOpUniqueOp(int argc,char opChar) {
    std::stringstream b;
	b << "Unique use option '" << opChar << "' was specified, but more than one (" << argc << ") options were specified.";
	printError(b.str());
	printUsage();
	exit(9);
}

bool setOpOs(DeepTime& dtO, SeepFilter& sfO, char c, char *optarg) ) {
	switch(c) {
		case 'B':
			dtO.setBoleSapExclude(optarg);
			return true;
		case 'b':
			dtO.setBoleSapInclude(optarg);
			return true;
		case 'D':
			dtO.setGenerateDocXs(false);
			return true;
		case 'd':
			dtO.setGenerateDocXs(true);
			return true;
		case 'E':
			sfO.setEarlyYearsToExclude(optarg);
			return true;
		case 'e':
			sfO.setYearsBackToInclude(optarg);
			return true;
		case 'F':
			sfO.setSkillFilterSet(optarg);
			sfO.setExcludeExperienceRemainder();
			return true;
		case 'f':
			sfO.setSkillFilterSet(optarg);
			sfO.setIncludeExperienceRemainder();
			return true;
		case 'J':
			sfO.setJobsExclude(optarg);
			return true;
		case 'j':
			sfO.setJobsInclude(optarg);
			return true;
		case 'M':
			dtO.setMoldsExclude(optarg);
			return true;
		case 'm':
			dtO.setMoldsInclude(optarg);
			return true;
		case 'O':
			sfO.setIncludeUnrelatedExperience();
			return true;
		case 'o':
			sfO.setOmitUnrelatedExperience();
			return true;
		case 'P':
			dtO.setGeneratePDFs(false);
			return true;
		case 'p':
			dtO.setGeneratePDFs(true);
			return true;
		case 'R':
			dtO.setReport(false);
			return true;
		case 'r':
			dtO.setReport(true);
			return true;
		case 'S':
			dtO.setSoilSapExclude(optarg);
			return true;
		case 's':
			dtO.setSoilSapInclude(optarg);
			return true;
		default:
			return false;
	}
}

int main(int argc, char **argv) {
    
	int c=0;

	DeepTime dto;
	SeepFilter sfo;

	while ((c = getopt(argc, argv, GETOPTS)) != -1) {
		if ( setOpOs(dto,sfo,c,optarg) ) contiue;
		switch(c) {
			case 'h':
				if ( argc != 1 ) usageErrorMultiOpUniqueOp(argc,c);
				printUsage();
				return 0;
			default:
				std::cout << "ERROR:  Invalid option specified on the command line.";
				printUsage();
				return 0;
		}
	}

	// Main processing occurs of no command line option 

	std::vector<Resin> rarray;

	std::cout << "Main Processing TBD for now." << std::endl;
}
//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of renderPE.cpp
