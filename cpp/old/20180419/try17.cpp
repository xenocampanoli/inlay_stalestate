// try17.cpp
//
#include <iostream>
#include <string>
#include <vector>

void echoOne() {
	std::cout << "trace 1" << std::endl;
}

void echoTwo() {
	std::cout << "trace 2" << std::endl;
}

void echoThree() {
	std::cout << "trace 3" << std::endl;
}

int main() {
	std::vector<void (*)()> funkies = {echoOne,echoTwo,echoThree};

	for(auto && fn : funkies)
                fn();
	std::cout << "trace end." << std::endl;
}
// end of try17.cpp
