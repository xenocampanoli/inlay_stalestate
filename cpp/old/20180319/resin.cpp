// resin.cpp
//345678901234567890123456789012345678901234567890123456789012345678901234567890

#include "resin.hpp"

// Begin:  All includes here should be specific only to this file:
#include <exception>
#include <sys/stat.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

// End:  All includes here should be specific only to this file:

const Json::Value Resin::ParseSap(std::string fnString) {

std::cout << "trace 0 ParseSap" << std::endl;
    const char *cfn = fnString.c_str();
    struct stat statbuffer;
    if ( stat(cfn,&statbuffer) != 0 ) {
        char pwd_b[128];
        char fpath_b[256];
        getcwd(pwd_b,128);
        sprintf(fpath_b,"%s/%s",pwd_b,(char *)cfn);
        if ( stat(fpath_b,&statbuffer) != 0 ) {
            char estr1[328];
            sprintf(estr1,"failed to find file path at either %s or %s.",cfn,fpath_b);
            throw std::invalid_argument(estr1);
        }
        fnString = fpath_b;
    }
    std::ifstream input_buffer(fnString.c_str());
    std::string input_text(( std::istreambuf_iterator<char>(input_buffer)),
                             std::istreambuf_iterator<char>());
std::cout << "trace 5 ParseSap" << std::endl;
//    std::cout << "trace json text:  " << input_text << std::endl;
    Json::Value root;
    Json::Reader reader;
    if ( reader.parse( input_text, root ) ) {
std::cout << "trace 6a ParseSap" << std::endl;
    //    for (auto const& id : root.getMemberNames()) {
     //       std::cout << id << std::endl;
      //  }
        std::cout << "Size: " << root.size() << std::endl;
        std::cout << "Contains IdentificationResin? " << root.isMember("IdentificationResin") << std::endl;
        return root;
    } else {
std::cout << "trace 6b ParseSap" << std::endl;
        std::cout << reader.getFormattedErrorMessages();
        exit(1);
    }
    std::stringstream estr2;
    estr2 << "Failure in attempt to parse json from " << fnString << "." << std::endl;
    throw std::runtime_error(estr2.str());
}


void Resin::DumpBoleSap() {
    if ( BoleSap.size() <= 0 ) {
        std::cout << "Non-positive size of BoleSap seen:  " << BoleSap.size() << "." << std::endl;
        return;
    }
    std::cout << BoleSap["IdentificationResin"] << "size of BoleSap seen." << std::endl;
}

void Resin::DumpSoilSap() {
}

Resin::Resin(std::string fnString1,std::string fnString2) : BoleSap(Resin::ParseSap(fnString1)), SoilSap(Resin::ParseSap(fnString2)) {
//    ValidateSoilSap();
 //   ValidateBoleSap(); 
}

/*
Resin::Resin(const Resin &resinO) {
}

Resin::~Resin() {
}
*/

void Resin::ValidateBoleSap() {
    if ( BoleSap.size() <= 0 )                                  throw std::runtime_error("No content seen in BoleSap data.");
    //if ( ! BoleSap.isMember("IdentificationResin") )            throw std::runtime_error("IdentificationResin not found as top member key.");
    //if ( ! BoleSap["IdentificationResin"].isMember("Name") )    throw std::runtime_error("Name not found as member major member key.");
}

void Resin::ValidateSoilSap() {
    if ( SoilSap.size() <= 0 )                                          throw std::runtime_error("No content seen in SoilSap data.");
    //if ( ! SoilSap.isMember("SupportResin") )                           throw std::runtime_error("SupportResin not found as top member key.");
    //if ( ! SoilSap["SupportResin"].isMember("DefaultBackgroundColor") ) throw std::runtime_error("DefaultBackgroundColor not found as major member key.");
}

/*
// End of resin.cpp

// After End Notes:

#include <json/value.h>
#include <fstream>

std::ifstream people_file("people.json", std::ifstream::binary);
people_file >> people;

cout<<people; //This will print the entire json object.

//The following lines will let you access the indexed objects.
cout<<people["Anna"]; //Prints the value for "Anna"
cout<<people["ben"]; //Prints the value for "Ben"
cout<<people["Anna"]["profession"]; //Prints the value corresponding to "profession" in the json for "Anna"

cout<<people["profession"]; //NULL! There is no element with key "profession". Hence a new empty element will be created.

*/

//345678901234567890123456789012345678901234567890123456789012345678901234567890
// End of resin.cpp
