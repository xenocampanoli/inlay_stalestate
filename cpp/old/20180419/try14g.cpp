// try14g.cpp
//
#include <iostream>
#include <string>
#include <regex>

int main()
{
const char *textexample =
  "This text is pretty long, but will be "
  "concatenated into just a single string. "
  "The disadvantage is that you have to quote "
  "each part, and newlines must be literal as "
  "usual.";
	const std::string re_prefix = "(^|\r?\n)";
	const std::string re_suffix = "(?=\r?\n|$)";
	//std::string s("ccc\r\naaa\r\ngggg");
	//std::regex ee(R"((^|\r?\n)(?:aaa|bbb)(?=\r?\n|$))");
	//std::string newtext = std::regex_replace( s, ee, "$1" );
	//std::cout << newtext << std::endl;
	const std::string mold =
R"MOLD(
@@@Name@@@
@@@Phone@@@
@@@Email@@@
^^^FictionalFileWeWillIgnoreHer^^^
)MOLD";
	std::smatch smo;
	std::vector<std::regex> InclusionTypes = {
		std::regex("@@@([^@]*)@@@"),
		std::regex("\\^\\^\\^([^^]*)\\^\\^\\^")
//		std::regex("@@@([^@]*)@@@")
	};


	int n = 0;
	std::string target = mold;
	for(std::regex e : InclusionTypes) {
		while ( std::regex_search( target, smo, e ) ) {
			std::cout << "smo size = " << smo.size() << std::endl;
			std::cout << "first key:  " << smo[1].str() << std::endl;
			//std::cout << "suffix of string = " << smo.suffix() << std::endl;
			//s = smo.suffix();
			std::string identifier = smo[0].str();
			std::string replacement = "====" + smo[1].str() + "====";
			size_t idsize = identifier.size();
			std::cout << "identifier is:  " << identifier << " with size " << idsize << "." << std::endl;
			target.replace(target.find(identifier), idsize, replacement);
			std::cout << "target is now:  " << target << std::endl;
			std::cout << "End regex loop pass " << ++n << "." << std::endl;
			if ( n > 9 ) break;
		}
	}
	std::cout << "trace result string:  " << target << std::endl;

	return 0;
}
