
#include <iostream>
#include <string>

int main() {
	std::string s = R"EOS(Now is the time
for all good strings
to go
on
and on
and on...
)EOS";
	std::cout << "trace:  " << s << std::endl;
}
