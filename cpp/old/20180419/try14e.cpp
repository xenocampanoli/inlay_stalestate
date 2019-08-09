// try14e.cpp
//
#include <iostream>
#include <string>
#include <regex>

int main()
{
	const std::string re_prefix = "(^|\r?\n)";
	const std::string re_suffix = "(?=\r?\n|$)";
	//std::string s("ccc\r\naaa\r\ngggg");
	//std::regex ee(R"((^|\r?\n)(?:aaa|bbb)(?=\r?\n|$))");
	//std::string newtext = std::regex_replace( s, ee, "$1" );
	//std::cout << newtext << std::endl;
	std::string rstr1 = "@@@([^@]*)@@@";
	std::string rstr2 = "\\^\\^\\^([^^]*)\\^\\^\\^";
	const std::string mold =
R"MOLD(
@@@Name@@@@
@@@Phone@@@
@@@Email@@@
^^^FictionalFileWeWillIgnoreHer^^^
)MOLD";
	std::smatch smo;
	std::vector<std::regex> InclusionTypes = {
		std::regex(re_prefix + rstr1 + re_suffix),
		std::regex(rstr2)
	};


	int n = 0;
	std::string target = mold;
	std::string s = mold;
	std::string replacement;
	for(std::regex e : InclusionTypes) {
		//auto b = std::regex_search( s, smo, e );
		//std::cout << "Begin pass for regex number " << ++n << ", " << b << "." << std::endl;
		//while ( std::regex_search( s, smo, e ) && smo.str().size() > 0 ) {
		while ( auto result = std::regex_search( s, smo, e ) ) {
			std::cout << "trace 3 dump s:  " << s << std::endl;
			std::cout << "trace 3a dump smo[0]:  " << smo[0].str() << std::endl;
			std::cout << "trace 3a dump smo[1]:  " << smo[1].str() << std::endl;
			std::cout << "trace 3a dump smo[2]:  " << smo[2].str() << std::endl;
			std::cout << "smo size = " << smo.size() << std::endl;
			replacement = "\n\n===\n\n" + smo[2].str() + "\n\n===\n\n";
			std::cout << "replacement value:  " << replacement << std::endl;
			s = std::regex_replace(s, std::regex(smo[0].str()), replacement);
			std::cout << "trace 7 dump s:  " << s << std::endl;
			//std::cout << "suffix of string = " << smo.suffix() << std::endl;
			//s = smo.suffix();
			//std::cout << "string to search now:  " << s << std::endl;
			break;
		}
		std::cout << "End pass for regex number " << n << "." << std::endl;
	}
	std::cout << "trace result string:  " << s << std::endl;

	return 0;
}
