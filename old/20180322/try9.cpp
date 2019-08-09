#include <string>
#include <iostream>
#include <regex>

using namespace std;

int main(int argc, char * argv[]) {
    string test = "test replacing \"these characters\"";
    regex reg("[^\\w]+");
    test = regex_replace(test, reg, "_");
    cout << test << endl;
    test = "test replacing @@@this@@@ with something else.";
    regex reg2("@@@.*?@@@");
    test = regex_replace(test, reg2, "wild statement");
    cout << test << endl;
}
