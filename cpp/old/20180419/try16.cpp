// try14h.cpp
//
#include <iostream>
#include <string>
#include <regex>

int main() {
	std::string mold = "1234\n";
	std::string entire = "";
	std::string item;

	int i;

	for (i=0;  i<16; ++i) {
		item = mold;
		entire += item;
	}
	std::cout << "trace entire:\n" << entire << "\nThat's the end." << std::endl;
}
// end of try14h.cpp
