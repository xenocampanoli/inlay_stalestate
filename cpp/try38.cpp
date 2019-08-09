#include <ctype.h>
#include <locale>
#include <regex>
#include <set>
#include <string>
#include <vector>

#include "env.hpp"

std::regex insRx(const std::string strArg) {
	std::string bs = ".*" + strArg + ".*";
	std::cout << "trace bs:  " << bs << "." << std::endl;
	return std::regex(bs);
}

bool isCapitalized(std::string& sArg) {
	int i = 0;
	for(auto c : sArg) {
		if (i == 0 && ! std::isalpha(c))	return false;
		if (i == 0 && std::islower(c))		return false;
		if (i != 0 && std::isupper(c))		return false;
		++i;
	}
	return true;
}

int main() {
	
	std::locale loc1("C");
	//std::vector<std::string> sv = {"One","two","3","Quatre","6ank"};
	std::set<std::string> ss = {"One","two","3","Quatre","6ank"};
	//std::set<std::string> str = {"John", "Kelly", "Amanda", "Kim"};
	//for(auto s : sv) {
	for(auto s : ss) {
		if (isCapitalized(s)) 
			std::cout << "String is Capitalized:  " << s << "." << std::endl;
		else
			std::cout << "String NOT Capitalized:  " << s << "." << std::endl;
	}
	std::cout << "trace 5" << std::endl;
	auto mit = std::find(ss.begin(),ss.end(),"One");
	if ( mit == ss.end() ) 
		std::cout << "Nope." << std::endl;
	else
		std::cout << "Yep." << std::endl;
	mit = std::find(ss.begin(),ss.end(),"Uno");
	if ( mit == ss.end() ) 
		std::cout << "Nope." << std::endl;
	else
		std::cout << "Yep." << std::endl;
}
