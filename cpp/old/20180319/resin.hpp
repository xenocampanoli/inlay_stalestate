// mold.hpp

#include <cstring>
#include <string>
#include <jsoncpp/json/json.h>
//#include <jsoncpp/json/value.h>

class Resin {

    private:

    const Json::Value BoleSap;
    const Json::Value SoilSap;

    const Json::Value ParseSap(std::string fnString);

    void ValidateBoleSap();
    void ValidateSoilSap();

    public:

    void DumpBoleSap();
    void DumpSoilSap();

    Resin(std::string fnString1,std::string fnString2);

/*
    Resin(const Resin &resinO);

    ~Resin();
    */
};

// End of resin.hpp
