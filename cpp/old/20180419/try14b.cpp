#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::regex exp("(\\b\\S*\\b)");
    std::smatch res;
    std::string str = "first second third forth";
    std::regex exp2("(@@@([^@]*)@@@");
	std::string s =
R"MOLD(
@@@Name@@@@
@@@Phone@@@
@@@Email@@@
^^^FictionalFileWeWillIgnoreHer^^^
)MOLD";

    while (std::regex_search(str, res, exp)) {
        std::cout << res[0] << std::endl;
        str = res.suffix();
    }
    while (std::regex_search(s, res, exp2)) {
        std::cout << res[0] << std::endl;
        str = res.suffix();
    }
}   
