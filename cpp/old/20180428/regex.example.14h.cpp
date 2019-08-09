// try14h.cpp
//
#include <iostream>
#include <string>
#include <regex>

int main()
{
	const std::string mold =
R"MOLD(
@@@Name@@@
@@@Phone@@@
@@@Email@@@
^^^FictionalFileWeWillIgnoreHer^^^
)MOLD";
	std::smatch smo;
	std::vector<std::string> InclusionStringPatterns = {
		"\\^\\^\\^([^^]*)\\^\\^\\^",
		"@@@([^@]*)@@@"
	};


	int n = 0;
	std::string target = mold;
	for(std::string restr : InclusionStringPatterns) {
		std::regex e = std::regex(restr);
		while ( std::regex_search( target, smo, e ) ) {
			std::cout << "smo size = " << smo.size() << std::endl;
			std::cout << "first key:  " << smo[1].str() << std::endl;
			std::string identifier = smo[0].str();
			std::string replacement = "\n\n====\n\n" + smo[1].str() + "\n\n====\n\n";
			size_t idsize = identifier.size();
			std::cout << "identifier is:  " << identifier << " with size " << idsize << "." << std::endl;
			size_t position = target.find(identifier);
			target.replace(position, idsize, replacement);
			std::cout << "target is now:  " << target << std::endl;
			std::cout << "End regex loop pass " << ++n << "." << std::endl;
			if ( n > 9 ) break;
		}
	}
	std::cout << "trace result string:  " << target << std::endl;

	return 0;
}
// end of try14h.cpp
