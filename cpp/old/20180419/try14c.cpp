// match_results::begin/end
// - using smatch, a standard alias of match_results<string::iterator>
#include <iostream>
#include <string>
#include <regex>

int main()
{
	const std::string prefix_patt = "(^|\r?\n)";
	const std::string suffix_patt = "(?=\r?\n|$)";
	//std::string s("ccc\r\naaa\r\ngggg");
	//std::regex ee(R"((^|\r?\n)(?:aaa|bbb)(?=\r?\n|$))");
	//std::string newtext = std::regex_replace( s, ee, "$1" );
	//std::cout << newtext << std::endl;
	std::string mold =
R"MOLD(
@@@Name@@@@
@@@Phone@@@
@@@Email@@@
^^^FictionalFileWeWillIgnoreHer^^^
)MOLD";
	std::smatch smo;
/*
	std::vector<std::regex> InclusionTypes = {
		std::regex("@@@([^@]*)@@@"),
		std::regex("\\^\\^\\^([^^]*)\\^\\^\\^")
//		std::regex("@@@([^@]*)@@@")
	};
 */
	std::vector<std::string> InclusionPatterns = {
		"@@@([^@]*)@@@",
		"\\^\\^\\^([^^]*)\\^\\^\\^"
	};


	int n = 0;
	std::string target = mold;
	std::string s;
	for(std::string i_patt : InclusionPatterns) {
		std::string strbuffer = prefix_patt + i_patt + suffix_patt;
		std::regex e = std::regex(strbuffer);
		s = mold;
/*
		auto b = std::regex_search( s, smo, e );
		std::cout << "Begin pass for regex number " << ++n << ", " << b << "." << std::endl;
		std::cout << "trace dump mold:  " << s << std::endl;
*/
		while ( s.size() > 0 && std::regex_search( s, smo, e ) ) {
			std::cout << "smo size = " << smo.size() << std::endl;
			std::cout << "first key:  " << smo[1].str() << std::endl;
			//std::cout << "suffix of string = " << smo.suffix() << std::endl;
			s = smo.suffix();
			//std::cout << "string to search now:  " << s << std::endl;
		}
		std::cout << "End pass for regex number " << n << "." << std::endl;
	}
	std::cout << "trace result string:  " << s << std::endl;

	return 0;
}
