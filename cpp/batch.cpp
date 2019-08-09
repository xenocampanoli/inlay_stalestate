// batch.cpp

#include <regex>
#include <iostream>

#include "subject.hpp"
#include "templates.hpp"

const std::string TopFileId		= "TopFile";
const std::string EducationId	= "Education";
const std::string ExperienceId	= "Experience";
const std::string SampleWorkId	= "SampleWork";

const std::string ExampleId		= "Examples";

std::string Batch::cookAmber(std::string moldFileId=Batch::TopFileId) {
	// For each thread of processing.
}

Batch::driveConfiguredCombinationThreads() {
	// For submitting and managing all the batches being cooked.
}

Batch::Batch() {
};

void Batch::setBoleSapExclude(conststd::string nameCSV) {}
void Batch::setBoleSapInclude(conststd::string nameCSV) {}
void Batch::setGenerateDOCXs(conststd::bool generateEm) {}
void Batch::setGeneratePDFs(conststd::bool generateEm) {}
void Batch::setMoldsExclude(conststd::string nameCSV) {}
void Batch::setMoldsInclude(conststd::string nameCSV) {}
void Batch::setReport(conststd::bool reportIt) {}
void Batch::setSoilSapExclude(conststd::string nameCSV) {}
void Batch::setSoilSapInclude(conststd::string nameCSV) {}

// End of batch.cpp
