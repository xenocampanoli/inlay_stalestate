#include <regex>
#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::string p=".*Boeing.*";
	std::string s="Boeing";
	if (std::regex_match(s,std::regex(p))) std::cout << "trace try31a:  "<<s<<std::endl;
	s=" Boeing ";
	if (std::regex_match(s,std::regex(p))) std::cout << "trace try31b:  "<<s<<std::endl;
}
