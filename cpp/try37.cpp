#include <regex>
#include <string>

#include "env.hpp"

std::regex insRx(const std::string strArg) {
	std::string bs = ".*" + strArg + ".*";
	std::cout << "trace bs:  " << bs << "." << std::endl;
	return std::regex(bs);
}

int main() {
	std::string sb = "onetwothree\nfourfivesix\nseveneightnine\n";
	//std::string sb = "onetwothreefourfivesixseveneightnine\n";
	std::regex rb = std::regex(".*fourfivesix.*");
	if (std::regex_search(sb,rb))
		std::cout << "PASS" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	std::regex rb2 = insRx("fourfivesix");
	if (std::regex_search(sb,rb2))
		std::cout << "PASS" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	if (std::regex_search(sb,insRx("fourfivesix")))
		std::cout << "PASS" << std::endl;
	else
		std::cout << "FAIL" << std::endl;
}
